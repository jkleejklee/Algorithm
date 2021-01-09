#include <cstdio>
using namespace std;
int a, b, c, d, e, f;
int solve()
{
    int u[4] = {0, 5, 3, 1};
    int ans = d + e + f + (c + 3) / 4; 
    int y = 5 * d + u[c % 4]; 
    if (b > y)
        ans += (b - y + 8) / 9; 
    int x = 36 * ans - 36 * f - 25 * e - 16 * d - 9 * c - 4 * b; 
    if (a > x)
        ans += (a - x + 35) / 36;
    return ans;
}
int main()
{
    while (scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) && a + b + c + d + e + f)
        printf("%d\n", solve());
    return 0;
}
