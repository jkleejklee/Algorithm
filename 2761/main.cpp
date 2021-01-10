#include <cstdio>
#include <ctime>
#include <algorithm>
using namespace std;
const int N = 100010;
const int M = 50010;
struct Treap
{
    int a[2]; 
    int x; 
    int m; 
    int n; 
    int r; 
    Treap() {}
    Treap(int p)
    {
        a[0] = a[1] = 0;
        x = p;
        m = n = 1;
        r = rand();
    }
} T[N];
struct line
{
    int i, j, k;
    int id; 
    int x;  
    bool operator<(const line &a) const
    {
        return i < a.i;
    }
};
int tot;  
int a[N]; 
void rotateTreap(int &root, int d)
{
    int t = T[root].a[d];
    T[root].a[d] = T[t].a[d ^ 1];
    T[t].a[d ^ 1] = root;
    T[root].n = T[root].m + T[T[root].a[0]].n + T[T[root].a[1]].n;
    root = t;
}
void insertTreap(int &root, int x)
{
    if (!root)
    {
        root = ++tot;
        T[root] = Treap(x);
    }
    else if (x == T[root].x)
        T[root].m++;
    else
    {
        int d = (x > T[root].x); 
        insertTreap(T[root].a[d], x);
        if (T[T[root].a[d]].r < T[root].r)
            rotateTreap(root, d);
    }
    T[root].n = T[root].m + T[T[root].a[0]].n + T[T[root].a[1]].n;
}
void deleteTreap(int &root, int x)
{
    if (x == T[root].x)
    {
        if (T[root].m != 1)
            T[root].m--;
        else if (!T[root].a[0])
            root = T[root].a[1];
        else if (!T[root].a[1])
            root = T[root].a[0];
        else
        {
            int d = (T[T[root].a[0]].r < T[T[root].a[1]].r);
            rotateTreap(root, d);
            deleteTreap(T[root].a[!d], x);
        }
    }
    else
    {
        int d = (x > T[root].x);
        deleteTreap(T[root].a[d], x);
    }
    T[root].n = T[root].m + T[T[root].a[0]].n + T[T[root].a[1]].n;
}
int query(int root, int k)
{
    while (root)
    {
        int n = T[T[root].a[0]].n;
        if (n >= k)
            root = T[root].a[0];
        else if (n < k && k <= n + T[root].m)
            return T[root].x;
        else
        {
            k -= n + T[root].m;
            root = T[root].a[1];
        }
    }
    return 0;
}
int main()
{
    srand(time(0));
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        tot = 0;
        line Q[M];
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &Q[i].i, &Q[i].j, &Q[i].k);
            Q[i].id = i;
        }
        sort(Q, Q + m);
        int root = 0;
        int L, R; 
        for (L = R = Q[0].i; R <= Q[0].j; R++)
            insertTreap(root, a[R]);
        Q[Q[0].id].x = query(root, Q[0].k);
        for (int i = 1; i < m; i++)
        {
            for (; L < Q[i].i && L < R; L++)
                deleteTreap(root, a[L]);
            for (; R <= Q[i].j; R++)
                insertTreap(root, a[R]);
            for (; R > Q[i].j + 1; R--)
                deleteTreap(root, a[R - 1]);
            Q[Q[i].id].x = query(root, Q[i].k);
        }
        for (int i = 0; i < m; i++)
            printf("%d\n", Q[i].x);
    }
    return 0;
}
