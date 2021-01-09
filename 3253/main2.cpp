#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    int n;
    long long a, ans = 0;
    priority_queue<long long, vector<long long>, greater<long long>> Q;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%lld", &a);
        Q.push(a);
    }
    while (Q.size() > 1)
    {
        long long x = Q.top();
        Q.pop();
        long long y = Q.top();
        Q.pop();
        ans += x + y;
        Q.push(x + y);
    }
    printf("%lld\n", ans);
    return 0;
}
