#include<stdio.h>
#include<stdlib.h>
#include"arbre.h"
#include<time.h>

int main(){
    srand((unsigned)time(NULL)); 

    arbre monArbre;
    initialiserArbre(&monArbre);

    int choix, nbElements, val;
    // Demander à l'utilisateur le type d'arbre à créer
    printf("Choisissez le type d'arbre :\n");
    printf("1. Arbre binaire \n");
    printf("2. Arbre binaire de recherche\n");
    printf("3. Arbre AVL\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    printf("Combien de nombres voulez-vous insérer dans l'arbre ? ");
    scanf("%d", &nbElements);
     // Insérer les nombres dans l'arbre selon le type choisi
    for(int i = 0; i < nbElements; i++) {
        val = rand() % (10*nbElements); // nombre aléatoire entre 0 et n*10
        if (choix == 1) {
            insererDansArbre(&monArbre, val);
        } else if (choix == 2) {
            insererDansArbreBinaires(&monArbre, val);
        }else if (choix == 3) {
            insererDansAVL(&monArbre, val);
        }
    }
    // Afficher l'arbre et vérifier s'il est vide
    arbre_vide(&monArbre);
    printf("Parcours de l'arbre binaire: \n");
    afficherArbre(&monArbre);
    hauteur_arbre(&monArbre);
    printf("Qu'elle est la valeur qure vous rechercher \n");
    scanf("%d", &val);

    if (choix == 2 || choix == 3) {
        Recherche_Abre_Binaire_De_Recherche(&monArbre, val);
    }else if (choix == 1){
        choix = 0;
        printf("Qu'elle est la fonction de recherche que vous vous voulez utiliser \n");
        printf("1. DFS \n");
        printf("2. BFS\n");
        scanf("%d", &choix);
        if (choix == 1) {
            DFS(&monArbre, val);
        } else if (choix == 2) {
            BFS(&monArbre, val);
        }
    }

    printf("Qu'elle est la valeur dont vous vous voulez la profondeur ou taper -1 pour quitter la recherche de prrofondeur \n");
    scanf("%d", &val);

    do{
        profondeurNoeud(&monArbre, val);
        printf("Qu'elle est la valeur dont vous vous voulez la profondeur ou taper -1 pour quitter la recherche de prrofondeur \n");
        scanf("%d", &val);

    }while (val != -1);

    printf("Qu'elle est le nombre que vous voulez supprimer \n");
    scanf("%d", &val);

    if (choix == 2) {
        supprimerElement(&monArbre, val);
    }else if (choix == 3){
        supprimerAVL(monArbre.racine, val);
    }
    arbre_vide(&monArbre);
    printf("Parcours de l'arbre binaire: \n");
    afficherArbre(&monArbre);
    hauteur_arbre(&monArbre);
    // Supprimer tout l'arbre et vérifier à nouveau s'il est vide
    supprimerArbre(&monArbre);
    arbre_vide(&monArbre);

    return 0;
}