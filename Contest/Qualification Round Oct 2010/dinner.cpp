/*
PROG: dinner          
LANG: C++           
ID: felikju1
*/


#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>

#define fi first
#define se second

using namespace std;

pair < long long, long long > sapi[1100];
pair < long long, long long > meja[1100];
bool duduk[1100];

int n,m,x,y,z;
int hungry[1100],panjang;

int main()
{
	freopen("dinner.in","r",stdin);
	freopen("dinner.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(x=1;x<=n;x++) scanf("%lld %lld",&sapi[x].fi,&sapi[x].se);
	for(x=1;x<=m;x++) scanf("%lld %lld",&meja[x].fi,&meja[x].se);
	
	memset(duduk,false,sizeof(duduk));
	
	for(y=1;y<=m;y++)
	{
		long long min = 8000000000000LL;
		int siapa=1001;
		for(x=1;x<=n;x++) if(!duduk[x])
		{
			long long temp = (long long)((meja[y].fi-sapi[x].fi)*(meja[y].fi-sapi[x].fi)
										+(meja[y].se-sapi[x].se)*(meja[y].se-sapi[x].se));
			if(temp<min)
			{
				min=temp;
				siapa=x;
			}
		}
		
		duduk[siapa]=true;
	}

	panjang=0;
	for(x=1;x<=n;x++) if(!duduk[x])
	{
		panjang++;
		hungry[panjang]=x;
	}

	if(panjang==0) printf("0\n"); else
		for(x=1;x<=panjang;x++) printf("%d\n",hungry[x]);
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}

