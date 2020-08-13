#ifndef ALGO_PI_H
#define algo_pi_h

#include "../../HashTables/Chained/chainedhashtable.h"
#include "../../LinkedLists/LinkedList/linkedlist.h"

// Think about using a chained hash table. We'll know
// at calling time the size needed for the table. at most
typedef OHTbl DivDiffTable;
typedef List Polynomial;

typedef struct NewtonPolyForm_
{
	int exponent;
	double coeff;
	double* samples;
} NewtonPolyForm;

typedef struct StandardForm_
{
	int exponent;
	double coeff;
} StandardForm;

int interpol(const double* x, const double* fx, int size, Polynomial* poly);
double evaluate(Polynomial* poly, double x);

#define ddt_init ohtbl_init
#define ddt_insert ohtbl_insert
#define ddt_lookup ohtbl_lookup

#endif
