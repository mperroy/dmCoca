#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "all.h"

void writeInFile(int value, FILE * file){
  char str[10];
  sprintf(str, "%d", value); // on part du principe que si le nombre a plus de 10 décimales, il ne sera pas traité.
  fputs(str, file);
  fputc(' ', file);
}

int main(int argc, char * argv[]) {
  if(argc < 2){
    fprintf(stderr, "Nombre d'arguments insuffisant.\n");
    exit(EXIT_FAILURE);
  }
  
  //Vérification que la hauteur donnée est un entier
  if(!isdigit(argv[1][0])){
    fprintf(stderr, "Veuillez saisir un entier pour la hauteur");
    exit(EXIT_FAILURE);
  }
  
  FILE * cnfFile = NULL;
  //Hauteur donnée
  int k = atoi(argv[1]);
  int nbVar = 1; //1 car le '0' a la fin des clauses compte comme une variable
  int nbClause = 0;
  
  //Ouverture du fichier résultat (ouvert en écriture seulement)
  cnfFile = fopen("cnfFile.txt","w");
  if(cnfFile == NULL){
    fprintf(stderr, "Impossible d'ouvrir le fichier");
    exit(EXIT_FAILURE);
  }
  
  //Initialisation de la zone de commentaire du fichier résultat
  fputs("c\nc start with comments\nc\n", cnfFile);
  fputs("p cnf           \n", cnfFile);
  
  //Contrainte 1
  for(int v = 1 ; v < orderG() ; v++){
    for(int h = 0 ; h < k ; h++){
      nbVar ++;
      writeInFile(v+(h*orderG()), cnfFile);
    }
  }
  nbClause ++;
  //on termine la ligne de la clause
  fputs("0\n", cnfFile);
      
  //Contrainte 2
  for(int v = 1 ; v < orderG() ; v++){
    writeInFile(v, cnfFile);
  }

  nbClause ++;
  fputs("0\n", cnfFile);
      
  //Contrainte 3
  for(int v = 1 ; v < orderG() ; v++){
    writeInFile(v+(k * orderG()), cnfFile);
  }
      
  nbClause ++;
  fputs("0\n", cnfFile);
      
  //Contrainte 4
  for(int v = 1 ; v < orderG()-1 ; v++){
    for(int i = 1 ; i < k ; i++){
      for(int u = v ; u < orderG() ; u++){
	if(are_adjacent(u, v)){
	  // Faux v,i / vrai u,i-1
	  fputc('-', cnfFile);
	  writeInFile(v+(i * orderG()), cnfFile);
	  writeInFile(u+((i-1) * orderG()), cnfFile);
	}
      }
    }
  }
  nbClause ++;
  fputs("0\n", cnfFile);
  
  //On écrit le nombre de variables utilisées et le nombre de clauses
  //32 nombre de caractère dont on doit se déplacer
  
  fseek(cnfFile, 32, SEEK_SET);
  writeInFile(nbVar, cnfFile);
  writeInFile(nbClause, cnfFile);
  //On ferme le fichier résultat
  fclose(cnfFile);
  return 0;
}
