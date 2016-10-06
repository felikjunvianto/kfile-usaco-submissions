/*
	ID: felikju1
	PROG: shopping
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
#define INF 1000000000

using namespace std;

int code[1010],cost[10];
int S,N,A,x,y,z;
map<vector<int>,int> dp;
vector<pair<vector<int>,int> > offer;
vector<int> dummy;

int solve(vector<int> T)
{
	if(dp.find(T)!=dp.end()) return(dp[T]);
	bool oke=true;
	int x,y,z;
	for(x=0;x<5;x++) if(T[x]) oke=false;
	if(oke) return(0);
	
	int &ret = dp[T] = INF;
	for(x=0;x<offer.size();x++)
	{
		oke=true;
		for(y=0;y<5;y++) if(T[y]<offer[x].fi[y]) oke=false;
		
		if(oke)
		{
			vector<int> next;
			for(y=0;y<5;y++) next.pb(T[y]-offer[x].fi[y]);
			ret=min(ret,offer[x].se+solve(next));
		}
	}
	
	int temp=0;
	for(x=0;x<5;x++) temp+=T[x]*cost[x];
	ret=min(ret,temp);
	return(ret);
}

int main()
{
	freopen ("shopping.in","r",stdin);
	freopen ("shopping.out","w",stdout);
	
	for(x=0;x<5;x++) dummy.pb(0);
	scanf("%d",&S);
	memset(code,-1,sizeof(code));
	A=0;
	while(S--)
	{
		scanf("%d",&N);
		offer.pb(mp(dummy,0));
		for(x=0;x<N;x++)
		{
			scanf("%d",&y);
			if(code[y]==-1) code[y]=A++;
			scanf("%d",&offer.back().fi[code[y]]);
		}
		scanf("%d",&offer.back().se);
	}
	
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d %d %d",&x,&y,&z);
		if(code[x]==-1) code[x]=A++;
		cost[code[x]]=z;
		dummy[code[x]]=y;
	}
	
	printf("%d\n",solve(dummy));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
