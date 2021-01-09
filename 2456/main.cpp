#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100001;
int x[N], n;
int search(int a)
{
    int j, s = 1;
    for (int i = 0; i < n; i = j)
        for (j = i + 1; j < n; j++)
            if (x[j] - x[i] >= a)
            {
                s++;
                break;
            }
    return s;
}
int main()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    sort(x, x + n);
    int a = 0;
    int b = x[n - 1] - x[0];
    while (b - a > 1)
    {
        int c = (a + b) / 2;
        if (search(c) < m)
            b = c;
        else
            a = c;
    }
    printf("%d\n", a);
    return 0;
}
