#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int m, int n) {
    int temp = m % n;
    if (temp == 0)
        return n;
    m = n;
    n = temp;
    return gcd(m, n);
}

long power_mod(long b, long e, long m) {
    long int r = 1;
    while (e) {
        if (e & 1)
            r = (r * b) % m;
        b = (b * b) % m;
        e >>= 1;
    }
    return r;
}

int main() {
    long p, q;
    printf("Enter the two prime numbers: ");
    scanf("%ld %ld", &p, &q);
    long m, n = p * q;
    printf("Enter the message: ");
    scanf("%ld", &m);
    long phi = (p - 1) * (q - 1);
    long e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        e++;
    }
    long d = 2;
    while (d < phi) {
        if ((e * d) % phi == 1)
            break;
        d++;
    }
    long enc = power_mod(m, e, n);
    long dec = power_mod(enc, d, n);
    printf("Encryption: %ld\n", enc);
    printf("Decryption: %ld\n", dec);
    return 0;
}
