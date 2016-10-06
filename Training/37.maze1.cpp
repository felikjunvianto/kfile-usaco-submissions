/*
	ID: felikju1
	PROG: maze1
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

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

int bawah,samping,x,y,z,kamar,ver,hor,maks;
char peta[300][300];
char masuk[300];
bool visited[4000]={0};
vector<int> adjlist[4000];
queue<pair<int,int> > node;

int main()
{
	freopen ("maze1.in","r",stdin);
	freopen ("maze1.out","w",stdout);
	scanf("%d %d\n",&samping,&bawah);
	
	for(y=0;y<2*bawah+1;y++)
	{
		gets(masuk);
		for(x=0;x<2*samping+1;x++) peta[x][y]=masuk[x];
	}
	
	for(y=1;y<=2*bawah-1;y+=2)
		for(x=1;x<=2*samping-1;x+=2)
		{
			kamar=((y-1)/2)*samping+((x+1)/2);
			for(ver=-1;ver<=1;ver++)
				for(hor=-1;hor<=1;hor++)
					if(((ver==0)^(hor==0))&&(peta[x+hor][y+ver]==' '))
						if((x+hor==0)||(x+hor==2*samping)||(y+ver==0)||(y+ver==2*bawah))
						{
							node.push(mp(kamar,1));
							visited[kamar]=true;
						} else adjlist[kamar].pb(kamar+hor+ver*samping);
		}
		
	maks=0;
	while(!node.empty())
	{
		maks=max(maks,node.front().se);
		for(x=0;x<adjlist[node.front().fi].size();x++) if(!visited[adjlist[node.front().fi][x]])
		{
			visited[adjlist[node.front().fi][x]]=true;
			node.push(mp(adjlist[node.front().fi][x],node.front().se+1));
		}
		node.pop();
	}
	printf("%d\n",maks);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
