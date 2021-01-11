#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 750;
struct Point
{
    int x, y;
    Point(){};
    Point(int x, int y) : x(x), y(y) {}
};
int cross(Point p1, Point p2, Point p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
bool onSegment(Point p1, Point p2, Point p0)
{
    return (p0.x >= min(p1.x, p2.x)) && (p0.x <= max(p1.x, p2.x)) && (p0.y >= min(p1.y, p2.y)) && (p0.y <= max(p1.y, p2.y));
}
bool interesect(Point p1, Point p2, Point p3, Point p4)
{
    int d1 = cross(p2, p3, p1);
    int d2 = cross(p2, p4, p1);
    int d3 = cross(p1, p4, p3);
    int d4 = cross(p2, p4, p3);
    if (d1 * d2 < 0 && d3 * d4 < 0)
        return true;
    else if (!d1 && onSegment(p1, p2, p3))
        return true;
    else if (!d2 && onSegment(p1, p2, p4))
        return true;
    else if (!d3 && onSegment(p3, p4, p1))
        return true;
    else if (!d4 && onSegment(p3, p4, p2))
        return true;
    return false;
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        Point p1, p2, p3, p4;
        scanf("%d%d%d%d%d%d%d%d", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y);
        Point p5 = Point(p4.x, p3.y);
        Point p6 = Point(p3.x, p4.y);
        bool ans = false;
        ans = ans || interesect(p1, p2, p3, p5);
        ans = ans || interesect(p1, p2, p6, p4);
        ans = ans || interesect(p1, p2, p3, p6);
        ans = ans || interesect(p1, p2, p5, p4);
        ans = ans || onSegment(p3, p4, p1);
        printf("%c\n", ans ? 'T' : 'F');
    }
    return 0;
}
