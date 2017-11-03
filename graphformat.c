#include "graphformat.h"

//Initialisation de la matrice des variables
int[][] initMatrix(int nbSommet, int hauteur) {
  //Vraiment des int les variables de la matrice ? Valeur ?
  //Terminologie des variables à mettre dans le fichier résultat
  int matrix[nbSommet][hauteur];
  for(int i = 0; i < nbSommet; i++) {
	for(int j = 0; j < hauteur; j++)
	  matrix[i][j] = 0;
      }
  return matrix;
}

int main(int argc, char * argv[]) {

  FILE * cnfFile = NULL;
  //Hauteur donnée
  int k = atoi(args[1]);
  int nbVar = 1; //1 car le '0' a la fin des clauses compte comme une variable
  int nbClause = 0;
  // Matrice contenant toutes les variables de nos clauses
  int matVar[orderG()][k]; 

  //Vérification que la hauteur donnée est un entier
  if(isdigit(k) == 0)
    printf("Veuillez saisir un entier pour la hauteur");
  else {
    //Ouverture du fichier résultat (ouvert en écriture seulement)
    cnfFile = fopen("cnfFile.txt","w");
    if(cnfFile == NULL)
      printf("Impossible d'ouvrir le fichier");
    else {
      //Initialisation des valeurs de la matrice
      matVar = initMatrix(orderG(), k, matVar);
      
      //Initialisation de la zone de commentaire du fichier résultat
      fputs("c\nc start with comments\nc\n", cnfFile);
      fputs("p cnf \n", cnfFile);

      //Contrainte 1
      for(int v = 0 ; v < orderG() ; v++){
	for(int h = 0 ; h < k ; h++){
	  matVar[v][h] = 1;
	  nbVar ++;
	  puts((v+(h * orderG()))" ", cnfFile);
	}
      }
      nbClause ++;
      //on réinitialise la matrice avant chaque autre contrainte
      matVar = initMatrix(orderG(), k, matVar);
      //on termine la ligne de la clause
      puts("0\n", cnfFile);
      
      //Contrainte 2
      for(int v = 0 ; v < orderG() ; v++){
	matVar[v][0] = 1;
	puts(v" ", cnfFile);
      }
      nbClause ++;
      matVar = initMatrix(orderG(), k, matVar);
      puts("0\n", cnfFile);
      
      //Contrainte 3
      for(int v = 0 ; v < orderG() ; v++){
	matVar[v][k] = 1;
	puts((v+(k * orderG()))" ",cnfFile);
      }
      nbClause ++;
      matVar = initMatrix(orderG(), k, matVar);
      puts("0\n", cnfFile);
      
      //Contrainte 4
      for(int v = 0 ; v < orderG() ; v++){
	for(int i = 1 ; i < k ; i++){
	  for(int u = 0 ; u < orderG() ; u++){
	    if(are_adjacent(u, v){
		//faux v,i vrai u,i-1
		matVar[v][i] = 1;
		matVar[u][i-1] = 1;
		puts("-"(v+(i * orderG()))" "(u+(i-1 * orderG()))" ", cnfFile);
	    }
	  }
	}
      }
     nbClause ++;
     puts("0", cnfFile);
     }
   }
  //On écrit le nombre de variables utilisées et le nombre de clauses
  //34 nombre de caractère dont on doit se déplacer
  fseek(cnfFile, 34, SEEK_SET);
  puts(nbVar " " nbClause, cnfFile);
  //On ferme le fichier résultat
  fclose(cnfFile);
  return 0;
}
