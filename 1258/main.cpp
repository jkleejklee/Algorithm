#include <cstdio>
#include <queue>
using namespace std;
const int N = 105;
struct edge
{
    int v; 
    int to;
    edge(int a, int b) : v(a), to(b) {}
    bool operator<(const edge a) const
    {
        return v > a.v;
    }
};
priority_queue<edge> Q; 
int n;  
int a[N][N]; 
bool vis[N];   
int Prim()
{
    int ans = 0; 
    vis[1] = true; 
    for (int i = 2; i <= n; i++)
        Q.push(edge(a[1][i], i));
    while (!Q.empty())
    {
        edge e = Q.top(); 
        Q.pop();
        if (!vis[e.to])
        {
            ans += e.v;      
            vis[e.to] = true; 
            for (int i = 1; i <= n; i++)
                if (i != e.to)
                    Q.push(edge(a[e.to][i], i));
        }
    }
    return ans;
}
int main()
{
    while (~scanf("%d", &n))
    {
        fill(vis, vis + N, 0);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);
        printf("%d\n", Prim());
    }
    return 0;
}
