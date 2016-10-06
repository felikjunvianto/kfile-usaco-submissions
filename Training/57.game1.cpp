/*
	ID: felikju1
	PROG: game1
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

int N,x,y,z,sum;
int arr[210];
int dp[210][210];

int solve(int l,int r)
{
	if(l==r) return(arr[l]);
	if(dp[l][r]!=-1) return(dp[l][r]);
	
	int &ret = dp[l][r];
	ret= max(arr[l]-solve(l+1,r),arr[r]-solve(l,r-1));
	return(ret);
}

int main()
{
	freopen ("game1.in","r",stdin);
	freopen ("game1.out","w",stdout);
	
	scanf("%d",&N);
	sum=0;
	for(x=1;x<=N;x++)
	{
		scanf("%d",&arr[x]);
		sum+=arr[x];
	}
	
	memset(dp,-1,sizeof(dp));
	z=solve(1,N);
	printf("%d %d\n",(z+sum)/2,(sum-z)/2);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
