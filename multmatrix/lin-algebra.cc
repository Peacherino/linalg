#include "lin-algebra.h"

//-------------------------------------------
Dmatrix GetA() {
    int rows, cols;
    cin >> rows >> cols;

    Dmatrix A(rows, Dvector(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; ++j)
            cin >> A[i][j];
    return A;
}
Dvector Getb(const int &siz)
// gets the vector b from the user and returns it
{
    Dvector b(siz);
    for (int i = 0; i < siz; i++)
        cin >> b[i];
    return b;
}

void Display(const Dvector &xvect)
// displays the contents of vector xvect
{
	for (int i=0; i<xvect.size(); ++i) {
		printf("%.2f ", xvect[i]);
	}
	printf("\n");
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

Dvector GetRow(const Dmatrix &Amat, int row)
{
    //if (row >= Amat.size()) {
	//printf("out of bounds get outta here mustard");
    }
    //return Amat[row]
}

}

Dvector GetCol(const Dmatrix &Amat, int col)
{
}

Dvector DotProduct(const Dmatrix &Amat, const Dmatrix &Amat, int row, int col)
{
}

Dvector Solvex(const Dmatrix &Amat, const Dvector &bvect)
// Solves for systems of linear equations in the form Ax=b using cramer's rule 
{
    Dvector result;
    double detA = Det(Amat);

    for (int i = 0; i < Amat.size(); i++) {
        Dmatrix Ai = Replace(Amat, i, bvect);
	double detAi = Det(Ai);
	result.push_back(detAi/ detA );
    }
    return result;
}


double Det(const Dmatrix &Amat)
// returns the Determinant of matrix Amat using a recursive algorithm
// base case is 2x2 matrix 
{
    double result = 0;
    double sign = 1;
    if (Amat.size() == 2) {
	return (Amat[0][0])*(Amat[1][1]) - (Amat[0][1])*(Amat[1][0]);
    }
    for (int i=0; i<Amat.size(); i++) {
	Dmatrix minor = Minor(Amat, i);
	result += Det(minor)*Amat[0][i]*sign;
	sign = sign*(-1);
    }
    return result;



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
