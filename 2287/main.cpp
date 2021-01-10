#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        int t[1001]; 
        int q[1001]; 
        for (int i = 0; i < n; i++)
            scanf("%d", &t[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &q[i]);
        sort(t, t + n); 
        sort(q, q + n); 
        int ans = 0;   
        int ti = 0;  
        int qi = 0;  
        int tj = n - 1; 
        int qj = n - 1; 
        while (n--)
        {
            if (t[ti] > q[qi]) 
            {
                ans++;
                ti++;
                qi++;
            }
            else if (t[tj] > q[qj]) 
            {
                ans++;
                tj--;
                qj--;
            }
            else 
            {
                if (t[ti] != q[qj])
                    ans--;
                ti++;
                qj--;
            }
        }
        printf("%d\n", ans * 200);
    }
    return 0;
}
