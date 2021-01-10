#include <cstdio>
using namespace std;
const int N = 32005;
int C[N];   
int levels[N]; 
int lowbit(int x)
{
    return x & (-x);
}
int sum(int x)
{
    int s;
    for (s = 0; x > 0; x -= lowbit(x))
        s += C[x];
    return s;
}
void update(int x)
{
    for (; x <= N; x += lowbit(x))
        C[x]++; 
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        levels[sum(x + 1)]++;
        update(x + 1);
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", levels[i]);
    return 0;
}
