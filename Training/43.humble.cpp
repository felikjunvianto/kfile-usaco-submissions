/*
	ID: felikju1
	PROG: humble
	LANG: C++
*/

#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double> 
#define LL long long

using namespace std;

int N,K,x,y,z;
LL temp,batas= 2147483648LL;
PII prime[110];
vector<int> humb;

int main()
{
	freopen ("humble.in","r",stdin);
	freopen ("humble.out","w",stdout);
	
	scanf("%d %d",&K,&N);
	for(x=0;x<K;x++) 
	{
		scanf("%d",&prime[x].fi);
		prime[x].se=0;
	}
	
	humb.pb(1);
	for(z=1;z<=N;z++) 
	{
		int terkecil=-1,now;
		for(x=0;x<K;x++) 
		{
			temp=(LL)((LL)prime[x].fi*(LL)humb[prime[x].se]);
			if(temp<batas)
				if((terkecil==-1)||(terkecil>(int)temp))
				{
					terkecil=temp;
					now=x;
				}
		}
		
		humb.pb(prime[now].fi*humb[prime[now].se]);
		LL sama=(LL)humb.back();
		for(x=0;x<K;x++) 
		{
			temp=(LL)((LL)prime[x].fi*(LL)humb[prime[x].se]);
			if((temp<batas)&&(temp==sama)) prime[x].se++;
		}
	}
	
	printf("%d\n",humb[N]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
