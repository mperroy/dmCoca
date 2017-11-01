#include "graphformat.h"

int main(int argc, char * argv[]) {

  FILE * cnfFile = NULL;
  //Hauteur donnée
  int k = atoi(args[1]);
  int nbVar = 0;
  int nbClause = 0;
  // Matrice contenant toutes les variables de nos clauses
  int matVar[orderG()][k]; 

  //Vérification que la hauteur donnée est un entier
  if(isdigit(k) == 0)
    printf("Veuillez saisir un entier pour la hauteur");

  //Ouverture du fichier résultat (ouvert en écriture seulement)
  cnfFile = fopen("cnfFile.txt","w");
  if(cnfFile == NULL)
    printf("Impossible d'ouvrir le fichier");
  
  //Initialisation de la matrice des variables
  //Vraiment des int les variables de la matrice ? Valeur ?
  //Terminologie des variables à mettre dans le fichier résultat
  for(int i = 0; i < orderG(); i++) {
    for(int j = 0; j < k; j++)
     matVar[i][j] = 0;
  }

  // Contrainte 1
  for(int v = 0 ; v < orderG() ; v++){
    for(int h = 0 ; h < k ; h++){
      matVar[v][h] = 1; // on les écrit dans le fichier ?
    }
  }

  // Contrainte 2
  for(int v = 0 ; v < orderG() ; v++){
    matVar[v][0] = 1; // idem
  }

  // Contrainte 3
  for(int v = 0 ; v < orderG() ; v++){
    matVar[v][k] = 1; // idem
  }

  // Contrainte 4
  for(int v = 0 ; v < orderG() ; v++){
    for(int i = 1 ; i < k ; i++){
      for(int u = 0 ; u < orderG() ; u++){
	if(are_adjacent(u, v){
	    // faux v,i vrai u,i-1
	  }
      }
    }
  }
  //On ferme le fichier résultat
  fclose(cnfFile);
  return 0;
}
