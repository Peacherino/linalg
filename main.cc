#include "lin-algebra.h"

int main(){

	Dmatrix A;     
	Dvector b,x;

	A=GetA();
	Display(A);
	b=Getb(A.size());
	x=Solvex(A,b);
	Display(x);

	return(0);
}
