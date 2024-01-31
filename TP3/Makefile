execavl: main.o arbre_binaire_de_recherche.o arbre_binaire.o file_arbre.o fonction_arbre.o AVL.o
	gcc -o execavl main.o arbre_binaire_de_recherche.o arbre_binaire.o file_arbre.o fonction_arbre.o AVL.o

main.o: main.c arbre.h
	gcc -c main.c

arbre_binaire_de_recherche.o: arbre_binaire_de_recherche.c arbre.h
	gcc -c arbre_binaire_de_recherche.c

arbre_binaire.o: arbre_binaire.c arbre.h
	gcc -c arbre_binaire.c

file_arbre.o: file_arbre.c arbre.h
	gcc -c file_arbre.c

fonction_arbre.o: fonction_arbre.c arbre.h
	gcc -c fonction_arbre.c

AVL.o: AVL.c arbre.h
	gcc -c AVL.c

delete:
	rm -rf *.o