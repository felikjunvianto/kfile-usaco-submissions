/*
	ID: felikju1
	PROG: rockers
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

int N, T, M;
int dp[30][30][30];
int song[30];

int solve(int nowSong, int nowDisc, int timeLeft)
{
	if(nowSong == N+1 || nowDisc == M+1) return 0;
	if(dp[nowSong][nowDisc][timeLeft] != -1) return dp[nowSong][nowDisc][timeLeft];
	
	int &ret = dp[nowSong][nowDisc][timeLeft] = 0;
	
	//option 1: include song in current disc (if it's fit)
	if(timeLeft >= song[nowSong]) ret = max(ret, solve(nowSong + 1, nowDisc, timeLeft - song[nowSong]) + 1);
	
	//option 2: skip current song 
	ret = max(ret, solve(nowSong + 1, nowDisc, timeLeft));
	
	//option 3: change to new disc
	ret = max(ret, solve(nowSong, nowDisc + 1, T));
	
	return ret;
}

int main()
{
	freopen ("rockers.in","r",stdin);
	freopen ("rockers.out","w",stdout);
	
	scanf("%d %d %d",&N, &T, &M);
	for(int i = 1; i <= N; i++) scanf("%d",&song[i]);
	
	memset(dp,-1,sizeof(dp));
	printf("%d\n",solve(1,1,T));
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
