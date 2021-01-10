#include <cstdio>
#include <queue>
using namespace std;
const int N = 310;
const int p[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int q[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
struct point
{
    int x; 
    int y;
    int n; 
    point(int x, int y, int n) : x(x), y(y), n(n) {}
};
bool v[N][N];
int BFS(point &a, point &b)
{
    queue<point> Q;
    Q.push(a);
    while (!Q.empty())
    {
        point i = Q.front();
        Q.pop();
        if (i.x == b.x && i.y == b.y)
            return i.n;
        for (int t = 0; t < 8; t++)
        {
            point j = point(i.x + p[t], i.y + q[t], i.n + 1);
            if (!v[j.x][j.y])
            {
                v[j.x][j.y] = true;
                Q.push(j);
            }
        }
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int l, x, y;
        scanf("%d%d%d", &l, &x, &y);
        point a = point(x + 2, y + 2, 0);
        scanf("%d%d", &x, &y);
        point b = point(x + 2, y + 2, 0);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                v[i][j] = (i < 2 || i > l + 1 || j < 2 || j > l + 1) ? 1 : 0;
        printf("%d\n", BFS(a, b));
    }
    return 0;
}
