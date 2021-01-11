#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 100;
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
    bool operator<(const Segment &p) const
    {
        return (p1.x == p.p1.x) ? p2.x < p.p2.x : p1.x < p.p1.x;
    }
};
double cross(Point p1, Point p2, Point p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
Point intersection(Point p1, Point p2, Point p3, Point p4)
{
    double s1 = cross(p1, p2, p3);
    double s2 = cross(p1, p2, p4);
    return Point((p3.x * s2 - p4.x * s1) / (s2 - s1), (p3.y * s2 - p4.y * s1) / (s2 - s1));
}
int main()
{
    double a, b; 
    double y;
    while (scanf("%lf%lf%lf", &a, &b, &y) && (a || b || y))
    {
        Segment H = Segment(Point(a, y), Point(b, y)); 
        scanf("%lf%lf%lf", &a, &b, &y);
        Segment R = Segment(Point(a, y), Point(b, y)); 
        int n;
        scanf("%d", &n);
        Segment s[N]; 
        int scnt = 0; 
        while (n--)
        {
            scanf("%lf%lf%lf", &a, &b, &y);
            if (y > H.p1.y || y < R.p1.y)
                continue;
            Segment T = Segment(Point(a, y), Point(b, y)); 
            Segment S;                 
            S.p1 = intersection(H.p2, T.p1, R.p1, R.p2);
            S.p2 = intersection(H.p1, T.p2, R.p1, R.p2);
            if (S.p2.x < R.p1.x || S.p1.x > R.p2.x)
                continue;
            S.p1.x = max(S.p1.x, R.p1.x);
            S.p2.x = min(S.p2.x, R.p2.x);
            s[scnt++] = S;
        }
        sort(s, s + scnt);
        Segment u[N]; 
        memset(u, 0, sizeof(u));
        u[0] = R;
        int ucnt = 0; 
        for (int i = 0; i < scnt; i++)
        {
            if (u[ucnt].p1.x < s[i].p1.x)
            {
                u[ucnt].p2.x = s[i].p1.x;
                ucnt++;
            }
            u[ucnt].p1.x = max(u[ucnt].p1.x, s[i].p2.x);
            u[ucnt].p2.x = R.p2.x;
        }
        double ans = 0;
        for (int i = 0; i <= ucnt; i++)
            ans = max(ans, u[i].p2.x - u[i].p1.x);
        ans ? printf("%.2f\n", ans) : printf("No View\n");
    }
    return 0;
}
