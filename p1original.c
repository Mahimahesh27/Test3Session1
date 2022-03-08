#include <stdio.h>


void input(int *n1, int *den1, int *n2, int *den2);

int gcd(int a, int b);

void smallest(int den3, int n3);

void add_frac(int n1, int den1, int n2, int den2, int *n3, int *den3);

void output(int n1, int den1, int n2, int den2, int n3, int den3);

int main()
{
  int *n1, *den1, *n2, *den2, *n3, *den3;
  input(&n1, &den1, &n2, &den2);
  add_frac(n1, den1, n2, den2, &n3, &den3);
  output(n1, den1, n2, den2, n3, den3); 
}

void input(int *n1, int *den1, int *n2, int *den2)
{
  printf("Enter Numerator 1: ");
  scanf("%d", n1);

  printf("Enter Denominator 1: ");
  scanf("%d", den1);

  printf("Enter Numerator 2: ");
  scanf("%d", n2);

  printf("Enter Denominator 2: ");
  scanf("%d", den2);
}

int gcd(int a, int b) 
{
   if (a == 0)
      return b;
   return gcd( b%a , a);
}

void smallest(int den3, int n3) 
{
   // Finding gcd of both terms
   int common_factor = gcd(n3,den3);
   den3 = den3 / common_factor;
   n3 = n3 / common_factor;
}

void add_frac(int n1, int den1, int n2, int den2, int *n3, int *den3) 
{
   
   *den3 = gcd(den1,den2);
   
   *den3 = (den1*den2) / (*den3);
   
   *n3 = (n1)*( *den3 / den1) + (n2)*((*den3)/den2);
   smallest(*den3, *n3);
}

void output(int n1, int den1, int n2, int den2, int n3, int den3)
{
  printf("The summ of 2 fractions %d/%d and %d/%d= %d/%d", n1, den1, n2, den2, n3, den3);
}