#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include"Tri.h"

void Tri_choisie(int* tab, int taille_de_tableau){
     int choix;
    // Affiche les options de tri disponibles
    printf("\n Choisissez l'algorithme de tri:  \n");
    printf("\n 1. Tri à bulle\n 2. Tri à bulle boustrophédon \n 3. Tri par sélection\n 4. Tri par insertion\n 5. Tri rapide\n 6. Tri par fusion ameliore\n 7.tri_rapde_ameliore\n 8. Mesurer la performance de toute les fonctions de tris\n 0. Quitter\n");
    scanf("%d", &choix);
     // Initialise le tableau avec des valeurs aléatoires et l'affiche
    InitialisateurDeTableau(tab, taille_de_tableau);
    if (choix!= 8){
        AfficherTableau(tab, taille_de_tableau);
        TestTab(tab, taille_de_tableau);
    }
    // Boucle pour effectuer le tri selon le choix de l'utilisateur
    // Applique l'algorithme de tri correspondant au choix
    while (choix !=0)
    {
        switch(choix) {
        case 1:
            TriABulle(tab, taille_de_tableau);
            break;
        case 2:
            TriABulleboustrophedon(tab, taille_de_tableau);
            break;
        case 3:
            Triparselection(tab, taille_de_tableau);
            break;
        case 4:
            Triparinsertion(tab, taille_de_tableau);
            break;
        case 5:
            tri_rapide(tab,taille_de_tableau-1);
            break;
        case 6:
            triFusionAmeliorer(tab, taille_de_tableau);
            break;
        case 7:
            tri_rapide_ameliore(tab,taille_de_tableau);
            break;
        case 8:
            PerformanceDeToutesFonctionsDeTri(tab,taille_de_tableau);
            break;
        default:
            printf("Choix invalide.\n");
            break;
        }
        // Affiche le tableau après le tri et repropose les options
        if (choix!=8){
             printf("Tableau trié :\n");
            AfficherTableau(tab, taille_de_tableau);
            TestTab(tab, taille_de_tableau);
        }
        printf("\nChoisissez l'algorithme de tri:\n");
        printf("1. Tri à bulle\n 2. Tri à bulle boustrophédon\n 3. Tri par sélection\n 4. Tri par insertion\n 5. Tri rapide\n 6. Tri par fusion\n 7.tri_rapde_ameliore\n 8. Mesurer la performance de toute les fonctions de tris\n 0. Quitter\n");
        scanf("%d", &choix);
        InitialisateurDeTableau(tab, taille_de_tableau);
        if (choix!=0 && choix !=8){
            AfficherTableau(tab, taille_de_tableau);
            TestTab(tab, taille_de_tableau);
        }
    }
    
     

}

void InitialisateurDeTableau (int* tab, int taille_de_tableau){
    srand(time(NULL)); // Initialise le générateur de nombres aléatoires
    for(int i=0; i<taille_de_tableau; i++){
        tab[i] = rand()%(taille_de_tableau+100); // Remplit le tableau avec des valeurs aléatoires
    }
    srand(time(NULL));
}

int TestTabCroissant (int* tab, int taille_de_tableau){
    int n = 0;
    // Retourne 1 si le tableau n'est pas croissant
    // Retourne 0 si le tableau est croissant
    for(int i=0; i<taille_de_tableau-1; i++){
        if (tab[i]>tab[i+1]){
            n = 1;
            break;
        }
    }
    return n; 
}

int TestTabDecroissant (int* tab, int taille_de_tableau){
    int n = 0;
    // Retourne 1 si le tableau n'est pas décroissant
    // Retourne 0 si le tableau est décroissant
    for(int i=0; i<taille_de_tableau-1; i++){
        if (tab[i]<tab[i+1]){
            n = 1;
            break;
        }
    }
    return n;
}
void AfficherTableau (int* tab, int taille_de_tableau){
    for(int i=0; i<taille_de_tableau; i++){
        printf(" %d ", tab[i]); // Affiche chaque élément du tableau
    }
    printf(" \n");
}

void TestTab (int* tab, int taille_de_tableau){
    if (TestTabCroissant(tab, taille_de_tableau) == 0){
        printf("Le Tableau est croissant \n");
    }
    else if (TestTabDecroissant (tab, taille_de_tableau) == 0){
        printf(" Le tableau est decroissant \n");
    }
    else {
        printf("Le tableau n'est ni croissant, ni decroissant\n");
    }
}

void mesurerPerformanceTri(void (*fonctionTri)(int*, int), int* tab, int taille_de_tableau, const char* nomTri) {
    clock_t debut, fin;
    double temps_ecoule;
    // Copie le tableau pour ne pas affecter le tableau pour les autres tris 
    int* tabCopie = malloc(taille_de_tableau * sizeof(int));
    copie_de_tableau(tab,tabCopie,taille_de_tableau);

    // Mesurer le temps de tri
    debut = clock();
    fonctionTri(tabCopie, taille_de_tableau);
    fin = clock();

    // Calculer et afficher le temps ecoule
    temps_ecoule = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("Temps pour %s: %f secondes\n", nomTri, temps_ecoule);

    free(tabCopie); // Libère la mémoire allouée pour la copie
}

void copie_de_tableau(int* tab, int* tabcopie, int taille_tab){
    for (int i=0;i<taille_tab; i++){
        tabcopie[i]= tab [i]; // copie du tableau originale
    }
}

void PerformanceDeToutesFonctionsDeTri(int* tab, int taille_de_tableau) {
    // Crée une copie du tableau pour ne pas modifier l'original lors des tests
    int* tabCopie = malloc(taille_de_tableau * sizeof(int));
    if (tabCopie == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        return;
    }

    // Teste chaque algorithme de tri et mesure sa performance
    printf("Test des performances des algorithmes de tri:\n");

    copie_de_tableau(tab,tabCopie,taille_de_tableau);
    mesurerPerformanceTri(TriABulle, tabCopie, taille_de_tableau, "Tri à Bulle");

    copie_de_tableau(tab,tabCopie,taille_de_tableau);
    mesurerPerformanceTri(TriABulleboustrophedon, tabCopie, taille_de_tableau, "Tri à Bulle Boustrophédon");

    copie_de_tableau(tab,tabCopie,taille_de_tableau);
    mesurerPerformanceTri(Triparselection, tabCopie, taille_de_tableau, "Tri par Sélection");

    copie_de_tableau(tab,tabCopie,taille_de_tableau);
    mesurerPerformanceTri(Triparinsertion, tabCopie, taille_de_tableau, "Tri par Insertion");

    copie_de_tableau(tab,tabCopie,taille_de_tableau);
    mesurerPerformanceTri(tri_rapide, tabCopie, taille_de_tableau, "Tri Rapide");

    copie_de_tableau(tab,tabCopie,taille_de_tableau);
    mesurerPerformanceTri(triFusionAmeliorer, tabCopie, taille_de_tableau, "Tri Fusion Amélioré");

    copie_de_tableau(tab,tabCopie,taille_de_tableau);
    mesurerPerformanceTri(tri_rapide_ameliore, tabCopie, taille_de_tableau, "Tri Rapide Amélioré");

    // Libère la mémoire allouée pour la copie
    free(tabCopie);
}
