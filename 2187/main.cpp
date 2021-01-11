#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 50005;
struct Point
{
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
} v[N], p[N];
int dist(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
int cross(Point p1, Point p2, Point p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
int cmp(Point p1, Point p2)
{
    return cross(p[0], p1, p2) > 0 || (!cross(p[0], p1, p2) && dist(p[0], p1) < dist(p[0], p2));
}
int convex(int n)
{
    v[0] = p[0];
    v[1] = p[1];
    int top = 1;
    for (int i = 2; i < n; i++)
    {
        while (top && cross(v[top - 1], v[top], p[i]) <= 0)
            top--;
        v[++top] = p[i];
    }
    return top;
}
int rotatingCalipers(int m)
{
    int q = 1;
    int ans = 0;
    for (int i = 0; i <= m; i++)
    {
        while (cross(v[i + 1], v[q + 1], v[i]) > cross(v[i + 1], v[q], v[i]))
            q = (q + 1) % m;
        ans = max(ans, max(dist(v[i], v[q]), dist(v[i + 1], v[q])));
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &p[i].x, &p[i].y);
        if (p[0].x > p[i].x || (p[0].x == p[i].x && p[0].y > p[i].y))
            swap(p[0], p[i]);
    }
    sort(p + 1, p + n, cmp);
    int m = convex(n);
    printf("%d\n", rotatingCalipers(m));
    return 0;
}
