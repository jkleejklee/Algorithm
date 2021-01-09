#include <cstdio>
using namespace std;
int cube[1000001];
int main()
{
    int n, a;
    scanf("%d", &n);
    for (a = 2; a <= 100; a++)
        cube[a * a * a] = a;
    for (a = 2; a <= n; a++)
        for (int b = 2; b <= n; b++)
            for (int c = b; c <= n; c++)
            {
                int d = a * a * a - b * b * b - c * c * c;
                if (d > 0 && cube[d] >= c)
                    printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, cube[d]);
            }
    return 0;
}