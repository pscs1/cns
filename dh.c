#include <stdio.h>
int power_mod(int b, int e, int m)
{
    int r=1;
    while(e)
    {
        if (e&1) {
            r = (r*b) % m;
        }
        b = (b*b) % m;
        e>>=1;
    }
    return r;
}
int main()
{
    int q, alpha, Xa, Xb, Ya, Yb;
    printf("Enter a prime no.:\n");
    scanf("%d",&q);
    printf("Enter a primitive root of %d\n", q);
    scanf("%d",&alpha);
    printf("Enter your private key(XA):\n");
    scanf("%d",&Xa);
    Ya = power_mod(alpha, Xa, q);
    printf("Enter your friend's private key(XB):\n");
    scanf("%d",&Xb);
    Yb = power_mod(alpha, Xb, q);
    int keyA = power_mod(Yb, Xa, q);
    int keyB = power_mod(Ya, Xb, q);
    printf("Your secret key is %d\nYour friend's secret key is %d\n", keyA, keyB);
    return 0;
}
