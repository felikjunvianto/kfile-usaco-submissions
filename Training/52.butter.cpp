/*
	ID: felikju1
	PROG: butter
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

int N,P,C;
int x,y,z,total,temp;
int cow[600],dis[810][810];
vector<PII> adjlist[810];
bool visited[810];
priority_queue<PII,vector<PII>,greater<PII> > pq;


void dijkstra(int s)
{
	int x;
	memset(visited,false,sizeof(visited));
	for(x=1;x<=P;x++) dis[s][x]=1000000000;
	pq.push(mp(0,s));
	
	while(!pq.empty())
	{
		PII now=pq.top();
		pq.pop();
		
		if(!visited[now.se])
		{
			visited[now.se]=true;
			dis[s][now.se]=now.fi;
			
			for(x=0;x<adjlist[now.se].size();x++)
			{
				PII next=adjlist[now.se][x];
				if(!visited[next.fi])
					pq.push(mp(dis[s][now.se]+next.se,next.fi));
			}
		}
	}
}

int main()
{
	freopen ("butter.in","r",stdin);
	freopen ("butter.out","w",stdout);
	
	scanf("%d %d %d",&N,&P,&C);
	for(x=0;x<N;x++) scanf("%d",&cow[x]);
	while(C--)
	{
		scanf("%d %d %d",&x,&y,&z);
		adjlist[x].pb(mp(y,z));
		adjlist[y].pb(mp(x,z));
	}
	
	for(x=0;x<N;x++) dijkstra(cow[x]);
	total=-1;
	for(x=1;x<=P;x++)
	{
		temp=0;
		for(y=0;y<N;y++) temp+=dis[cow[y]][x];
		if((total==-1)||(total>temp)) total=temp;
	}
	
	printf("%d\n",total);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
