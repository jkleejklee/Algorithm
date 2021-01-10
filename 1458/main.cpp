#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 2005;
int main()
{
    char a[N], b[N];
    while (~scanf("%s %s", a, b))
    {
        int la = strlen(a);
        int lb = strlen(b);
        int c[N][N] = {0};
        for (int i = 1; i <= la; i++)
            for (int j = 1; j <= lb; j++)
            {
                if (a[i - 1] == b[j - 1])
                    c[i][j] = c[i - 1][j - 1] + 1;
                else
                    c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        printf("%d\n", c[la][lb]);
    }
    return 0;
}
