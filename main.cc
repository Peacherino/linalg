#include "lin-algebra.h"

int main() {

  Dmatrix A;
  Dvector b, x;

  A = GetA();
  Display(A);
  b = Getb(A.size());
  x = Solvex(A, b);
  cout << "the result is: ";
  Display(x);

  return (0);
}
