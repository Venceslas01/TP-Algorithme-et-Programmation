#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include"Tri.h"

void TriABulle (int* tab, int taille_de_tableau){
    int temp = 0;
    int n = 0;

    // Parcours des élément du tableau
        for(int i = taille_de_tableau - 2; i >0; i--){ 
        // Compare et échange des éléments adjacents du tableau
        for(int j = 0; j<i+1; j++){ 
            if (tab[j] > tab [j+1]) {
                temp = tab [j];
                tab[j] = tab [j+1];
                tab[j+1] = temp;
                n = 1;
                }

            }
    }
    // Vérifie si le tableau était déjà tri
    if (n == 0){
        printf ("Le tableau est deja trie \n");
    }

}

void TriABulleboustrophedon (int* tab, int taille_de_tableau){
    int temp;
    int debut = 0;
    int fin = taille_de_tableau - 1;
    int echange = 1;
    int j;

    while (echange) { // Continue tant que échange est vrai
        echange = 0;
        // Parcours des éléments du tableau de gauche à droite
        for (j = debut; j < fin; ++j) {
            // Compare et échange des éléments du tableau
            if (tab[j] > tab[j + 1]) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                echange = 1;
            }
        }
        fin--;
        // Parcours des éléments du tableau de droite à gauche
        for (j = fin; j > debut; --j) {
             // Compare et échange des éléments du tableau
            if (tab[j] < tab[j - 1]) {
                temp = tab[j];
                tab[j] = tab[j - 1];
                tab[j - 1] = temp;
                echange = 1;
            }
        }
        debut++;
    }
}

void Triparselection (int* tab, int taille_de_tableau){
    int tmp = 0, min_index = 0;
    // Parcours des éléments du tableau
    for (int i = 0; i < taille_de_tableau - 1; i++){
        min_index = i;
        // Identification du plus petit élément dans la partie non triée
        for (int j = i + 1; j < taille_de_tableau; j++){
            if (tab[j] < tab[min_index]){
                min_index = j;
            }
        }
        // Échange de l'élément identifié précédemment
        if (min_index != i){
            tmp = tab[i];
            tab[i] = tab[min_index];
            tab[min_index] = tmp;
        }
    }
}




void Triparinsertion (int* tab, int taille_de_tableau){
    int temp;
    // Parcours des élément du tableau
    for (int i=1; i<taille_de_tableau-1; i++){
        for (int j=i+1; j<taille_de_tableau; j++){
            // Compare l'élément courant(i)  avec chaque élément suivant (i+1)
            // Si un élément suivant est plus petit, on échange les éléments
            if (tab[i]>tab[j]){
                temp = tab [i];
                tab[i] = tab [j];
                tab [j] = temp;
                for (int y=i-1; y >=0 ; y--) {
                    if (tab[y]>tab[i]){
                        temp = tab [i];
                        tab[i] = tab [y];
                        tab [y] = temp;
                    }
                }
            }


        }

    }

}
 
int partition(int* tab, int gauche, int droite){
	int tmp = 0;
	int i = gauche+1, j = droite, pivot = tab[gauche];
    // Boucle pour partitionner le tableau autour du pivot
	while (i<=j){
        // Incrémente (i) tant que les éléments du tableau à la position i sont inférieurs ou égales au pivot et que i est inférieur ou égale à j
		while (tab[i] <= pivot && i <= droite){
			i += 1;
		}
        // décrémente (j) tant que les éléments du tableau à la position j sont strictement supếrieur au pivot 
		while (tab[j] > pivot){
			j -= 1;
		}
        // Échange les éléments aux indices (i) et (j)
		if (i<j){
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
			i += 1;
			j -= 1;
		}
	}
    // Place le pivot à sa position finale
	tmp = tab[gauche];
	tab[gauche] = tab [j];
	tab [j] = tmp;
  	return j;  // Retourne la position du pivot

}
void tri_rapide(int* tab, int taille){
    int debut = 0;
    tri_rapide_exec(tab, debut, taille);
}
void tri_rapide_exec(int* tab, int debut, int taille_tab)
{
	int j = 0;
 	if (debut<taille_tab){
 		j = partition(tab,debut,taille_tab); // Partitionne le tableau
		tri_rapide_exec(tab,debut,j-1); // Tri rapide sur la partie de gauche du tableau partitionné
		tri_rapide_exec(tab,j+1,taille_tab); // Tri rapide sur la partie de droite du tableau partinnionné
 	}
	
}
void tri_rapide_ameliore(int *tab, int taille){
    int debut = 0;
    tri_rapid_ameliore_exec(tab, debut, taille);
}

void tri_rapid_ameliore_exec (int* tab, int debut, int taille_tab){
	int j = 0;
 	if (debut<taille_tab){
         // Utilise le tri par insertion pour les tableaux de petites tailles
 		if (taille_tab - debut < 15){
 			Triparinsertion(tab + debut, taille_tab - debut+1);
 		}
 		else{
            // Sinon, continue avec le tri rapide 
 		     j = partition(tab,debut,taille_tab);
 		     tri_rapid_ameliore_exec(tab, debut, j-1);
 		     tri_rapid_ameliore_exec(tab, j+1, taille_tab);
 		}
 	}
}

void triFusion(int i, int j, int tab[], int tmp[]) {
    // tableau d'un seul élément
    if(j <= i){ 
        return; 
    }
  
    int m = (i + j) / 2; // Calcul du  point médian
    
    // Tri fusion sur les deux moitiés
    triFusion(i, m, tab, tmp);     
    triFusion(m + 1, j, tab, tmp); 

    int pg = i;   // Pointeur gauche  
    int pd = m + 1; // Pointeur droit
    int c;          // Compteur pour le tableau temporaire

    // Fusionne les deux moitiés triées
    for(c = i; c <= j; c++) {
        if(pg == m + 1) { 
            tmp[c] = tab[pd];
            pd++;
        }else if (pd == j + 1) { 
            tmp[c] = tab[pg];
            pg++;
        }else if (tab[pg] < tab[pd]) { 
            tmp[c] = tab[pg];
            pg++;
        }else {  
            tmp[c] = tab[pd];
            pd++;
        }
    }
    // Copie les éléments fusionnés et triés dans le tableau original
    for(c = i; c <= j; c++) {  
        tab[c] = tmp[c];
    }
}

void triFusionAmeliorer(int *tab, int taille){
    srand((unsigned)time(NULL));
    int i = rand()%taille;
    int j = taille-1;
    int* tmp = malloc(taille * sizeof(int)); // Alloue un tableau temporaire
    triFusion(i,j,tab,tmp); // Appelle la fonction de tri fusion
    free(tmp);  // Libère la mémoire allouée pour le tableau temporaire
}