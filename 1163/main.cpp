#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int D[355][355]; 
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            scanf("%d", &D[i][j]);
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            D[i][j] += max(D[i + 1][j], D[i + 1][j + 1]);
    printf("%d\n", D[0][0]);
    return 0;
}