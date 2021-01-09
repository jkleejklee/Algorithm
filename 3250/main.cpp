#include <cstdio>
#include <stack>
using namespace std;
int main()
{
    int n;
    long long ans = 0;
    stack<long long> c;
    scanf("%d", &n);
    while (n--)
    {
        int h;
        scanf("%d", &h);
        while (!c.empty() && h >= c.top())
            c.pop();
        ans += c.size();
        c.push(h);
    }
    printf("%lld\n", ans);
    return 0;
}
