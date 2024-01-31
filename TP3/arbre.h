#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

typedef struct noeud {
            int donnee;
            struct noeud* gauche;
            struct noeud* droite;
} noeud;
typedef struct noeudfile {
    noeud* adress;
    struct noeudfile* suivante;
} noeudfile;

typedef struct arbre {
        noeud* racine; 
 }arbre;
typedef struct file {
    noeudfile* racine_file; 
} file;

noeud* creernouveauNoeud(int valeur);
void arbre_vide (arbre* mon_arbre);
noeud* ajout_donne(noeud* racine, int valeur);
void insererDansArbre(arbre* mon_arbre, int valeur);
void parcoursDeArbre(noeud* racine);
void afficherArbre(arbre* mon_arbre) ;
void initialiserArbre(arbre* mon_arbre);
int hauteurArbre(noeud* racine);
void hauteur_arbre(arbre* mon_arbre);
int recherche_DFS(noeud* racine, int valeur);
void DFS(arbre* mon_arbre,int valeur);
noeudfile* creernouveauNoeudfile(noeud* adress);
void ajouterEnracinefile(file* file, noeud* adress);
void enfilement(file *mafile, noeud* adress);
noeud* defilement (file *mafile);
void BFS(arbre* mon_arbre,int valeur);
int BFS_recherche (noeud* racine, int valeur, file* mafile);
void profondeurNoeud(arbre* mon_arbre,int valeur);
int profondeurNoeud_calcul(noeud* racine, int valeur,int niveau) ;
void supprimerNoeud(noeud* racine);
void supprimerArbre(arbre* mon_arbre);
noeud* ajout_donne_binaire_s(noeud* racine, int valeur);
void insererDansArbreBinaires(arbre* mon_arbre, int valeur) ;
void Recherche_Abre_Binaire_De_Recherche(arbre* mon_arbre,int valeur);
int recherche_valeur(noeud* racine, int valeur);
int facteurEquilibre(noeud* noeud);
noeud* rotationGauche(noeud* racine);
noeud* rotationDroite(noeud* racine);
noeud* insererAVL(noeud* racine, int valeur);
void insererDansAVL(arbre* mon_arbre, int valeur);
noeud* noeudValeurminimum(noeud* node);
noeud* supprimerAVL(noeud* racine, int valeur);
void supprimerElement(arbre* mon_arbre, int valeur);
noeud* supprimerNoeudBR(noeud* racine, int valeur);
#endif // ARBRE_H_INCLUDED
