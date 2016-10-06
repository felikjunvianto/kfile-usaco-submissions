/*
	ID: felikju1
	PROG: comehome
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

bool visited[60];
int dis[60];
vector<pair<int,int> > adjlist[60];
int x,y,z,n,mini,cost,satu,dua;
int huge=2000000000;
char node1[2],node2[2];
priority_queue <pair<int,int> > node;

void djikstra()
{
	while(!node.empty())
	{
		int x;
		int now=-node.top().se;
		int jarak =-node.top().fi;
		node.pop();

		if(!visited[now])
		{
			visited[now]=true;
			dis[now]=jarak;
			for(x=0;x<adjlist[now].size();x++) if(!visited[adjlist[now][x].se])
				node.push(mp(-(dis[now]+adjlist[now][x].fi),-adjlist[now][x].se));
		}
	}
}

int main()
{
	freopen ("comehome.in","r",stdin);
	freopen ("comehome.out","w",stdout);
	
	scanf("%d",&n);
	for(x=0;x<n;x++)
	{
		scanf("%s %s %d",&node1,&node2,&cost);
		
		if((node1[0]>='A')&&(node1[0]<='Z')) satu=node1[0]-'A'; else satu=node1[0]-'a'+26;
		if((node2[0]>='A')&&(node2[0]<='Z')) dua=node2[0]-'A'; else dua=node2[0]-'a'+26;
		
		adjlist[satu].pb(mp(cost,dua));
		adjlist[dua].pb(mp(cost,satu));
	}
	
	memset(visited,false,sizeof(visited));
	node.push(mp(0,-25));
	for(x=0;x<60;x++) dis[x]=huge;
	dis[25]=0;
	djikstra();
	
	mini=huge;
	int nearest=26;
	for(x=0;x<25;x++) if(dis[x]<mini)
	{
		nearest=x;
		mini=dis[x];
	}
	printf("%c %d\n",nearest+'A',mini);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
