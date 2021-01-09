#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 20005;
long long H[N]; 
int Size;       
int parent(int x)
{
    return x / 2;
}
int left(int x)
{
    return 2 * x;
}
int right(int x)
{
    return 2 * x + 1;
}
void minheapify(long long *H, int x)
{
    int y; 
    int l = left(x);
    int r = right(x);
    y = (l <= Size && H[l] < H[x]) ? l : x;
    y = (r <= Size && H[r] < H[y]) ? r : y;
    if (y != x)
    {
        swap(H[x], H[y]); 
        minheapify(H, y); 
    }
}
int minheappop(long long *H)
{
    long long y;
    if (Size > 0)
    {
        y = H[1];
        H[1] = H[Size]; 
        Size--;
        minheapify(H, 1); 
    }
    return y;
}
void minheapinsert(long long *H, long long x)
{
    H[++Size] = x; 
    for (int i = Size; i > 1 && H[parent(i)] > H[i]; i = parent(i))
        swap(H[parent(i)], H[i]);
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        long long a;
        scanf("%lld", &a);
        minheapinsert(H, a); 
    }
    long long ans = 0;
    while (Size > 1)
    {
        long long u = minheappop(H);
        long long v = minheappop(H);
        ans += u + v; 
        minheapinsert(H, u + v);
    }
    printf("%lld\n", ans);
    return 0;
}
