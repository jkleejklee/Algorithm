#include <cstdio>
#include <cstring>
using namespace std;
const int M = 1001;
int c[M][M]; 
int N;
int lowbit(int x)
{
    return x & (-x);
}
void update(int x, int y)
{
    for (int i = x; i <= N; i += lowbit(i))
        for (int j = y; j <= N; j += lowbit(j))
            c[i][j]++;
}
int query(int x, int y)
{
    int s = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j))
            s += c[i][j];
    return s;
}
int main()
{
    int X, T;
    char Q;
    scanf("%d", &X);
    while (X--)
    {
        memset(c, 0, sizeof(c));
        scanf("%d%d", &N, &T);
        while (T--)
        {
            scanf("\n%c", &Q);
            if (Q == 'C')
            {
                int x1, y1, x2, y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                update(x1, y1);
                update(x2 + 1, y1);
                update(x1, y2 + 1);
                update(x2 + 1, y2 + 1);
            }
            else
            {
                int x, y;
                scanf("%d%d", &x, &y);
                printf("%d\n", query(x, y) & 1);
            }
        }
        printf("\n");
    }
    return 0;
}
