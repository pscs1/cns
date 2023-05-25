#include <stdio.h>
 
int compute(int a, int m, int n)
{
    int r;
    int y = 1;
 
    while (m > 0)
    {
        r = m % 2;
        if (r == 1) {
            y = (y*a) % n;
        }
        a = a*a % n;
        m = m / 2;
    }

    return y;
}
 
int main()
{
    int p = 23;        
    int g = 9;        
 
    int a, b;    
    int A, B;   
  
   printf("Enter your private key:\n");
   scanf("%d",&a);
 
   A = compute(g, a, p);
   printf("Enter your friend's private key:\n");
   scanf("%d",&b);
 
   B = compute(g, b, p);
 
    int keyA = compute(B, a, p);
    int keyB = compute(A, b, p);
 
    printf("Your secret key is %d\nYour friend's secret key is %d\n", keyA, keyB);
 
    return 0;
}
