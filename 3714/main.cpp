#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 100005;
const double MAX = 1e100;
struct Point
{
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    bool operator<(const Point &a) const
    {
        return x < a.x;
    }
};
double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        Point p[N], q[N];
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &q[i].x, &q[i].y);
        sort(p, p + n);
        sort(q, q + n);
        double ans = MAX;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            while (k < n && p[k].x < q[i].x)
                k++;
            for (int j = k; j < n; j++)
            {
                if ((p[j].x - q[i].x) > ans)
                    break;
                ans = min(ans, dist(p[j], q[i]));
            }
            for (int j = k - 1; j >= 0; j--)
            {
                if ((q[i].x - p[j].x) > ans)
                    break;
                ans = min(ans, dist(p[j], q[i]));
            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}
