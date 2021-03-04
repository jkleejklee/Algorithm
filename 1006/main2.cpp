#include <cstdio>
using namespace std;
int main()
{
    int p,e,i,d;
    int n=1;
    while(scanf("%d%d%d%d",&p,&e,&i,&d)&&~p)
    {
        int ans=(p*5544+e*14421+i*1288-d)%21252;
        if(ans<=0)
            ans+=21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",n++,ans);
    }
    return 0;
}