#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
const int M = 5010;
struct question
{
    int i, j, k;
    bool v; 
    int ans; 
} Q[M];
int C[N]; 
int id[N]; 
int tmp[N];
int pos;
int n;
pair<int, int> a[N];
int lowbit(int x)
{
    return x & (-x);
}
int sum(int x)
{
    int s;
    for (s = 0; x > 0; x -= lowbit(x))
        s += C[x];
    return s;
}
void update(int x, int d)
{
    while (x <= N)
    {
        C[x] += d;
        x += lowbit(x);
    }
}
void query(int l, int r, int L, int R)
{
    if (l > r || L == R)
        return;
    int mid = (L + R) >> 1;
    while (a[pos + 1].first <= mid && pos < n)
    {
        update(a[pos + 1].second, 1);
        pos++;
    }
    while (a[pos].first > mid)
    {
        update(a[pos].second, -1);
        pos--;
    }
    int cnt = 0; 
    for (int i = l; i <= r; i++)
    {
        if (sum(Q[id[i]].j) - sum(Q[id[i]].i - 1) > Q[id[i]].k - 1)
        {
            Q[id[i]].ans = mid;
            Q[id[i]].v = true;
            cnt++;
        }
        else
            Q[id[i]].v = false;
    }
    int p = l;
    int q = l + cnt;
    for (int i = l; i <= r; i++)
        if (Q[id[i]].v)
            tmp[p++] = id[i];
        else
            tmp[q++] = id[i];
    for (int i = l; i <= r; i++)
        id[i] = tmp[i];
    query(l, p - 1, L, mid);
    query(p, q - 1, mid + 1, R);
}
int main()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    pos = 0; 
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &Q[i].i, &Q[i].j, &Q[i].k);
        id[i] = i;
    }
    query(1, m, a[1].first, a[n].first + 1);
    for (int i = 1; i <= m; i++)
        printf("%d\n", Q[i].ans);
    return 0;
}
