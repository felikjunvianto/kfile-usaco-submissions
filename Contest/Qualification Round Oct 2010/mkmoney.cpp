/* 
	ID 	 : felikju1
	PROB : mkmoney
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

pair<int,int> barang[110];
int belanja[150000];
int t,x,y,z,m,n,sum;

int main()
{
	freopen("mkmoney.in","r",stdin);
	freopen("mkmoney.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(x=0;x<n;x++) 
	{
		scanf("%d %d",&barang[x].se,&barang[x].fi);
		barang[x].fi-=barang[x].se;
	}
	
	memset(belanja,0,sizeof(belanja));
	
	for(x=0;x<n;x++) belanja[barang[x].se]=barang[x].fi;
	for(x=0;x<n;x++)
	{
		for(y=barang[x].se;y<=m;y++) if(belanja[y-barang[x].se]>0)
		{
			if((belanja[y-barang[x].se]+barang[x].fi)>belanja[y])
				belanja[y]=belanja[y-barang[x].se]+barang[x].fi;
		}
	}
	
	int maks=0;
	for(x=0;x<=m;x++) if(belanja[x]+m-x>maks) maks=belanja[x]+m-x;
	cout << maks << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
