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

void uniqueIntPerVertice(clause * cnf);

void uniqueRoot(clause * cnf);

void atLeastOneVerticeAtK(clause * cnf, int k);

void potentialParent(clause * cnf);
