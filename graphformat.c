#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "all.h"

int main(int argc, char * argv[]) {

  FILE * cnfFile = NULL;
  //Hauteur donnée
  int k = atoi(argv[1]);
  int nbVar = 1; //1 car le '0' a la fin des clauses compte comme une variable
  int nbClause = 0;

  //Vérification que la hauteur donnée est un entier
  if(isdigit(k) == 0)
    printf("Veuillez saisir un entier pour la hauteur");
  else {
    //Ouverture du fichier résultat (ouvert en écriture seulement)
    cnfFile = fopen("cnfFile.txt","w");
    if(cnfFile == NULL)
      printf("Impossible d'ouvrir le fichier");
    else {
      //Initialisation de la zone de commentaire du fichier résultat
      fputs("c\nc start with comments\nc\n", cnfFile);
      fputs("p cnf \n", cnfFile);

      //Contrainte 1
      for(int v = 0 ; v < orderG() ; v++){
	for(int h = 0 ; h < k ; h++){
	  nbVar ++;
	  fputc((v+(h * orderG())), cnfFile);
	  fputc(' ', cnfFile);
	}
      }
      nbClause ++;
      //on termine la ligne de la clause
      fputs("0\n", cnfFile);
      
      //Contrainte 2
      for(int v = 0 ; v < orderG() ; v++){
	fputc(v, cnfFile);
	fputc(' ', cnfFile);
      }

      nbClause ++;
      fputs("0\n", cnfFile);
      
      //Contrainte 3
      for(int v = 0 ; v < orderG() ; v++){
	fputc((v+(k * orderG())),cnfFile);
	fputc(' ', cnfFile);
      }
      
      nbClause ++;
      fputs("0\n", cnfFile);
      
      //Contrainte 4
      for(int v = 0 ; v < orderG() ; v++){
	for(int i = 1 ; i < k ; i++){
	  for(int u = 0 ; u < orderG() ; u++){
	    if(are_adjacent(u, v)){
		//faux v,i vrai u,i-1
		fputc('-', cnfFile);
		fputc((v+(i * orderG())), cnfFile);
		fputc(' ', cnfFile);
		fputc((u+(i-1 * orderG())), cnfFile);
		fputc(' ', cnfFile);
	      }
	  }
	}
      }
     nbClause ++;
     fputc('0', cnfFile);
     }
   }
  //On écrit le nombre de variables utilisées et le nombre de clauses
  //34 nombre de caractère dont on doit se déplacer
  fseek(cnfFile, 34, SEEK_SET);
  fputc(nbVar, cnfFile);
  fputc(' ', cnfFile);
  fputc(nbClause, cnfFile);
  //On ferme le fichier résultat
  fclose(cnfFile);
  return 0;
}
