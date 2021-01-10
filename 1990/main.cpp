#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 20005;
int C[N]; 
int S[N]; 
pair<int, int> A[N]; 
int lowbit(int x)
{
    return x & (-x);
}
void update(int x)
{
    int d = x;
    while (x <= N)
    {
        C[x]++;
        S[x] += d;
        x += lowbit(x);
    }
}
void sum(int x, int &pc, int &ps)
{
    while (x)
    {
        pc += C[x];
        ps += S[x];
        x -= lowbit(x);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &A[i].first, &A[i].second);
    sort(A, A + n);
    int all = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        update(A[i].second);
        int pc = 0;
        int ps = 0;
        sum(A[i].second, pc, ps);
        all += A[i].second;
        ans += A[i].first * (A[i].second * pc * 1LL - ps);
        ans += A[i].first * (all - ps - (i + 1 - pc) * A[i].second * 1LL);
    }
    printf("%lld\n", ans);
    return 0;
}
