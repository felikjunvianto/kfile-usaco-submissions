/*
	ID: felikju1
	PROG: range
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

int N,x,y,z,cnt,now,last;
bool dp[2][260][260];
char msk[300];

int main()
{
	freopen ("range.in","r",stdin);
	freopen ("range.out","w",stdout);
	
	scanf("%d",&N);
	for(y=1;y<=N;y++)
	{
		scanf("%s",msk);
		for(x=0;x<N;x++) dp[1][x+1][y]=msk[x]-'0';
	}
	
	for(z=2;z<=N;z++)
	{
		now=z&1;
		last=1-now;
		memset(dp[now],false,sizeof(dp[now]));
		
		cnt=0;
		for(x=1;x+z-1<=N;x++)
			for(y=1;y+z-1<=N;y++)
				if((dp[last][x][y])&&(dp[last][x+1][y])&&(dp[last][x][y+1])&&(dp[last][x+1][y+1]))
					{
						dp[now][x][y]=true;
						cnt++;
					}	
		if(cnt) printf("%d %d\n",z,cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
