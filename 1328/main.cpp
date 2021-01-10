#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmp(pair<double, double> a, pair<double, double> b)
{
    return a.second < b.second;
}
pair<double, double> s[1005];
int main()
{
    int n, t = 1;
    double d; 
    while (scanf("%d %lf", &n, &d) && (n || d))
    {
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            double x, y;
            scanf("%lf %lf", &x, &y);
            if (y > d)
            {
                ans = -1;
                continue;
            }
            if (ans == 1)
            {
                double r = sqrt(d * d - y * y);
                s[i] = make_pair(x - r, x + r);
            }
        }
        if (ans == 1)
        {
            sort(s, s + n, cmp); 
            double R = s[0].second; 
            for (int i = 1; i < n; i++)
                if (R < s[i].first) 
                {
                    R = s[i].second; 
                    ans++;
                }
        }
        printf("Case %d: %d\n", t++, ans);
    }
    return 0;
}
