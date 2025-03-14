#include "lin-algebra.h"

//-------------------------------------------
Dmatrix GetA() {
}
Dvector Getb(const int &siz)
// gets the vector b from the user and returns it
{
}

void Display(const Dvector &xvect)
// displays the contents of vector xvect
{
}


void Display(const Dmatrix &Amat)
// displays the contents of matrix Amat (Note: Display function is overloaded)
{
    for (int row=0; row<Amat.size(); ++row) {
	for (int col=0; col<Amat.size(); ++col) {
	    printf("%.2f ", Amat[row][col]);
	}
	printf("\n");
    }
}


Dvector Solvex(const Dmatrix &Amat, const Dvector &bvect)
// Solves for systems of linear equations in the form Ax=b using cramer's rule 
{
}


double Det(const Dmatrix &Amat)
// returns the Determinant of matrix Amat using a recursive algorithm
// base case is 2x2 matrix 
{
    return (Amat[0][0])*(Amat[1][1]) - (Amat[0][1])*(Amat[1][0]);

}


Dmatrix Replace(Dmatrix Rmat, const int col, const Dvector &bvect)
// Replaces the column 'col' in Rmat with bvect and returns Rmat
{
    for (int i=0; i < Rmat.size(); i++) {
	Rmat[i][col] = bvect[i];
    }
    return Rmat;
}


Dmatrix Minor(const Dmatrix &Amat, const int col)
// Gets the Minor matrix of Amat by crossing out the first row and 
// column 'col' then returns that smaller matrix
{
    Dmatrix res(Amat.size() - 1);
    for (int source_row=1; source_row < Amat.size(); source_row++) {
	for (int source_col=0; source_col < Amat.size(); source_col++) {
	    if (source_col == col) {
		continue;
	    }
	    int destrow = source_row - 1;
	    res[destrow].push_back(Amat[source_row][source_col]);
	}
    }

    return res;
}
