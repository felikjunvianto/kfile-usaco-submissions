/*
	ID: felikju1
	PROG: preface
	LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char sim[] = {'I','V','X','L','C','D','M'};
int  jum[] = {1,5,10,50,100,500,1000};

int sum[7];
int t,x,y,z,bil,n;

int main()
{
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	scanf("%d",&n);
	for(t=1;t<=n;t++)
	{
		bil=t;
		for(x=6;x>=0;x--)
		{
			z=bil/jum[x];
			if(z>0)
			{
				if(z<4) sum[x] += z; else
				{
					sum[x] += 1;
					sum[x+1] += 1;
				}
				bil %= jum[x];
			}	
				
			z=bil/jum[x];
			if((z==0)&&(x>=2)&&((bil/(jum[x]-jum[x-2]))==1)&&(x%2==0))
			{
				sum[x-2] += 1;
				sum[x] += 1; 
				bil = bil - (jum[x]-jum[x-2]);
			}
		}
	}
	
	for(x=0;x<7;x++) if(sum[x]>0) printf("%c %d\n",sim[x],sum[x]);
	fclose(stdin);
	fclose(stdout);
}
