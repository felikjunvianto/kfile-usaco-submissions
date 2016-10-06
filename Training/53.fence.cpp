/*
	ID: felikju1
	PROG: fence
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

int F,x,a,b;
int deg[510];
int adjmat[510][510];
vector<int> adjlist[510];
stack<int> path;

void euler(int now)
{
	for(int i=0;i<adjlist[now].size();i++)
	{
		int next=adjlist[now][i];
		if(adjmat[now][next])
		{
			adjmat[now][next]--;
			adjmat[next][now]--;
			euler(next);
		}
	}
	path.push(now);
}	

int main()
{
	freopen ("fence.in","r",stdin);
	freopen ("fence.out","w",stdout);
	
	scanf("%d",&F);
	memset(adjmat,0,sizeof(adjmat));
	memset(deg,0,sizeof(deg));
	while(F--)
	{
		scanf("%d %d",&a,&b);
		adjmat[a][b]++;
		adjmat[b][a]++;
		deg[a]++,deg[b]++;
		adjlist[a].pb(b);
		adjlist[b].pb(a);
	}
	
	for(x=1;x<=500;x++) sort(adjlist[x].begin(),adjlist[x].end());
	for(x=1;x<=500;x++) if(deg[x]&1) break;
	if(x==501) x=1;
	euler(x);
	
	while(!path.empty())
	{
		printf("%d\n",path.top());
		path.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
