#include <cstdio>
#include <cstring>
using namespace std;
void postorder(char *left, char *right, int n)
{
    char root = left[0];
    if (n > 0)
    {
        int m = strchr(right, root) - right;
        postorder(left + 1, right, m); 
        postorder(left + m + 1, right + m + 1, n - m - 1); 
        printf("%c", root);
    }
}
int main()
{
    char s1[30], s2[30];
    while (~scanf("%s%s", s1, s2))
    {
        postorder(s1, s2, strlen(s1));
        printf("\n");
    }
    return 0;
}
