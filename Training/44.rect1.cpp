/*
	ID: felikju1
	PROG: rect1
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

typedef struct {int xa,ya,xb,yb,warna;} kotak;
vector<kotak> box[2];
int total[2600];
kotak baru,potongan;
int x,y,T,now,next;

int main()
{
	freopen ("rect1.in","r",stdin);
	freopen ("rect1.out","w",stdout);
	scanf("%d %d %d",&x,&y,&T);
	now=0;
	box[now].pb((kotak){0,y,x,0,1});
	while(T--)
	{
		next=now^1;
		box[next].clear();
		scanf("%d %d %d %d %d",&baru.xa,&baru.yb,&baru.xb,&baru.ya,&baru.warna);
		box[next].pb(baru);
		
		for(x=0;x<box[now].size();x++)
		{
			potongan.xa=max(box[now][x].xa,baru.xa);
			potongan.ya=min(box[now][x].ya,baru.ya);
			potongan.xb=min(box[now][x].xb,baru.xb);
			potongan.yb=max(box[now][x].yb,baru.yb);
			
			if((potongan.xa<potongan.xb)&&(potongan.ya>potongan.yb))
			{
				if(box[now][x].xa<baru.xa) box[next].pb((kotak){box[now][x].xa,box[now][x].ya,baru.xa,box[now][x].yb,box[now][x].warna});
				if(box[now][x].xb>baru.xb) box[next].pb((kotak){baru.xb,box[now][x].ya,box[now][x].xb,box[now][x].yb,box[now][x].warna});
				if(box[now][x].ya>baru.ya) box[next].pb((kotak){potongan.xa,box[now][x].ya,potongan.xb,baru.ya,box[now][x].warna});
				if(box[now][x].yb<baru.yb) box[next].pb((kotak){potongan.xa,baru.yb,potongan.xb,box[now][x].yb,box[now][x].warna});
			} else box[next].pb(box[now][x]);
		}
		now=next;
	}
	
	memset(total,0,sizeof(total));
	for(x=0;x<box[now].size();x++)
	{
		int indeks=box[now][x].warna;
		total[indeks]+=(box[now][x].xb-box[now][x].xa)*(box[now][x].ya-box[now][x].yb);
	}
	
	for(x=1;x<=2500;x++) if(total[x]>0) printf("%d %d\n",x,total[x]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
