#include "PolyInterpolation.h"

int hash_one(double* x) { }
int hash_two(double* x) { }
int match_coeff(){}

// Produce the divided difference table given observation and populate 
// a Newton Polynomial with the appropriate coefficents.

double divided_difference(const double* x, const double* fx, int size, DivDiffTable* ddt)
{
	int retval = ddt_lookup(ddt, (void**)&x);
	if (retval == 0) { return x; }	

	double num = divided_difference(x, fx, size-1, ddt) +
	       	     divided_difference(x+1, fx+1, size-1, ddt)
	double dem = x[size] - x[0]

	ddt_insert(ddt, (const void*)(num/dem));
	return num/dem;
}

int interpol
(
	const double* x, 
	const double* fx, 
	int size, 
	Polynomial* poly
)
{
	DivDiffTable ddt; ddt_init(ddt,hash_one,hash_two);
	for (int sample = 0; sample <= size; sample++)
	{
		// be careful of mutating x
		double coeff = divided_difference(x,fx,sample,ddt);
		NewtonPolyForm* term;

		if ((term = (NewtonPolyForm*)malloc(sizeof(NewtonPolyForm))) == NULL)
		{
			chtbl_destroy(ddt);
			list_destroy(poly);k
			return -1;
		}

		term->exponent = sample;
		term->coeff = coeff;
		term->samples = x;

		if (list_insert_next(poly, NULL, (const void*)term) == -1)
		{
			chtbl_destroy(ddt);
			list_destroy(poly);k
			return -1;
		}
	}
	return 0;
}

// Provided a polynomial struct, dispatch evaluation to the appropriate
// evaluation function.
double evaluate(Polynomial* poly, double x);
