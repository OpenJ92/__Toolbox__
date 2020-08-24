#ifndef ALGO_PI_H
#define algo_pi_h

#include "../../HashTables/Chained/chainedhashtable.h"
#include "../../LinkedLists/LinkedList/linkedlist.h"

// Think about using a chained hash table. We'll know
// at calling time the size needed for the table. at most
typedef enum Polytype
{
	NewtonPoly,
	StandardPoly,
} Polytype;

typedef struct Poly_
{
	Polytype pt;
	List* terms;
} Poly;

typedef OHTbl DivDiffTable;

typedef struct DivDiff_
{
	int id;
	double divdiff;
}

typedef struct DDNode_
{
	double divdiff; 
}

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
