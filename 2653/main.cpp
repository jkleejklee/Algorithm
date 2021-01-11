#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
struct Point
{
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
};
struct Segment
{
    Point p1, p2;
    bool t; 
    Segment() {}
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
} s[N];
double cross(Point p1, Point p2, Point p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
bool intersect(Point p1, Point p2, Point p3, Point p4)
{
    double d1 = cross(p2, p3, p1);
    double d2 = cross(p2, p4, p1);
    double d3 = cross(p1, p4, p3);
    double d4 = cross(p2, p4, p3);
    return (d1 * d2 < 0 && d3 * d4 < 0);
}
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        int m = n;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf%lf%lf%lf", &s[i].p1.x, &s[i].p1.y, &s[i].p2.x, &s[i].p2.y);
            s[i].t = false;
        }
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (intersect(s[i].p1, s[i].p2, s[j].p1, s[j].p2))
                {
                    s[i].t = true;
                    m--;
                    break;
                }
        printf("Top sticks:");
        for (int i = 1; i <= n; i++)
            if (!s[i].t)
                printf(" %d%s", i, (--m) ? "," : ".\n");
    }
    return 0;
}
