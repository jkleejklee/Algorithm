#include <cstdio>
using namespace std;
const int N = 750;
struct Point
{
    int x, y;
    Point(){};
    Point(int x, int y) : x(x), y(y) {}
};
double area(Point p1, Point p2)
{
    return p1.x * p2.y - p2.x * p1.y;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double x = 0, y = 0;
        double s = 0;
        int n;
        Point p0;
        scanf("%d%d%d", &n, &p0.x, &p0.y);
        Point p1 = p0;
        while (n--)
        {
            Point p2;
            if (n)
                scanf("%d%d", &p2.x, &p2.y);
            else
                p2 = p0;
            double g = area(p1, p2);
            x += (p1.x + p2.x) * g;
            y += (p1.y + p2.y) * g;
            s += g;
            p1 = p2;
        }
        printf("%.2lf %.2lf\n", x / (3 * s), y / (3 * s));
    }
    return 0;
}
