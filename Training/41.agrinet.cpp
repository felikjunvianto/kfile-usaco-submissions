/*
	ID: felikju1
	PROG: agrinet
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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define eps 1e-9

using namespace std;

int node,x,y,z;
vector<pair<int,pair<int,int> > > edge;
int par[110];

int find(int i)
{
	if(par[i]==-1) par[i]=i; else
	{
		int ti=i;
		while(par[ti]!=ti) ti=par[ti];
		par[i]=ti;
	}
	return(par[i]);
}

bool uni(int i,int j)
{
	if(find(i)!=find(j))
	{
		par[par[i]]=par[j];
		return(false);
	} else return(true);
}

int kruskal()
{
	int x,mst=0;
	for(x=1;x<=node;x++) par[x]=-1;
	sort(edge.begin(),edge.end());
	
	for(x=0;x<edge.size();x++)
		if(!uni(edge[x].se.fi,edge[x].se.se)) mst+=edge[x].fi;
	return(mst);
}

int main()
{
	freopen ("agrinet.in","r",stdin);
	freopen ("agrinet.out","w",stdout);
	scanf("%d",&node);
	for(x=1;x<=node;x++)
		for(y=1;y<=node;y++) 
		{
			scanf("%d",&z);
			if(y!=x) edge.pb(mp(z,mp(x,y)));
		}
	printf("%d\n",kruskal());
	fclose(stdin);
	fclose(stdout);
	return 0;
}
