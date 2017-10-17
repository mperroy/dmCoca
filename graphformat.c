#include "graphformat.h"
// include biblio pour manipuler file

clause createClause(){
  clause cnf = malloc(sizeof(clause));
  cnf->varList = malloc(sizeof(intList*));
  cnf->nbVar = 0;
  cnf->next = NULL;
  return cnf;
}

void addClause(clause * cnf){
  while(cnf->next != NULL){
    cnf = cnf->next;
  }
  cnf->next = createClause();
}

void freeClause(clause * cnf){
  if(cnf->next != NULL)
    freeClause(cnf->next);
  freeVarList(cnf->varList);
  free(cnf);
}

void addVar(clause * cnf, int var){
  cnf->nbVar++;
  intList * tmp = cnf->varList;
  while(tmp->next != NULL){
    tmp = tmp->next;
  }
  tmp->next = malloc(sizeof(intList*));
  tmp->next->var = var;
}

void freeVarList(intList * varList){
  if(varList->next != NULL)
    freeVarList(varList->next);
  free(varList);
}

void uniqueIntPerVertice(clause * cnf){
}

void uniqueRoot(clause * cnf){
}

void atLeastOneVerticeAtK(clause * cnf, int k){
}

void potentialParent(clause * cnf){
}

int main(int argc, char ** args){
  // check pour k bien reçu
  // ouverture + écriture fichier cnf retour
  return 0;
}
