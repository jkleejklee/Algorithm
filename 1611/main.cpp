#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 30005;
int p[N];
int Find(int x)
{
    return (p[x] < 0) ? x : Find(p[x]);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x < y)
    {
        p[x] += p[y];
        p[y] = x;
    }
    if (x > y)
    {
        p[y] += p[x];
        p[x] = y;
    }
}
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) && (n || m))
    {
        fill(p, p + N, -1);
        while (m--)
        {
            int k, a, b;
            scanf("%d%d", &k, &a);
            while (--k)
            {
                scanf("%d", &b);
                Union(a, b);
            }
        }
        printf("%d\n", -p[Find(0)]); 
    }
    return 0;
}
