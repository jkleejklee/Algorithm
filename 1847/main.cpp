#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 105;
const int M = N * (N - 1) / 2;
const int INF = 0x3f3f3f3f;
int n;
int m; 
int D[N];
struct Edge
{
    int u, v, w;
    Edge() {}
    Edge(int a, int b, int c) : u(a), v(b), w(c) {}
} e[M];
void Bellman_Ford()
{
    while (n--)
        for (int i = 0; i < m; i++)
            D[e[i].v] = min(D[e[i].v], D[e[i].u] + e[i].w);
}
int main()
{
    int a, b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++)
    {
        D[i] = INF;
        int k;
        scanf("%d", &k);
        for (int p = 0; p < k; p++)
        {
            int j;
            scanf("%d", &j);
            e[m++] = Edge(i, j, p > 0);
        }
    }
    D[a] = 0;
    Bellman_Ford();
    printf("%d\n", (D[b] == INF) ? -1 : D[b]);
    return 0;
}
