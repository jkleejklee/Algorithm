#include <cstdio>
#include <queue>
using namespace std;
const int N = 1001;
int T[1000000]; 
int main()
{
    int t, k = 0;
    while (scanf("%d", &t) && t)
    {
        printf("Scenario #%d\n", ++k);
        bool v[N]; 
        for (int i = 0; i < t; i++)
        {
            int n;
            scanf("%d", &n);
            v[i] = false;
            while (n--)
            {
                int x;
                scanf("%d", &x);
                T[x] = i;
            }
        }
        queue<int> Q[N]; 
        queue<int> TQ; 
        char cmd[10];
        while (scanf("%s", cmd) && cmd[0] != 'S')
        {
            if (cmd[0] == 'E')
            {
                int x;
                scanf("%d", &x);
                int i = T[x];
                if (!v[i])
                {
                    v[i] = true;
                    TQ.push(i); 
                }
                Q[i].push(x); 
            }
            else if (cmd[0] == 'D')
            {
                int i = TQ.front(); 
                printf("%d\n", Q[i].front()); 
                Q[i].pop();
                if (Q[i].empty())
                {
                    TQ.pop();
                    v[i] = false;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
