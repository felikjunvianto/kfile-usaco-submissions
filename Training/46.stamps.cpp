/*
	ID: felikju1
	PROG: stamps
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
#define huge 1000000000;

using namespace std;

int batas=2000000;
int dp[2000100];
int cent[60];
int x,y,z,K,N;

int main()
{
	freopen ("stamps.in","r",stdin);
	freopen ("stamps.out","w",stdout);
	
	scanf("%d %d",&K,&N);
	for(x=0;x<N;x++) scanf("%d",&cent[x]);
	for(x=0;x<=batas;x++) dp[x]=huge;
	dp[0]=0;
	
	for(x=0;x<N;x++)
		for(y=cent[x];y<=batas;y++) dp[y]=min(dp[y],dp[y-cent[x]]+1);
	
	for(x=0;x<=batas+1;x++) if(dp[x]>K) break;
	printf("%d\n",x-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
