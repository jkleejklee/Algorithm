#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[200]; //输入序列
char b[200]; //输出序列
bool v[200]; //记录序列中字母是否被使用
void perm(unsigned int k)
{
    char c = '\0'; //记录本层递归使用的字母
    if (k == strlen(a))
    {
        b[k] = '\0';
        puts(b);
    }
    for (int i = 0; a[i]; i++)
    {
        if (!v[i] && a[i] != c)
        {
            b[k] = a[i];
            v[i] = true;
            c = a[i];
            perm(k + 1);
            v[i] = false;
        }
    }
}
int main()
{
    scanf("%s", a);
    sort(a, a + strlen(a));
    perm(0);
    return 0;
}
