/*
	ID: felikju1
	PROG: gdisc
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

int N,a,b,ans;
bool adjmat[50][50];

int main()
{
	scanf("%d",&N);getchar();
	
	for(a=1;a<=N;a++)
		for(b=1;b<=N;b++) (a==b?adjmat[a][b]=0:adjmat[a][b]=1);
		
	for(a=1;a<=N;a++)
		for(b=a;b<=N;b++) if(adjmat[a][b])
		{
			printf("R %d %d\n",a,b);fflush(stdout);
			printf("Q\n");fflush(stdout);
			scanf("%d",&ans);
			
			if(ans) adjmat[a][b]=adjmat[b][a]=0; else
			{
				printf("U %d %d\n",a,b);
				fflush(stdout);
			}
		}
		
	printf("A\n");fflush(stdout);
	for(a=1;a<=N;a++)
	{
		for(b=1;b<=N;b++)
		{
			printf("%d",adjmat[a][b]);
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
	}
	return 0;
}
