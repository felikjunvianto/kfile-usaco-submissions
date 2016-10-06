/*
	ID: felikju1
	PROG: bigmac
	LANG: C++
*/

#include <cstdio>
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

using namespace std;

int n,m,a,b,c,d;
int x,y,z,banyak;
bool kecil;
double v,cost,currency;
queue<pair<int,double> > jalur;
vector<pair<int,double> > adjlist[2010];
bool visited[2010][2010]={0};

int main()
{
	freopen ("bigmac.in","r",stdin);
	freopen ("bigmac.out","w",stdout);
	
	scanf("%d %d %lf %d %d",&n,&m,&v,&a,&b);
	jalur.push(mp(a,v));
	
	for(x=0;x<m;x++)
	{
		scanf("%d %d %lf",&c,&d,&currency);
		adjlist[c].pb(mp(d,currency));
	}
	
	kecil=false;
	banyak=0;
	
	do
	{
		if(jalur.front().fi==b)
		{
			banyak++;
			if(banyak==1) cost=jalur.front().se; else
			{
				if(jalur.front().se!=cost) kecil=true;
				cost=min(cost,jalur.front().se);
			}
		}
		
		a=jalur.front().fi;
		double harga=jalur.front().se;

		for(x=0;x<adjlist[a].size();x++) if(!visited[a][adjlist[a][x].fi])
		{
			visited[a][adjlist[a][x].fi]=true;
			jalur.push(mp(adjlist[a][x].fi,harga*adjlist[a][x].se));
		}
		jalur.pop();
	}while(!jalur.empty());
	
	if(!kecil) printf("0\n"); else printf("%.2f\n",cost);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
