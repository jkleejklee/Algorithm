#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 100005;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
int main()
{
    int n, c, f;
    scanf("%d%d%d", &n, &c, &f);
    n /= 2; 
    pair<int, int> a[N];
    for (int i = 0; i < c; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a + c, cmp);
    int lsum[N]; 
    int rsum[N]; 
    priority_queue<int> R, L;
    for (int i = 0; i < n; i++)
    {
        lsum[n] += a[i].second;
        L.push(a[i].second);
    }
    for (int i = n; i < c - n; i++)
    {
        lsum[i + 1] = lsum[i];
        if (a[i].second < L.top())
        {
            lsum[i + 1] = lsum[i] + a[i].second - L.top();
            L.pop();
            L.push(a[i].second);
        }
    }
    for (int i = c - 1; i > c - n - 1; i--)
    {
        rsum[c - n - 1] += a[i].second;
        R.push(a[i].second);
    }
    for (int i = c - n - 1; i > n - 1; i--)
    {
        rsum[i - 1] = rsum[i];
        if (a[i].second < R.top())
        {
            rsum[i - 1] = rsum[i] + a[i].second - R.top();
            R.pop();
            R.push(a[i].second);
        }
    }
    int i;
    for (i = n; i < c - n && lsum[i] + a[i].second + rsum[i] > f; i++)
        ;
    printf("%d\n", (i == c - n) ? -1 : a[i].first);
    return 0;
}
