#ifndef ALGO_PI_H
#define algo_pi_h

#include "../../HashTables/Chained/chainedhashtable.h"
#include "../../LinkedLists/LinkedList/linkedlist.h"

// Think about using a chained hash table. We'll know
// at calling time the size needed for the table. at most
typedef CHTbl DividedDifferenceTable;
typedef List Polynomial;

typedef struct NewtonPolyForm_
{
	double coeff;
	double* samples;
} NewtonPolyForm;

typedef struct StandardForm_
{
	double coeff;
} StandardForm;

int interpol(const double* x, const double* fx, int size, Polynomial** poly);
double evaluate(Polynomial* poly, double x);

#endif
