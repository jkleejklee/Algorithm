#include <cstdio>
#include <queue>
#include <cstdlib>
#include <climits>
using namespace std;
struct point
{
    int x; //棋盘上点的行值
    int y; //棋盘上点的列值
    int n; //到达该点的步数
    int h; //评估值
    point(int x, int y, int n) : x(x), y(y), n(n) {}
    bool operator<(const point a) const
    {
        return h > a.h;
    }
};
int v[12][12]; //保存到达该点的最少步数
const int d[2][8] = {-1, 1, -2, 2, -2, 2, -1, 1, -2, -2, -1, -1, 1, 1, 2, 2};
priority_queue<point> Q;
int H(point a, point b)
{
    return abs(b.x - a.x) + abs(b.y - a.y);
}
int main()
{
    char s[3], t[3];
    while (~scanf("%s %s", s, t))
    {
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 12; j++)
                v[i][j] = (i < 2 || i > 9 || j < 2 || j > 9) ? -1 : INT_MAX;
        point a = point(s[0] - 'a' + 2, s[1] - '1' + 2, 0);
        point b = point(t[0] - 'a' + 2, t[1] - '1' + 2, 0);
        a.h = H(a, b);
        v[a.x][a.y] = 0;
        int ans = INT_MAX;
        //使用优先队列，每次选择评估值最小的位置进行搜索
        Q = priority_queue<point>();
        Q.push(a);
        while (!Q.empty())
        {
            point i = Q.top();
            Q.pop();
            if (i.n >= ans)
                continue;
            if (i.x == b.x && i.y == b.y)
                ans = i.n;
            for (int j = 0; j < 8; j++)
            {
                point k = point(i.x + d[0][j], i.y + d[1][j], i.n + 1);
                if (~v[k.x][k.y] && k.n < v[k.x][k.y])
                {
                    v[k.x][k.y] = k.n;
                    k.h = H(k, b);
                    Q.push(k);
                }
            }
        }
        printf("To get from %s to %s takes %d knight moves.\n", s, t, ans);
    }
    return 0;
}
