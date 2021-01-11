#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1005;
const int M = 100005;
const int INF = 0x3f3f3f3f;
int head[N], head1[N];
int n; 
int m; 
int k; 
int p;
int D[N];
struct Node
{
    int id;  
    int dis; 
    Node(int a, int b) : id(a), dis(b) {}
    bool operator<(const Node &a) const
    {
        return dis + D[id] > a.dis + D[a.id];
    }
};
struct Edge
{
    int u, v, w, next, next1;
    Edge() {}
    Edge(int a, int b, int c, int d, int e) : u(a), v(b), w(c), next(d), next1(e) {}
} e[M];
void init()
{
    fill(head, head + N, -1);
    fill(head1, head1 + N, -1);
    p = 0;
}
void addEdge(int u, int v, int w)
{
    e[p] = Edge(u, v, w, head[u], head1[v]);
    head[u] = p;
    head1[v] = p++;
}
void Dijkstra(int s)
{
    priority_queue<int> Q;
    fill(D, D + n + 1, INF);
    D[s] = 0;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.top();
        Q.pop();
        for (int i = head1[u]; i + 1; i = e[i].next1)
            if (D[e[i].u] > D[u] + e[i].w)
            {
                D[e[i].u] = D[u] + e[i].w;
                Q.push(e[i].u);
            }
    }
}
int Astar(int s, int t)
{
    priority_queue<Node> Q;
    Q.push(Node(s, 0));
    k--;
    while (!Q.empty())
    {
        Node p = Q.top();
        Q.pop();
        if (p.id == t)
        {
            if (k)
                k--;
            else
                return p.dis;
        }
        for (int i = head[p.id]; i + 1; i = e[i].next)
            Q.push(Node(e[i].v, p.dis + e[i].w));
    }
    return -1;
}
int main()
{
    scanf("%d%d", &n, &m);
    init();
    for (int i = 0; i < m; i++)
    {
        int a, b;
        int w; 
        scanf("%d%d%d", &a, &b, &w);
        addEdge(a, b, w);
    }
    int s; 
    int t; 
    scanf("%d%d%d", &s, &t, &k);
    Dijkstra(t);
    if (s == t)
        k++;
    printf("%d\n", Astar(s, t));
    return 0;
}
