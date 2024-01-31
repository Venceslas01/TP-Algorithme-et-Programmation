#include<stdio.h>
#include<stdlib.h>
#include"arbre.h"

// Fonction pour ajouter une valeur dans l'arbre binaire de recherche
noeud* ajout_donne(noeud* racine, int valeur) {
    if (racine == NULL){
        // Si l'endroit est vide, crée un nouveau noeud avec la valeur
        return creernouveauNoeud(valeur);
    }
    // Si la valeur est plus petite, va à gauche, sinon va à droite
    if (valeur<racine->donnee){

        racine->gauche = ajout_donne(racine->gauche,valeur);

    }else if (valeur>racine->donnee)
    {
        racine->droite = ajout_donne(racine->droite,valeur);
    }
    return racine;
}
void insererDansArbre(arbre* mon_arbre, int valeur) {
    mon_arbre->racine = ajout_donne(mon_arbre->racine, valeur);
}
// Fonction pour chercher une valeur dans l'arbre binaire de recherche
int recherche_valeur(noeud* racine, int valeur){
     // Si la racine est vide, retourne 0
    if (racine == NULL) {
        return 0;
    }
    // Si la valeur est trouvée, retourne 1
    if (valeur == racine->donnee){
        return 1;
    }
    // Compare la valeur et décide de chercher à gauche ou à droite
    if (valeur < racine->donnee){
        return recherche_valeur(racine->gauche, valeur); 
    } else {
        return recherche_valeur(racine->droite, valeur); 
    }
}

void Recherche_Abre_Binaire_De_Recherche(arbre* mon_arbre,int valeur){
    if (recherche_valeur(mon_arbre->racine, valeur) == 1){
        printf("Valeur %d trouvée dans l'arbre (Recherche valeur arbre binaire de recherche)\n", valeur);
    }
    else if (recherche_valeur(mon_arbre->racine, valeur) == 0){
        printf("Valeur %d n'est pas trouvée dans l'arbre (Recherche valeur arbre binaire de recherche)\n", valeur);
    }
}

void supprimerElement(arbre* mon_arbre, int valeur) {
    supprimerNoeudBR(mon_arbre->racine, valeur);
    printf ("Noeud supprimer avec succès\n");
}
// Fonction pour supprimer un noeud dans l'arbre
noeud* supprimerNoeudBR(noeud* racine, int valeur) {
    // Si la racine est vide, rien à faire
    if (racine == NULL) {
        return NULL;
    }
    // Cherche la valeur à supprimer en allant à gauche ou à droite
    if (valeur < racine->donnee) {
        racine->gauche = supprimerNoeudBR(racine->gauche, valeur);
    } else if (valeur > racine->donnee) {
        racine->droite = supprimerNoeudBR(racine->droite, valeur);
    } else {
        // Trouve le noeud à supprimer
        if (racine->gauche == NULL) {
            noeud* temp = racine->droite;
            free(racine);
            return temp;
        } else if (racine->droite == NULL) {
            noeud* temp = racine->gauche;
            free(racine);
            return temp;
        }

        noeud* temp = noeudValeurminimum(racine->droite);
        racine->donnee = temp->donnee;
        racine->droite = supprimerNoeudBR(racine->droite, temp->donnee);
    }
    return racine;
}
