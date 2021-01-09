#include <cstdio>
#include <cmath>
using namespace std;
double x[101], y[101];
int n;
double f(double x1, double y1)
{
    double sum = 0;
    for (int i = 0; i < n; ++i)
        sum += sqrt((x1 - x[i]) * (x1 - x[i]) + (y1 - y[i]) * (y1 - y[i]));
    return sum;
}
double fy(double x1)
{
    double l = 0;
    double r = 10000;
    while (r - l > 0.1)
    {
        double lt = (l * 2 + r) / 3;
        double rt = (l + r * 2) / 3;
        f(x1, lt) < f(x1, rt) ? r = rt : l = lt;
    }
    return f(x1, l);
}
double fx()
{
    double l = 0;
    double r = 10000;
    while (r - l > 0.1)
    {
        double lt = (l * 2 + r) / 3;
        double rt = (l + r * 2) / 3;
        fy(lt) < fy(rt) ? r = rt : l = lt;
    }
    return fy(l);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lf%lf", &x[i], &y[i]);
    printf("%.0f\n", fx());
    return 0;
}
