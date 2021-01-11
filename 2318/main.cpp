#include <cstdio>
using namespace std;
const int N = 5005;
int n;
double x1, y1, x2, y2;
struct Point
{
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
};
struct Segment
{
    Point p1, p2;
    Segment() {}
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
} b[N];
double cross(Point p1, Point p2, Point p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
int box(Point p)
{
    if (p.x < x1 || p.x > x2 || p.y < y2 || p.y > y1)
        return n + 1;
    int l = 0;
    int r = n + 1;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (cross(b[mid].p1, p, b[mid].p2) < 0)
            l = mid;
        else
            r = mid;
    }
    return l;
}
int main()
{
    while (scanf("%d", &n) && n)
    {
        int m;
        scanf("%d%lf%lf%lf%lf", &m, &x1, &y1, &x2, &y2);
        b[0] = Segment(Point(x1, y1), Point(x1, y2));
        int i;
        for (i = 1; i <= n; i++)
        {
            double u, l;
            scanf("%lf%lf", &u, &l);
            b[i] = Segment(Point(u, y1), Point(l, y2));
        }
        b[i] = Segment(Point(x2, y1), Point(x2, y2));
        int a[N] = {0}; 
        for (i = 0; i < m; i++)
        {
            double x, y;
            scanf("%lf%lf", &x, &y);
            a[box(Point(x, y))]++;
        }
        for (i = 0; i <= n; i++)
            printf("%d: %d\n", i, a[i]);
        printf("\n");
    }
    return 0;
}
