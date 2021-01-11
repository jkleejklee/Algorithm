#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 400;
const int M = 400 * 2;
struct Line
{
    double p;   
    double r;  
    double h;  
    int bottom; 
    Line() {}
    Line(double p, double r, double h, int b) : p(p), r(r), h(h), bottom(b) {}
    bool operator<(const Line &a) const
    {
        return h < a.h;
    }
} l[N];   
double a[N]; 
double sum[M]; 
int cnt[M];    

void up(int x, int p, int r)
{
    if (cnt[x])
        sum[x] = a[r + 1] - a[p];
    else if (p == r)
        sum[x] = 0;
    else
        sum[x] = sum[x * 2] + sum[x * 2 + 1];
}
void update(int x, int p, int r, int L, int R, int c)
{
    if (p >= L && r <= R)
    {
        cnt[x] += c;
        up(x, p, r);
        return;
    }
    int m = (p + r) / 2;
    if (m >= L)
        update(x * 2, p, m, L, R, c);
    if (m < R)
        update(x * 2 + 1, m + 1, r, L, R, c);
    up(x, p, r);
}
int main()
{
    int c = 0;
    int n;
    while (scanf("%d", &n) && n)
    {
        n *= 2;
        double x1, x2, y1, y2;
        for (int i = 0; i < n; i += 2)
        {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            l[i] = Line(x1, x2, y1, 1);
            a[i] = x1;
            l[i + 1] = Line(x1, x2, y2, -1);
            a[i + 1] = x2;
        }
        sort(a, a + n);
        sort(l, l + n); 
        fill(cnt, cnt + M, 0);
        fill(sum, sum + M, 0);
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            int p = lower_bound(a, a + n, l[i].p) - a;
            int r = lower_bound(a, a + n, l[i].r) - a - 1;
            if (p <= r)
                update(1, 0, n - 1, p, r, l[i].bottom);
            ans += sum[1] * (l[i + 1].h - l[i].h);
        }
        printf("Test case #%d\n", ++c);
        printf("Total explored area: %.2f\n\n", ans);
    }
    return 0;
}
