//Ln|sinx| = -ln2 - cos2x - cos(4x) / 2 - cos(2nx) / n для 0<x<pi
#include <stdio.h>
#include <math.h>

int main() {
        float s = -log(2);
        float x;
        float e;
        printf("vvedite x\n ");
        scanf("%f", &x);
        printf("vevdite e\n ");
        scanf("%f", &e);
        if ((x<0)||(x>3.1415)) {
                printf("nedopustimoe x\n");
                return 0;
        }
        x = 1.75;
        e = 0.00001;
        int  k = 1;
        float  c = 2 * x;
        float s1;
        while (fabs(cos(c) / k) > e) {
                s1 = s - cos(c) / k;
                k = k + 1;
                c = c + 2x;
                s = s1;
                printf("s = %f ", s);
                printf("+ %f ", cos(c)/k);
                printf("k = %d\n ", k);
        }
        printf("s= %f\n", s);
        printf("s0= %f\n", log(sin(x)));
        return 0;
}
