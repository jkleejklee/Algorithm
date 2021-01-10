#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const double eps = 1e-3;
int main(int argc,char *args[])
{

    FILE *in=fopen(args[1],"r");
    FILE *out=fopen(args[2],"r");
    FILE *user=fopen(args[3],"r");
    int ret=0;
    char a[10];
    for(int i=0; i<9; i++)
    {
        fscanf(in,"%c%*c",&a[i]);
    }
    char b[1000];
    fscanf(user,"%s",b);
    for(int i=0; b[i]; i++)
    {
        int x=strchr(a,'x')-a;
        if(x>=6 && b[i]=='d')
            return 1;
        if(x<3 && b[i]=='u')
            return 1;
        if(!x%3 && b[i]=='l')
            return 1;
        if(x%3==2 && b[i]=='r')
            return 1;
        switch(b[i])
        {
        case 'u':
            swap(a[x],a[x-3]);
            break;
        case 'd':
            swap(a[x],a[x+3]);
            break;
        case 'l':
            swap(a[x],a[x-1]);
            break;
        case 'r':
            swap(a[x],a[x+1]);
            break;
        }
    }
    if(strcmp(a,"12345678x"))
        ret=1;

    fclose(in);
    fclose(out);
    fclose(user);
    return ret;
}
