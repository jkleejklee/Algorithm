#include <cstdio>
#include <cmath>
#include <cfloat>
using namespace std;
const int N = 10001;
const double PI = acos(-1.0);
const int M = N * N * PI; 
int r[N], n;
double search(double x)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += r[i] * r[i] * PI / x;
    return s;
}
int main()
{
    int t, f;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &f);
        for (int i = 0; i < n; i++)
            scanf("%d", &r[i]);
        double a = 0;
        double b = M;
        while ((b - a) > FLT_EPSILON)
        {
            double c = (a + b) * 0.5;
            if (search(c) < f + 1)
                b = c;
            else
                a = c;
        }
        printf("%.4f\n", a);
    }
    return 0;
}
