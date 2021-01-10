#include <stdio.h>
#include <math.h>
#define eps (2*1e-5)
int main(int argc, char **argv)
{
    FILE *pin;
    FILE *pout;
    FILE *uout;
    double pans;
    double uans;
    int ret;
    pin = fopen(argv[1], "r");
    pout = fopen(argv[2], "r");
    uout = fopen(argv[3], "r");
    ret = 0;
    while (1)
    {
        int peof = fscanf(pout, "%lf", &pans);
        int ueof = fscanf(uout, "%lf", &uans);
        if (peof == EOF || ueof == EOF)
        {
            if (peof != ueof)
            {
                ret = 1;
            }
            break;
        }
        if (fabs(peof - ueof) > eps)
        {
            ret = 1;
            break;
        }
    }
    fclose(pin);
    fclose(pout);
    fclose(uout);
    return ret;
}