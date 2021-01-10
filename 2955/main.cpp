#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 101;
int f(char a, char b)
{
    return ((a == '[' && b == ']') || (a == '(' && b == ')')) ? 2 : 0;
}
int main()
{
    char s[N]; 
    while (scanf("%s", s) && s[0] != 'e')
    {
        int D[N][N] = {0}; 
        int m = strlen(s); 
        for (int t = 1; t <= m - 1; t++) 
            for (int i = 0; i <= m - t - 1; i++)
            {
                int j = i + t;
                for (int k = i; k <= j - 1; k++)
                    D[i][j] = max(D[i][j], max(D[i][k] + D[k + 1][j], D[i + 1][j - 1] + f(s[i], s[j])));
            }
        printf("%d\n", D[0][m - 1]);
    }
    return 0;
}
