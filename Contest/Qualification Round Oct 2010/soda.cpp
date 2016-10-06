/* 
	ID 	 : felikju1
	PROB : soda
	LANG : C++
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>

#define fi first
#define se second

using namespace std;

pair <int,string> sapi[110000];
int t,n,x,y,z,hitung,maks,temp;

int main()
{
	freopen("soda.in","r",stdin);
	freopen("soda.out","w",stdout);
	
	scanf("%d",&t);
	x=-1;
	while(t--)
	{
		x++;
		scanf("%d",&sapi[x].fi);
		sapi[x].se="begin";
		
		x++;
		scanf("%d",&sapi[x].fi);
		sapi[x].se="end";
	}
	x++;
	
	sort(sapi,sapi+x);
	
	maks=0;
	temp=0;
	hitung=0;
	
	for(y=0;y<x;y++)
	{
		switch(sapi[y].se[0])
		{
			case('b') : hitung++;
						if(temp<hitung) temp++;
						break;
			case('e') : hitung--;
						break;
		}
		
		if(hitung==0)
		{
			if(temp>maks) maks=temp;
			temp=0;
		}
	}
	
	printf("%d\n",maks);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
