#include <cstdio>
#include <cmath>
#include <cfloat>
using namespace std;
double L;
double f(double x)
{
    double R = (x * x + L * L / 4) / (2 * x);
    double a = asin(L / (2 * R));
    return 2 * R * a;
}
int main()
{
    double n, C;
    while (scanf("%lf%lf%lf", &L, &n, &C))
    {
        if (L == -1 && n == -1 && C == -1)
            break;
        double L1 = (1 + n * C) * L;
        double a = 0;
        double b = L / 2;
        double c;
        while (b - a > FLT_EPSILON)
        {
            c = (a + b) / 2;
            if (f(c) >= L1)
                b = c;
            else
                a = c;
        }
        printf("%.3f\n", c);
    }
    return 0;
}
