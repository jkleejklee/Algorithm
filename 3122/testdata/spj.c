
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-3;
int main(int argc,char *args[])
{
    FILE *in=fopen(args[1],"r");
    FILE *out=fopen(args[2],"r");
    FILE *user=fopen(args[3],"r");
    int ret=0;
    int T;
    fscanf(in,"%d",&T);
    while(T--)
    {
    double a,b;
    fscanf(out,"%lf",&a);
    fscanf(user,"%lf",&b);
    if(fabs(a-b)>eps)
        ret = 1;//Wrong Answer
    }
    fclose(in);
    fclose(out);
    fclose(user);
    return ret;
}
