#include <cstdio>
#include <algorithm>
using namespace std;
bool v[30][30]; 
bool found;
char path[100]; 
const int a[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int b[8] = {-2, -2, -1, -1, 1, 1, 2, 2}; 
int p, q;
void DFS(int i, int j, int k)
{
    if (k == p * q * 2)
        found = true;
    if (v[i][j] || found)
        return;
    path[k] = j - 2 + 'A';
    path[k + 1] = i - 2 + '1';
    v[i][j] = true;
    for (int t = 0; t < 8; t++)
        DFS(i + a[t], j + b[t], k + 2);
    v[i][j] = false;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        printf("Scenario #%d:\n", i);
        scanf("%d%d", &p, &q);
        found = false;
        fill(path, path + 100, 0);
        for (int i = 0; i < 30; i++)
            for (int j = 0; j < 30; j++)
                v[i][j] = (i < 2 || i > p + 1 || j < 2 || j > q + 1) ? 1 : 0;
        DFS(2, 2, 0); 
        printf("%s\n\n", found ? path : "impossible");
    }
    return 0;
}
