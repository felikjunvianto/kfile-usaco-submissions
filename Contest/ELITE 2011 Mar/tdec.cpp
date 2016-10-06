/*
	ID: felikju1
	PROG: tdec
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
#define M 100010

using namespace std;

typedef struct
{
	int par,need,cost;
} nud;

int N,x,y,z,T;
int min_add[M],sum[M];
vector<int> adjlist[M];
nud node[M];
PII proses[M];
queue<PII> q;
LL ans;


int main()
{
	freopen ("tdec.in","r",stdin);
	freopen ("tdec.out","w",stdout);
	
	scanf("%d",&N);
	for(x=1;x<=N;x++) 
	{
		scanf("%d %d %d",&node[x].par,&node[x].need,&node[x].cost);
		if(node[x].par!=-1) adjlist[node[x].par].pb(x);
	}
	
	q.push(mp(0,1));
	T=0;
	while(!q.empty())
	{
		PII now=q.front();
		proses[T++]=now;
		q.pop();
		
		for(x=0;x<adjlist[now.se].size();x++)
			q.push(mp(now.fi-1,adjlist[now.se][x]));
	}
	
	for(x=1;x<=N;x++) min_add[x]=node[x].cost;
	memset(sum,0,sizeof(sum));
	
	ans=0;
	sort(proses,proses+T);
	for(z=0;z<T;z++)
	{
		PII now=proses[z];	
		for(x=0;x<adjlist[now.se].size();x++) 
			sum[now.se]+=sum[adjlist[now.se][x]];
		
		int kurang=node[now.se].need-sum[now.se];
		if(kurang>0)
		{
			ans+=((LL)kurang*(LL)min_add[now.se]);
			sum[now.se]+=kurang;
		}
		
		if(now.se!=1) min_add[node[now.se].par]=min(min_add[node[now.se].par],min_add[now.se]);
	}
	
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
