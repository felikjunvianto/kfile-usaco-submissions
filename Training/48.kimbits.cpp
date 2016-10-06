/*
	ID: felikju1
	PROG: kimbits
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

int N,L,x;
unsigned int dp[40][40],I,ans;

unsigned int solve(int now,int left)
{
	if(now==N) return(1);
	if(dp[now][left]!=-1) return(dp[now][left]);
	
	unsigned int &ret=dp[now][left]=0;
	ret+=solve(now+1,left);
	if(left) ret+=solve(now+1,left-1);
	return(ret);
}

int main()
{
	freopen ("kimbits.in","r",stdin);
	freopen ("kimbits.out","w",stdout);
	scanf("%d %d %u",&N,&L,&I);
	
	memset(dp,-1,sizeof(dp));
	ans=solve(0,L);
	for(x=1;x<=N;x++) if(solve(x,L)>=I) printf("0"); else
	{
		I-=solve(x,L);
		printf("1");
		L--;
	}printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
