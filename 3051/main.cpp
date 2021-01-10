#include <cstdio>
#include <algorithm>
using namespace std;
char a[1001][81];
int w, h;
int cnt; 
void DFS(int x, int y)
{
    if (a[x][y] == '.' || x >= h || y >= w || x < 0 || y < 0)
        return;
    a[x][y] = '.';
    cnt++;
    DFS(x - 1, y);
    DFS(x, y - 1);
    DFS(x, y + 1);
    DFS(x + 1, y);
}
int main()
{
    int ans = 0;
    scanf("%d%d\n", &w, &h);
    for (int i = 0; i < h; i++)
        gets(a[i]);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            cnt = 0;
            if (a[i][j] == '*')
                DFS(i, j); 
            ans = max(ans, cnt);
        }
    printf("%d\n", ans);
    return 0;
}
