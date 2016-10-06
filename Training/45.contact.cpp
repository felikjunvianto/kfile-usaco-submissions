/*
	ID: felikju1
	PROG: contact
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
#define pi acos(-1.0)
#define eps 1e-9

using namespace std;

int A,B,N,x,y,z;
int duapk[15];
string total;
char baca[110];
map<string,int> indeks;
vector<pair<int,string> > ans;

int deci(string i)
{
	int hasil=0,panjang=i.size();
	for(int x=0;x<panjang;x++) hasil+=(i[x]-'0')*duapk[panjang-x-1];
	return(hasil);
}

bool cf(pair<int,string> a,pair<int,string> b)
{
	if(a.fi!=b.fi) return(a.fi>b.fi);
	if(a.se.size()!=b.se.size()) return(a.se.size()<b.se.size());
	return(deci(a.se)<deci(b.se));
}

int main()
{
	freopen ("contact.in","r",stdin);
	freopen ("contact.out","w",stdout);
	
	duapk[0]=1;
	for(x=1;x<15;x++) duapk[x]=duapk[x-1]*2;
	
	scanf("%d %d %d",&A,&B,&N);
	total="";
	while(scanf("%s",baca)!=EOF) total+=baca;
	
	for(x=A;x<=B;x++)
		for(y=0;y+x-1<total.size();y++)
		{
			string temp=total.substr(y,x);
			if(indeks.find(temp)==indeks.end()) indeks[temp]=1; 
				else indeks[temp]++;
		}
		
	for(map<string,int> :: iterator m=indeks.begin();m!=indeks.end();m++)
		ans.pb(mp(m->se,m->fi));
		
	sort(ans.begin(),ans.end(),cf);
	
	x=-1;
	do
	{
		x++;
		y=x+1;
		while((ans[x].fi==ans[y].fi)&&(y<ans.size())) y++;y--;
		
		printf("%d\n",ans[x].fi);
		for(z=x;z<=y;z++) 
		{
			printf("%s",ans[z].se.c_str());
			if(((z-x+1)%6==0)||(z==y)) printf("\n");
				else printf(" ");
		}
		x=y;
		N--;
	}while((x+1<ans.size())&&(N));
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
