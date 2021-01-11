#include <cstdio>
using namespace std;
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
void intersection(Point p1, Point p2, Point p3, Point p4)
{
    int s1 = cross(p1, p2, p3);
    int s2 = cross(p1, p2, p4);
    if (s1 == 0 && s2 == 0)
        printf("LINE\n"); 
    else if (s1 == s2)
        printf("NONE\n"); 
    else
    {
        double x = (p3.x * s2 - p4.x * s1) * 1.0 / (s2 - s1);
        double y = (p3.y * s2 - p4.y * s1) * 1.0 / (s2 - s1);
        printf("POINT %.2lf %.2lf\n", x, y); 
    }
}
int main()
{
    int n;
    Point p1, p2, p3, p4;
    scanf("%d", &n);
    printf("INTERSECTING LINES OUTPUT\n");
    while (n--)
    {
        scanf("%d%d%d%d", &p1.x, &p1.y, &p2.x, &p2.y);
        scanf("%d%d%d%d", &p3.x, &p3.y, &p4.x, &p4.y);
        intersection(p1, p2, p3, p4);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
