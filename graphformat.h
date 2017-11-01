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
