#include <cstdio>
#include <queue>
using namespace std;
struct point
{
    int x, y;
} p, q;
char a[22][22]; 
int w, h;    
int BFS()
{
    int ans = 0;
    queue<point> Q;
    Q.push(p);
    do
    {
        p = Q.front();
        Q.pop();
        ans++;
        if (p.x > 0 && a[p.x - 1][p.y] == '.')
        {
            q.x = p.x - 1;
            q.y = p.y;
            a[q.x][q.y] = '#';
            Q.push(q);
        }
        if (p.x + 1 < h && a[p.x + 1][p.y] == '.')
        {
            q.x = p.x + 1;
            q.y = p.y;
            a[q.x][q.y] = '#';
            Q.push(q);
        }
        if (p.y > 0 && a[p.x][p.y - 1] == '.')
        {
            q.x = p.x;
            q.y = p.y - 1;
            a[q.x][q.y] = '#';
            Q.push(q);
        }
        if (p.y < w - 1 && a[p.x][p.y + 1] == '.')
        {
            q.x = p.x;
            q.y = p.y + 1;
            a[q.x][q.y] = '#';
            Q.push(q);
        }
    } while (!Q.empty());
    return ans;
}
int main()
{
    while (scanf("%d%d", &w, &h) && w && h)
    {
        for (int i = 0; i < h; i++)
        {
            getchar();
            for (int j = 0; j < w; j++)
            {
                scanf("%c", &a[i][j]);
                if (a[i][j] == '@') 
                {
                    p.x = i;
                    p.y = j;
                    a[i][j] = '#';
                }
            }
        }
        printf("%d\n", BFS());
    }
    return 0;
}
