#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 750;
struct Point
{
    int x, y;
    Point(){};
    Point(int x, int y) : x(x), y(y) {}
} p[N];
int cross(Point p1, Point p2, Point p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &p[i].x, &p[i].y);
            for (int j = i - 1; j >= 0; j--)
            {
                int m = 2;
                for (int k = j - 1; k >= 0; k--)
                    if (!cross(p[j], p[k], p[i]))
                        m++;
                ans = max(ans, m);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
