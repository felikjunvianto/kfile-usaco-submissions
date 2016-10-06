/*
PROG: countbead        
LANG: C++           
ID: felikju1
*/


#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int n,x,y,jumlah;
int bead[100];

int main()
{
	freopen("countbead.in","r",stdin);
	freopen("countbead.out","w",stdout);
	scanf("%d",&n);
	for(x=0;x<n;x++) scanf("%d",&bead[x]);
	
	jumlah=0;
	for(x=1;x<n;x++) if(bead[x]+bead[x-1]==1) jumlah++;
	printf("%d\n",jumlah);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

