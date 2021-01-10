#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 30005;
int p[N];
int Find(int x)
{
    return (p[x] < 0) ? x : Find(p[x]);
}
//改进的合并操作，在合并的同时，将子节点集合的个数加到父节点集合的个数值上，使得父节点的P值保存合并后元素的个数
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
        printf("%d\n", -p[Find(0)]); //在合并过程中，始终累加的数量为负值，最后对该值取反就是集合中元素的数量
    }
    return 0;
}
