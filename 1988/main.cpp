#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 30005;
int order[N];
int p[N];
int Find(int x)
{
    if (p[x] < 0)
        return x;
    int y = p[x];
    p[x] = Find(p[x]);
    order[x] += order[y];
    return p[x];
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    order[y] = p[x];
    p[x] = p[x] + p[y];
    p[y] = x;
}
int main()
{
    fill(p, p + N, -1);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char c;
        scanf("%*c%c", &c);
        int x, y;
        if (c == 'M')
        {
            scanf("%d%d", &x, &y);
            Union(x, y);
        }
        if (c == 'C')
        {
            scanf("%d", &x);
            y = Find(x);
            printf("%d\n", order[x] - p[y] - 1);
        }
    }
    return 0;
}
