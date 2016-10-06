/*
	ID: felikju1
	PROG: inflate
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

int dp[10100]={0};
int m,n,x,y,z;
int waktu,nilai;

int main()
{
	freopen ("inflate.in","r",stdin);
	freopen ("inflate.out","w",stdout);
	scanf("%d %d",&m,&n);
	while(n--)
	{
		scanf("%d %d",&nilai,&waktu);
		for(x=waktu;x<=m;x++) dp[x]=max(dp[x],dp[x-waktu]+nilai);
	}
	
	printf("%d\n",dp[m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
