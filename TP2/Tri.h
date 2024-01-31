#ifndef TRI_H_INCLUDED
#define TRI_H_INCLUDED

// Déclaration des fonctions
void TestTab (int* tab, int taille_de_tableau);
void InitialisateurDeTableau (int* tab, int taille_de_tableau);
int TestTabCroissant (int* tab, int taille_de_tableau);
int TestTabDecroissant (int* tab, int taille_de_tableau);
void AfficherTableau (int* tab, int taille_de_tableau);
void TriABulle (int* tab, int taille_de_tableau);
void TriABulleboustrophedon (int* tab, int taille_de_tableau);
void Triparselection (int* tab, int taille_de_tableau);
void Triparinsertion (int* tab, int taille_de_tableau);
void mesurerPerformanceTri(void (*fonctionTri)(int*, int), int* tab, int taille_de_tableau, const char* nomTri);
int partition(int* tab, int gauche, int droite);
void tri_rapide_exec(int* tab, int debut, int taille_tab);
void tri_rapide(int* tab, int taille);
void TriInsertion(int *tab, int taille);
void tri_rapid_ameliore_exec (int* tab, int debut, int taille_tab);
void tri_rapide_ameliore(int *tab, int taille);
void triFusion(int i, int j, int tab[], int tmp[]);
void Tri_choisie(int* tab, int taille_de_tableau);
void triFusionAmeliorer(int *tab, int taille);
void copie_de_tableau(int* tab, int* tabcopie, int taille_tab);
void PerformanceDeToutesFonctionsDeTri(int* tab, int taille_de_tableau);

#endif // TRI_H_INCLUDED
