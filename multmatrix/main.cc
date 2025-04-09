#include "lin-algebra.h"

int main(){

	Dmatrix A;     
	Dvector b,x;

	A=GetA();
	A2 = GetA();
	Display(A);
	Display(A);
	b=Getb(A.size());
	x=Solvex(A,b);
	cout << "the result is: ";
	Display(x);

	return(0);
}
