#include<stdio.h>
#include<stdlib.h>
#include"arbre.h"



noeudfile* creernouveauNoeudfile(noeud* adress) {
    noeudfile* nouveauNoeudfile = (noeudfile*)malloc(sizeof(noeudfile));
    if (nouveauNoeudfile == NULL) {
        printf("Erreur : Impossible d'allouer de la m�moire pour la noeud.\n");
        exit(1); 
    }
    nouveauNoeudfile->adress = adress;
    nouveauNoeudfile->suivante = NULL;
    return nouveauNoeudfile;
}
// Ajoute un noeud au début de la file
void ajouterEnracinefile(file* file, noeud* adress) {
    noeudfile* nouveauNoeudfile = creernouveauNoeudfile(adress);
    nouveauNoeudfile->suivante = file->racine_file;
    file->racine_file = nouveauNoeudfile;
}
// Ajoute un noeud à la fin de la file
void enfilement(file *mafile, noeud* adress){
    noeudfile*courant = mafile->racine_file;
    noeudfile*precedent = NULL;
    if ( mafile->racine_file == NULL){
        ajouterEnracinefile(mafile, adress);
    }
    else {
        while(courant != NULL){
        precedent = courant;
        courant = courant -> suivante;
        }
        noeudfile* nouveauNoeudfile = creernouveauNoeudfile(adress);
        precedent->suivante = nouveauNoeudfile;
        nouveauNoeudfile->suivante = NULL;
    }
}
// Retire et renvoie le premier noeud (tete) de la file.
noeud* defilement (file *mafile){
    noeudfile* courant = mafile ->racine_file;
    noeudfile*precedent = NULL;
    noeud*tampon = NULL;
    if (courant != NULL){
        precedent = courant;
        tampon = courant->adress;
        courant = courant -> suivante;
        precedent->suivante = NULL;
        precedent->adress = NULL;
        free(precedent);
        mafile->racine_file = courant;
        return tampon;
    }
    else {
        return NULL;
    }

}
