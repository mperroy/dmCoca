#include <stdio.h>
#include <stdlib.h>
#include "all.h"

struct clause{
  intList * varList;
  int nbVar;
  clause* next;
};

struct intList{
  int var;
  intList* next;
};

clause createClause();

void addClause(clause * cnf);

void freeClause(clause * cnf);

void addVar(clause * cnf, int var);

void freeVarList(intList * varList);

clause uniqueIntPerVertice();

clause uniqueRoot();

clause atLeastOneVerticeAtK( int k);

clause potentialParent();
