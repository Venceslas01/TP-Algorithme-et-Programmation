#include<stdio.h>
#include<stdlib.h>
#include"Tri.h"

int main(){

    int taille_de_tableau = 0;
    printf("Indiquer la taille du tableau :  \n");
    scanf("%d", &taille_de_tableau);
    int* tab = malloc(taille_de_tableau * sizeof(int));
    Tri_choisie(tab,taille_de_tableau);
    return 0;

}