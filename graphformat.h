#include <stdio.h>
#include <stdlib.h>
#include "all.h"

struct clause{
  int * varTab;
  int nbVar;
  clause* next;
};

clause createClause();

void deleteLastClause(clause * cnf);

void addClause(clause * cnf);
