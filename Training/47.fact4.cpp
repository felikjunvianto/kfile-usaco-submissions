/*
	ID: felikju1
	PROG: fact4
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

int N,temp,x,dua,lima;
int faktor[4250];

int main()
{
	freopen ("fact4.in","r",stdin);
	freopen ("fact4.out","w",stdout);
	
	faktor[0]=0;
	for(x=1;x<=4220;x++)
	{
		temp=x;
		lima=0;
		while(temp%5==0) {lima++;temp/=5;}
		
		faktor[x]=faktor[x-1]+lima;
	}
	
	scanf("%d",&N);
	dua=lima=faktor[N];
	temp=1;
	for(x=2;x<=N;x++) 
	{
		int now=x;
		while((dua)&&(now%2==0))
		{
			now/=2;
			dua--;
		}
		
		while((lima)&&(now%5==0))
		{
			now/=5;
			lima--;
		}
		
		temp=(temp*now)%10;
	}
	
	printf("%d\n",temp);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
