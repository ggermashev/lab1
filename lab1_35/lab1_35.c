// m-целое число. Увеличить цифры числа m на 3. При переходе через 0 брать только одну цифру.
#include <stdio.h>

int plus3(n, k, c) {
        return n - (n % (k * 10) / k) * k+((n + c * k) % (k * 10) / k) * k;
}

int minus3(n, k, c) {
        return  n - (n % (k * 10) / k) * k +(((10+ (n % (k * 10) / k)) - c) % 10) * k;
}

int main(){
        int n , m;
        printf("vvedite m\n");
        scanf("%d", &m);
        int c = 3;
        int k = 1;
        int sgn = 1;
        if (m == 0) {
                m = 3;
                printf("%d\n", m);
                m = 0;
                printf("%d\n", m);
        }
        if (m < 0) { sgn = -1; }
        n = sgn * m;
        while (n / k>0) {
                n = plus3(n, k, c);
                k = k * 10;
        }
        m = sgn * n;
        printf("novoe m=");
        printf("%d\n", m);
        int s = k;
        k = 1;
        while (s > 1) {
                 n = minus3(n, k, c) ;
                 k = k * 10;
                 s = s / 10;
        }
        m = sgn * n;
        printf("nachal'noe m=");
        printf("%d\n",m);
        return 0;
}

