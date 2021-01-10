#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int V, F[10001];
void completePack(int c, int w)
{
    for (int v = c; v <= V; v++)
        F[v] = min(F[v], F[v - c] + w);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int e, f, n;
        scanf("%d%d%d ", &e, &f, &n);
        scanf("");
        V = f - e;
        fill(F + 1, F + V + 1, INF);
        while (n--)
        {
            int p, w;
            scanf("%d%d", &p, &w);
            completePack(w, p); 
        }
        if (F[V] == INF)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n", F[V]);
    }
    return 0;
}
