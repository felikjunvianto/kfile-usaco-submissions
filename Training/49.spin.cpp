/*
	ID: felikju1
	PROG: spin
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

int v[10],T,N,now,x,y,z;
int tembus[400];
vector<PII> wed[10];
bool lolos;

int main()
{
	freopen ("spin.in","r",stdin);
	freopen ("spin.out","w",stdout);
	
	T=1;
	for(x=1;x<=5;x++)
	{
		scanf("%d",&v[x]);
		now=360/__gcd(v[x],360);
		T=T*now/__gcd(T,now);
		
		scanf("%d",&N);
		while(N--)
		{
			scanf("%d %d",&y,&z);
			z=(y+z)%360;
			wed[x].pb(mp(y,z));
		}
	}
	
	lolos=false;
	for(z=0;z<T;z++)
	{
		memset(tembus,0,sizeof(tembus));
		for(y=1;y<=5;y++)
			for(x=0;x<wed[y].size();x++)
			{
				int a=wed[y][x].fi,b=wed[y][x].se;
				if(b<a) b+=360;
			
				for(int i=a;i<=b;i++) tembus[i%360]++;
			}
			
		for(y=0;y<360;y++) if(tembus[y]==5) lolos=true;
		if(lolos)
		{
			printf("%d\n",z);
			break;
		}
		
		for(y=1;y<=5;y++)
			for(x=0;x<wed[y].size();x++)
			{
				wed[y][x].fi=(wed[y][x].fi+v[y])%360;
				wed[y][x].se=(wed[y][x].se+v[y])%360;
			}
	}
	
	if(!lolos) printf("none\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
