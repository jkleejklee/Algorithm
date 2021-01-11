#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10001;
const int M = 50001;
struct Edge
{
    int v, next;
    Edge() {}
    Edge(int a, int b) : v(a), next(b) {}
} e[M];
int head[N], p;
void init()
{
    fill(head, head + N, -1);
    p = 0;
}
void addEdge(int u, int v)
{
    e[p] = Edge(v, head[u]);
    head[u] = p++;
}
int dfn[N];  
int low[N];   
int U[N];  
int Dindex = 0; 
int Ucnt = 0;  
int Stack[N];
int top = 0;
bool in[N]; 
int n, m;
void tarjan(int u)
{
    int v;
    dfn[u] = low[u] = ++Dindex;
    in[u] = true;
    Stack[++top] = u;
    for (int i = head[u]; i + 1; i = e[i].next)
    {
        v = e[i].v;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        Ucnt++;
        do
        {
            v = Stack[top--];
            in[v] = false;
            U[v] = Ucnt;
        } while (v != u);
    }
}
void solve()
{
    fill(dfn, dfn + N, 0);
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
}
int main()
{
    int i, a[M], b[M], ans;
    int cnt[N];   
    int D[N];  
    int Dcnt = 0; 
    fill(D, D + N, 0);
    fill(cnt, cnt + N, 0);
    scanf("%d%d", &n, &m);
    init();
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        addEdge(a[i], b[i]);
    }
    solve();
    for (i = 1; i <= m; i++)
    {
        if (U[a[i]] != U[b[i]])
            D[U[a[i]]]++;
    }
    for (i = 1; i <= n; i++)
        cnt[U[i]]++;
    for (i = 1; i <= Ucnt; i++)
        if (!D[i])
        {
            Dcnt++;
            ans = cnt[i];
        }
    printf("%d\n", Dcnt == 1 ? ans : 0);
    return 0;
}
