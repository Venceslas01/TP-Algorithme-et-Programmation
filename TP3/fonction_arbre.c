#include<stdio.h>
#include<stdlib.h>
#include"arbre.h"


// Crée un nouveau noeud pour l'arbre avec la valeur donnée
noeud* creernouveauNoeud(int valeur) {
    // Alloue de la mémoire pour le nouveau noeud
    noeud* nouveauNoeud = (noeud*)malloc(sizeof(noeud));
    if (nouveauNoeud == NULL) {
        printf("Erreur : Impossible d'allouer de la memoire pour la noeud.\n");
        exit(1); 
    }
    // Initialise le noeud
    nouveauNoeud->donnee = valeur;
    nouveauNoeud->gauche = NULL;
    nouveauNoeud->droite = NULL;

    return nouveauNoeud;
}
// Vérifie si l'arbre est vide ou non
void arbre_vide (arbre* mon_arbre){
    if ( mon_arbre->racine == NULL){
        printf(" L'arbre est vide \n");
    }
    else {
        printf("l'arbre n'est pas vide \n");
    }
}

// Parcours l'arbre de manière récursive
void parcoursDeArbre(noeud* racine) {
    if (racine != NULL) {
        parcoursDeArbre(racine->gauche);
        printf("%d ", racine->donnee);
        parcoursDeArbre(racine->droite);
    }
}
// Affiche les données de l'arbre
void afficherArbre(arbre* mon_arbre) {
    parcoursDeArbre(mon_arbre->racine);
    printf("\n");
}
// Initialise l'arbre en mettant sa racine à NULL
void initialiserArbre(arbre* mon_arbre) {
    mon_arbre->racine = NULL;
}
// Calcule la hauteur de l'arbre
int hauteurArbre(noeud* racine) {
    // Si l'arbre est vide, la hauteur est -1
    if (racine == NULL) {
        return -1;
    } else {
        // Calcul et retourne la hauteur maximale entre la gauche et la droite
        int hauteurGauche = hauteurArbre(racine->gauche);
        int hauteurDroite = hauteurArbre(racine->droite);

        if (hauteurGauche > hauteurDroite) {
            return hauteurGauche + 1;
        } else {
            return hauteurDroite + 1;
        }
    }
}

void hauteur_arbre(arbre* mon_arbre){
    int hauteur = hauteurArbre(mon_arbre->racine);
    printf("La hauteur de l'arbre est : %d\n", hauteur);
}

// Supprime un noeud et tous ses enfants de manière récursive
void supprimerNoeud(noeud* racine) {
    if (racine == NULL) return;

    supprimerNoeud(racine->gauche);
    supprimerNoeud(racine->droite);
    free(racine);
}

// Supprime l'ensemble de l'arbre
void supprimerArbre(arbre* mon_arbre) {
    supprimerNoeud(mon_arbre->racine);
    mon_arbre->racine = NULL; 
    printf("Arbre supprime\n");
}


