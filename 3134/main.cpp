#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int v[1001] = {1}; 
int p;  
bool IDS(int now, int depth)
{
    if (now > depth)
        return false;
    if (v[p] << (depth - now) < n)
        return false;
    if (v[p] == n)
        return true;
    p++; 
    for (int i = 0; i < p; i++)
    {
        v[p] = v[p - 1] + v[i];
        if (IDS(now + 1, depth))
            return true;
        v[p] = abs(v[p - 1] - v[i]);
        if (IDS(now + 1, depth))
            return true;
    }
    p--; 
    return false;
}
int main()
{
    while (scanf("%d", &n) && n)
    {
        int depth = 0;
        p = 0;
        while (!IDS(0, depth))
            depth++;
        printf("%d\n", depth);
    }
    return 0;
}
