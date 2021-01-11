#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1000;
struct Point
{
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
} q[N]; 
struct Segment
{
    Point p1, p2;
    Segment() {}
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};
double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double cross(Point p1, Point p2, Point p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
Point intersection(Segment a, Segment b)
{
    double s1 = cross(a.p1, a.p2, b.p1);
    double s2 = cross(a.p1, a.p2, b.p2);
    return Point((b.p1.x * s2 - b.p2.x * s1) / (s2 - s1), (b.p1.y * s2 - b.p2.y * s1) / (s2 - s1));
}
int halfPlanesCross(Segment *a, int n)
{
    int h = 0;  
    int t = 1;  
    Segment b[N]; 
    b[0] = a[0];
    b[1] = a[1];
    for (int i = 2; i < n; i++)
    {
        while (h < t && cross(a[i].p1, a[i].p2, intersection(b[t - 1], b[t])) > 0)
            --t;
        while (h < t && cross(a[i].p1, a[i].p2, intersection(b[h], b[h + 1])) > 0)
            ++h;
        b[++t] = a[i];
    }
    while (h < t && cross(b[h].p1, b[h].p2, intersection(b[t - 1], b[t])) > 0)
        --t;
    while (h < t && cross(b[t].p1, b[t].p2, intersection(b[h], b[h + 1])) > 0)
        ++h;
    int m = 0;
    for (int i = h; i < t; i++)
        q[m++] = intersection(b[i], b[i + 1]);
    q[m++] = intersection(b[h], b[t]);
    q[m] = q[0];
    return m;
}
int main()
{
    int n;
    int r; 
    scanf("%d%d", &n, &r);
    Point p[N]; 
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    p[n] = p[0];
    Segment a[N]; 
    for (int i = 0; i < n; i++)
    {
        double d = dist(p[i], p[i + 1]);
        double dx = (p[i + 1].x - p[i].x) / d * r;
        double dy = (p[i + 1].y - p[i].y) / d * r;
        a[i] = Segment(Point(p[i].x + dy, p[i].y - dx), Point(p[i + 1].x + dy, p[i + 1].y - dx));
    }
    int m = halfPlanesCross(a, n); 
    double maxd = 0;
    int maxi, maxj;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
        {
            double d = dist(q[i], q[j]);
            if (maxd < d)
            {
                maxd = d;
                maxi = i;
                maxj = j;
            }
        }
    printf("%.4f %.4f %.4f %.4f", q[maxi].x, q[maxi].y, q[maxj].x, q[maxj].y);
    return 0;
}
