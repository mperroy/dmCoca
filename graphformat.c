#include "graphformat.h"
// include biblio pour manipuler file

clause createClause(){
  clause cnf = malloc(sizeof(clause));
  cnf->varList = createVarList();
  cnf->nbVar = 0;
  cnf->next = NULL;
  return cnf;
}

void addClause(clause * cnf){
  while(cnf->next != NULL){
    cnf = cnf->next;
  }
  cnf = createClause();
  cnf->varList = malloc(sizeof(intList*));
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

clause uniqueIntPerVertice(){
  
  return NULL;
}

clause uniqueRoot(){
  return NULL;
}

clause atLeastOneVerticeAtK(int k){
  return NULL;
}

clause potentialParent(){
  return NULL;
}

int main(int argc, char ** args){
  // check pour k bien reçu
  // ouverture + écriture fichier cnf retour
  return 0;
}
