#include <cstdio>
#include <vector>
using namespace std;
struct job
{
    int v; 
    int p; 
    job(int a, int b) : v(a), p(b) {}
};
bool check(vector<job> Q, int x, unsigned int i)
{
    while (i < Q.size())
        if (x < Q[i++].p)
            return true;
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        vector<job> Q;
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0, p; i < n; i++)
        {
            scanf("%d", &p);
            Q.push_back(job(i, p));
        }
        int ans = 1;
        for (int k = 0; check(Q, Q[k].p, k) || Q[k].v != m; k++)
        {
            if (check(Q, Q[k].p, k))
                Q.push_back(Q[k]);
            else
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
