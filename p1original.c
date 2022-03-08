#include <stdio.h>

int gcd(int a, int b)

{
   if (a == 0)
      return b;
   return gcd(b%a, a);
}

void smallest(int &den3, int &n3)

{
   // Finding gcd of both terms
   int common_factor = gcd(n3,den3);
   den3 = den3/common_factor;
   n3 = n3/common_factor;
}

void add_frac(int n1, int den1, int n2, int den2, int &n3, int &den3)

{
   // to find the gcd of den1 and den2
   den3 = gcd(den1,den2);
    // LCM * GCD = a * b
   den3 = (den1*den2) / den3;
   // Changing the inputs to have same denominator
   // Numerator of the final fraction obtained
   n3 = (n1)*(den3/den1) + (n2)*(den3/den2);
   smallest(den3,n3);
}

int main() 

{
   int n1=1, den1=4, n2=2, den2=12, den3, n3;
   add_frac(n1, den1, n2, den2, n3, den3);
   printf("%d/%d + %d/%d = %d/%d\n", n1, den1, n2, den2, n3, den3);
   return 0;
}