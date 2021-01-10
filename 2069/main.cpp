#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cfloat>
using namespace std;
struct point
{
    double x, y, z;
    point() {}
    point(double x, double y, double z) : x(x), y(y), z(z) {}
} P[31];
int n;
double dis(point p0, point p)
{
    return sqrt((p0.x - p.x) * (p0.x - p.x) + (p0.y - p.y) * (p0.y - p.y) + (p0.z - p.z) * (p0.z - p.z));
}
//模拟退火法
double SA()
{
    double minr = FLT_MAX;     //所求的最小半径
    point p0 = point(0, 0, 0); //初始点
    //t为温度，FLT_EPSILON为临界温度，0.98为降温速率
    for (double t = 100; t > FLT_EPSILON; t *= 0.98)
    {
        int k = 0; //保存最远点位置
        for (int i = 1; i < n; i++)
            if (dis(p0, P[i]) > dis(p0, P[k]))
                k = i;
        double maxr = dis(p0, P[k]); //maxr为最远距离
        minr = min(minr, maxr);
        //温度变化空间向距离最远点变化
        p0.x += (P[k].x - p0.x) * t / maxr;
        p0.y += (P[k].y - p0.y) * t / maxr;
        p0.z += (P[k].z - p0.z) * t / maxr;
    }
    return minr;
}
int main()
{
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; ++i)
            scanf("%lf%lf%lf", &P[i].x, &P[i].y, &P[i].z);
        printf("%.5f\n", SA());
    }
    return 0;
}
