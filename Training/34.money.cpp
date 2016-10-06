/*
	PROG:money         
	LANG: C++           
	ID: felikju1
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int koin[30];
int v,n,x,y;
long long cara[10100];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d %d",&v,&n);
	for(x=0;x<v;x++) scanf("%d",&koin[x]);
	
	memset(cara,0,sizeof(cara));
	cara[0]=1;
	
	for(x=0;x<v;x++)
		for(y=0;y<=n-koin[x];y++) cara[y+koin[x]]+=cara[y];
		
	printf("%lld\n",cara[n]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

