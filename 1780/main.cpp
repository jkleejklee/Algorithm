#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1000010;
const int P[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int S[N]; 
int p[N]; 
bool v[N];
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        int m = P[n];
        fill(v, v + m, false);
        fill(p, p + m, 0);
        int top = 0;
        S[top] = 0;
        v[0] = true;
        while (top < m - 1)
        {
            int i = S[top];
            if (p[i] == 10)
            {
                top--;
                v[i] = false;
                p[i] = 0;
                continue;
            }
            p[i]++;
            int j = (i * 10 + p[i] - 1) % m;
            if (!v[j])
            {
                S[++top] = j;
                v[j] = true;
            }
        }
        for (int i = 1; i < n; i++)
            putchar('0');
        for (int i = 0; i < m; i++)
            putchar(S[i] % 10 + '0');
        printf("\n");
    }
}
