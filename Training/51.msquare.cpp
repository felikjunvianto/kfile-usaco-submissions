/*
	ID: felikju1
	PROG: msquare
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

map<string,bool> vis;
string now,last,next,temp,ans;
int x,y,z;
queue<pair<string,string> > q;

int main()
{
	freopen ("msquare.in","r",stdin);
	freopen ("msquare.out","w",stdout);
	
	last=ans="";
	for(x=0;x<8;x++)
	{
		scanf("%d",&y);
		last+=y+'0';
	}
	q.push(mp("12345678",""));
	vis["12345678"]=true;
	
	while(!q.empty())
	{
		now=q.front().fi;
		temp=q.front().se;
		q.pop();
		
		if(now==last) 
		{
			ans=temp;
			break;
		} else
		{
			//conf A
			next=now;
			reverse(next.begin(),next.end());
			if(vis.find(next)==vis.end())
			{
				vis[next]=true;
				q.push(mp(next,temp+'A'));
			}
			
			//conf B
			next=now;
			char c=next[3];
			for(x=3;x>0;x--) next[x]=next[x-1];
			next[0]=c;
			
			c=next[4];
			for(x=4;x<7;x++) next[x]=next[x+1];
			next[7]=c;
			if(vis.find(next)==vis.end())
			{
				vis[next]=true;
				q.push(mp(next,temp+'B'));
			}
			
			//conf C
			next=now;
			swap(next[2],next[5]);
			swap(next[2],next[6]);
			swap(next[2],next[1]);
			if(vis.find(next)==vis.end())
			{
				vis[next]=true;
				q.push(mp(next,temp+'C'));
			}
		}
	}
	
	printf("%d\n",(int)ans.size());
	for(x=0;x<ans.size();x++)
	{
		printf("%c",ans[x]);
		if((x%60==59)&&(x+1<ans.size())) printf("\n");
	}printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
