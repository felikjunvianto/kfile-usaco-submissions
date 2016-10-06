/*
	ID: felikju1
	PROG: roadplane
	LANG: C++
*/

#include <cstdio>
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
#define gede 1000000001
#define PII pair<int,int> 

using namespace std;

vector<PII> adjlist[50010];
int x,y,z,source,a,b,cost;
int t,r,p;

int main()
{
	freopen ("roadplane.in","r",stdin);
	freopen ("roadplane.out","w",stdout);
	
	scanf("%d %d %d %d",&t,&r,&p,&source);
	vector<int> dis(t+2,gede);
	dis[source]=0;
	
	for(x=0;x<r;x++)
	{
		scanf("%d %d %d",&a,&b,&cost);
		adjlist[a].pb(mp(b,cost));
		adjlist[b].pb(mp(a,cost));
	}
	
	for(x=0;x<p;x++)
	{
		scanf("%d %d %d",&a,&b,&cost);
		adjlist[a].pb(mp(b,cost));
	}
	
	for(x=0;x<t;x++)
		for(y=1;y<=t;y++)
			for(z=0;z<adjlist[y].size();z++)
				dis[adjlist[y][z].fi]=min(dis[adjlist[y][z].fi],dis[y]+adjlist[y][z].se);

	for(x=1;x<=t;x++) if(dis[x]==gede) printf("NO PATH\n");
		else printf("%d\n",dis[x]);
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
