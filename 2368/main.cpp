#include <cstdio>
using namespace std;
int main()
{
    int k;
    scanf("%d", &k);
    int n = 2;
    while (n * n < k && k % (n + 1))
        n++;
    if (n * n >= k)
    {
        if (k > 4 && !(k & 1))
            k = k / 2;
        n = k - 1;
    }
    printf("%d\n", n);
    return 0;
}
