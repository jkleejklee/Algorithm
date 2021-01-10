
	#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-4;
int main(int argc,char *args[])
{
    FILE *in=fopen(args[1],"r");
    FILE *out=fopen(args[2],"r");
    FILE *user=fopen(args[3],"r");
    int ret=0;
    //int T;
    //fscanf(in,"%d",&T);
    //while(T--)
    //{
    double a[4],b[4];
    fscanf(out,"%lf%lf%lf%lf",&a[0],&a[1],&a[2],&a[3]);
    fscanf(user,"%lf%lf%lf%lf",&b[0],&b[1],&b[2],&b[3]);
    sort(a,a+4);
    sort(b,b+4);
    for(int i=0; i<4; i++)
        if(fabs(a[i]-b[i])>eps)
            ret = 1;//Wrong Answer
    //}

    fclose(in);
    fclose(out);
    fclose(user);
    return ret;
}
