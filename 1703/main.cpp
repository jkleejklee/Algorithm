#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 200005;
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
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        fill(p, p + 2 * n, -1);
        while (m--)
        {
            int a, b;
            char c;
            scanf("\n%c%d%d", &c, &a, &b);
            if (c == 'D')
            {
                Union(a, b + n);
                Union(a + n, b);
            }
            if (c == 'A')
            {
                if (Find(a) == Find(b))
                    printf("In the same gang.\n");
                else if (Find(a + n) == Find(b) || Find(a) == Find(b + n))
                    printf("In different gangs.\n");
                else
                    puts("Not sure yet.");
            }
        }
    }
}
