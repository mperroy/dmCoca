
// include biblio pour manipuler file

int main(int argc, char * argv[]){
  // check pour k bien reçu
  // ouverture + écriture fichier cnf retour

  int k = atoi(args[1]); // vérif si bien entier
  int nbVar = 0;
  int nbClause = 0;

  // Matrice contenant toutes les variables de nos clauses
  int matVar[orderG()][k]; // passer tout ça à 0

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
  
  return 0;
}
