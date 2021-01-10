#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return (a.second * 1.0) / a.first > (b.second * 1.0) / b.first;
}
int main()
{
    int n;
    scanf("%d", &n);
    pair<int, int> a[N];
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a + n, cmp); 
    long long ans = 0;
    for (int i = 1, k = a[0].first; i < n; k += a[i].first, i++)
        ans += a[i].second * k * 2;
    printf("%lld\n", ans);
    return 0;
}
