#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 50005;
int p[N];
int Find(int x)
{
    return (p[x] < 0) ? x : Find(p[x]);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x > y)
        p[x] = y;
    if (x < y)
        p[y] = x;
}
int main()
{
    int n, m, k = 1;
    while (scanf("%d%d", &n, &m) && (n || m))
    {
        fill(p, p + N, -1); 
        while (m--)
        {
            int i, j;
            scanf("%d%d", &i, &j);
            Union(i, j);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (p[i] == -1)
                ans++;
        printf("Case %d: %d\n", k++, ans);
    }
    return 0;
}
