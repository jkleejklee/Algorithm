#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    char s[5005];
    scanf("%d%s", &n, s);
    int c[2][5005] = {0};
    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++)
        {
            if (s[i] == s[j])
                c[i & 1][j] = c[(i + 1) & 1][j - 1];
            else
                c[i & 1][j] = min(c[(i + 1) & 1][j], c[i & 1][j - 1]) + 1;
        }
    printf("%d", c[0][n - 1]);
    return 0;
}
