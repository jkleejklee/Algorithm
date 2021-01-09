#include <cstdio>
#include <cstring>
using namespace std;
char x[730][730];
int p[9] = {0, 0, 1, 3, 9, 27, 81, 243, 729}; 
void print(int n, int i, int j)
{
    if (n == 1)
    {
        x[i][j] = 'X';
        return;
    }
    print(n - 1, i, j);
    print(n - 1, i + p[n] * 2, j);
    print(n - 1, i + p[n], j + p[n]);
    print(n - 1, i, j + p[n] * 2);
    print(n - 1, i + p[n] * 2, j + p[n] * 2);
}
int main()
{
    memset(x, ' ', sizeof(x));
    print(7, 0, 0);
    int n;
    while (scanf("%d", &n) && ~n)
    {
        for (int i = 0; i < p[n + 1]; i++)
        {
            x[i][p[n + 1]] = '\0';
            puts(x[i]);
            x[i][p[n + 1]] = ' ';
        }
        printf("-\n");
    }
    return 0;
}
