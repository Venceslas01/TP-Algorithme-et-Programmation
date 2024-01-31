#include<stdio.h>
#include<stdlib.h>
#include"arbre.h"

int facteurEquilibre(noeud* noeud) {
    if (noeud == NULL) {
        return 0;
    }
    int hauteurGauche = hauteurArbre(noeud->gauche);
    int hauteurDroite = hauteurArbre(noeud->droite);
    return hauteurGauche - hauteurDroite;
}
// Rotation gauche pour rééquilibrer l'arbre
noeud* rotationGauche(noeud* racine) {
    noeud* nouvelleRacine = racine->droite;
    racine->droite = nouvelleRacine->gauche;
    nouvelleRacine->gauche = racine;
    return nouvelleRacine;
}
// Rotation droite pour rééquilibrer l'arbre
noeud* rotationDroite(noeud* racine) {
    noeud* nouvelleRacine = racine->gauche;
    racine->gauche = nouvelleRacine->droite;
    nouvelleRacine->droite = racine;
    return nouvelleRacine;
}
// Insertion dans un arbre AVL
noeud* insererAVL(noeud* racine, int valeur) {
    int equilibre = 0;
   // Si la racine est vide, on crée un nouveau noeud
    if (racine == NULL) return creernouveauNoeud(valeur);
    // Insertion dans le sous-arbre gauche
    if (valeur < racine->donnee) {
        racine->gauche = insererAVL(racine->gauche, valeur);
        
    } else if (valeur > racine->donnee) {  // Insertion dans le sous-arbre droit
        racine->droite = insererAVL(racine->droite, valeur);
    } else {
        // La valeur est déjà présente, on ne fait rien
        return racine; 
    }

    // équilibrage de l'arbre
     equilibre = facteurEquilibre(racine);
    if (equilibre > 1 && valeur < racine->gauche->donnee) {
        return rotationDroite(racine);
    }
    if (equilibre < -1 && valeur > racine->droite->donnee) {
        return rotationGauche(racine);
    }
    if (equilibre > 1 && valeur > racine->gauche->donnee) {
        racine->gauche = rotationGauche(racine->gauche);
        return rotationDroite(racine);
    }
    if (equilibre < -1 && valeur < racine->droite->donnee) {
        racine->droite = rotationDroite(racine->droite);
        return rotationGauche(racine);
    }

    return racine;
}
void insererDansAVL(arbre* mon_arbre, int valeur) {
    mon_arbre->racine = insererAVL(mon_arbre->racine, valeur);
}

// Supprime l'arbre.
void supprimer(arbre* mon_arbre) {
    supprimerNoeud(mon_arbre->racine);
    mon_arbre->racine = NULL; 
    printf("Arbre supprime\n");
}
// Trouve la feuille ayant la valeur minimum dans l'abre 
noeud* noeudValeurminimum(noeud* node) {
    noeud* current = node;
    while (current && current->gauche != NULL) {
        current = current->gauche;
    }
    return current;
}



// Supprime un noeud dans un arbre AVL
noeud* supprimerAVL(noeud* racine, int valeur) {
    int equilibre = 0;
     // Si la racine est NULL, rien à faire
    if (racine == NULL) {
        return racine;
    }

    // Recherche de la valeur à supprimer
    if (valeur < racine->donnee) {
        racine->gauche = supprimerAVL(racine->gauche, valeur);
    } else if (valeur > racine->donnee) {
        racine->droite = supprimerAVL(racine->droite, valeur);
    } else {
        // le noeud à supprimer est trouver
        if ((racine->gauche == NULL) || (racine->droite == NULL)) {
            // Il a un ou aucun enfant
            noeud* temp = racine->gauche ? racine->gauche : racine->droite;
            // S'il n'a aucun enfant, on le supprime simplement
            if (temp == NULL) {
                temp = racine;
                racine = NULL;
            } else {
                // Si il a un enfant, on le remplace  par son enfant
                *racine = *temp; 
            }
            free(temp);
        } else {
            // Le noeud a deux enfants
            noeud* temp = noeudValeurminimum(racine->droite);
            racine->donnee = temp->donnee;
            racine->droite = supprimerAVL(racine->droite, temp->donnee);
        }
    }

    // Si l'arbre n'a que la racine, il devient vide
    if (racine == NULL) {
      return racine;
    }
    // équilibrage de l'arbre après la suppression pour maintenir la structure des arbres AVl
    equilibre = facteurEquilibre(racine);
    if (equilibre > 1 && facteurEquilibre(racine->gauche) >= 0) {
        return rotationDroite(racine);
    }
    if (equilibre > 1 && facteurEquilibre(racine->gauche) < 0) {
        racine->gauche = rotationGauche(racine->gauche);
        return rotationDroite(racine);
    }
    if (equilibre < -1 && facteurEquilibre(racine->droite) <= 0) {
        return rotationGauche(racine);
    }
    if (equilibre < -1 && facteurEquilibre(racine->droite) > 0) {
        racine->droite = rotationDroite(racine->droite);
        return rotationGauche(racine);
    }

    return racine;
}