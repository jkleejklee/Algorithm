#include <cstdio>
using namespace std;
const int N = 750;
const int w[10][2] = {0, 0, -1, -1, 0, -1, 1, -1, -1, 0, 0, 0, 1, 0, -1, 1, 0, 1, 1, 1};
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
int area(Point p1, Point p2)
{
    return cross(p1, p2, Point(0, 0));
}
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        long long ans = 0;
        char c;
        Point p1 = Point(0, 0);
        while (scanf("%c", &c) && c != '5')
        {
            Point p2 = Point(p1.x + w[c - '0'][0], p1.y + w[c - '0'][1]);
            ans += area(p1, p2);
            p1 = p2;
        }
        if (ans < 0)
            ans = -ans;
        printf("%lld%s", ans / 2, (ans & 1) ? ".5\n" : "\n");
    }
    return 0;
}
