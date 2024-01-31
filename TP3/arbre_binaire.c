#include<stdio.h>
#include<stdlib.h>
#include"arbre.h"
#include<time.h>


noeud* ajout_donne_binaire_s(noeud* racine, int valeur) {
    int direction = 0; 
    if (racine == NULL) {
        return creernouveauNoeud(valeur);
    }

    // Génère un nombre aléatoire pour décider où insérer le nouveau noeud (gouche ou droite)
    direction = rand() % 2;
    if (direction == 0) {
        if (racine->gauche == NULL) {
            racine->gauche = creernouveauNoeud(valeur);
        } else {
            ajout_donne_binaire_s(racine->gauche, valeur);
        }
    } else {
        if (racine->droite == NULL) {
            racine->droite = creernouveauNoeud(valeur);
        } else {
            ajout_donne_binaire_s(racine->droite, valeur);
        }
    }

    return racine;
}


void insererDansArbreBinaires(arbre* mon_arbre, int valeur) {
    
    mon_arbre->racine = ajout_donne_binaire_s(mon_arbre->racine, valeur);
}
// recherche une valeur dans l'arbre en utilisant DFS
int recherche_DFS(noeud* racine, int valeur) {
    if (racine == NULL) {
        return 0;
    }
    // Si la valeur est trouvée, renvoie 1
    if (racine->donnee == valeur) {
        return 1;
    }
    // Continue la recherche dans le sous-arbre gauche et droit
    if (recherche_DFS(racine->gauche, valeur) || recherche_DFS(racine->droite, valeur)) {
        return 1;
    }

   return 0;
}

void DFS(arbre* mon_arbre,int valeur){
    if (recherche_DFS(mon_arbre->racine, valeur) == 1){
        printf("Valeur %d trouvée dans l'arbre (DFS)\n", valeur);
    }
    else if (recherche_DFS(mon_arbre->racine, valeur) == 0){
        printf("Valeur %d n'est pas trouvée dans l'arbre (DFS)\n", valeur);
    }
}
//  recherche une valeur dans l'arbre en utilisant BFS
int BFS_recherche (noeud* racine, int valeur, file* mafile) {
    if (racine == NULL) {
        return 0;
    }
     // Ajoute le noeud racine dans la file
    enfilement(mafile, racine);
    while (mafile->racine_file != NULL) {
        noeud* temp = defilement(mafile);
        if (temp->donnee == valeur) {
            return 1;
        }
        // Ajoute les enfants du noeud dans la file
        if (temp->gauche != NULL) {
            enfilement(mafile, temp->gauche);
        }
        if (temp->droite != NULL) {
            enfilement(mafile, temp->droite);
        }
    }
    return 0;
}

void BFS(arbre* mon_arbre,int valeur){
    file mafile;
    mafile.racine_file = NULL;
    if (BFS_recherche(mon_arbre->racine, valeur, &mafile) == 1){
        printf("Valeur %d trouvée dans l'arbre (BFS)\n", valeur);
    }
    else if (BFS_recherche(mon_arbre->racine, valeur, &mafile) == 0){
        printf("Valeur %d n'est pas trouvée dans l'arbre (BFS)\n", valeur);
    }
}
void profondeurNoeud(arbre* mon_arbre,int valeur){
    int niveau = 0;
    printf("Le niveau de %d est %d\n", valeur, profondeurNoeud_calcul(mon_arbre->racine,valeur,niveau));

}
// calcule la profondeur d'un noeud donné dans l'arbre
int profondeurNoeud_calcul(noeud* racine, int valeur,int niveau) {
    
    if (racine == NULL) 
        return -1;
    // Si la valeur est trouvée, renvoie le niveau actuel
    if (racine->donnee == valeur)
        return niveau;
    // Continue la recherche dans les sous-arbres gauche et droit
    int niveauGauche = profondeurNoeud_calcul(racine->gauche, valeur, niveau + 1);
    if (niveauGauche != -1)
        return niveauGauche;

    int niveauDroit = profondeurNoeud_calcul(racine->droite, valeur, niveau + 1);
        return niveauDroit;
}
