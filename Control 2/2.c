#include <math.h>
#include <stdio.h>


int main() {
  double A, B, C;
  char P;
  printf(
      "Escriba operador  (suma “+”, resta “-“, producto “*” o división “/”)  ");
  scanf("%c", &P);

  printf("Escriba su numero A ");
  scanf("%lf", &A);

  printf("Escriba su numero B ");
  scanf("%lf", &B);
  
  printf("Escriba su numero C ");
  scanf("%lf", &C);

  if (P=='+')
  {
  float total= A+B+C ;
  printf("Escriba su numero A  %.4f", total);
  }
  else if (P=='-')
  {
  float total= A-B-C ;
  printf("Escriba su numero A  %.4f", total);
  }
  else if (P=='*')
  {
  float total= A*B*C ;
  printf("Escriba su numero A  %.4f", total);
  }
  else if (P=='/')
  {
  float total= A/(B/C) ;
  printf("Escriba su numero A  %.4f", total);
  }
  

}