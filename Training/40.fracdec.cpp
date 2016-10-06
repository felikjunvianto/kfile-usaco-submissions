/*
	ID: felikju1
	PROG: fracdec
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
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

int n,d,x,y,z,temp;
string hasil;
vector<pair<int, int> > sisa;
map<int,int> cek;
char bagi[1000];
bool ada,berulang;

int main()
{
	freopen ("fracdec.in","r",stdin);
	freopen ("fracdec.out","w",stdout);
	scanf("%d %d",&n,&d);
	temp=n/d;
	n%=d;
	sprintf(bagi,"%d",temp);
	hasil=bagi;
	hasil+='.';
	sisa.pb(mp(n,-1));
	
	ada=false;
	do
	{
		temp=(n*10)/d;
		sisa[sisa.size()-1].se=temp;
		n=(n*10)%d;
		if(n==0) break;
		
		if(cek.find(sisa[sisa.size()-1].fi)!=cek.end())
		{
			ada=true;
			berulang=true;
		} else cek[sisa[sisa.size()-1].fi]=1;
		
		if (ada) 
		{
			for(z=0;z<sisa.size();z++) if(sisa[sisa.size()-1].fi==sisa[z].fi) break;
		} else sisa.pb(mp(n,-1));
	}while(!ada);
	
	for(x=0;x<z;x++) hasil+=sisa[x].se+'0';
	if(berulang) hasil+='(';
	for(x=z;x<sisa.size();x++) hasil+=sisa[x].se+'0';
	if(berulang) 
	{
		hasil.erase(hasil.size()-1,1);
		hasil+=')';	
	}
	
	y=0;
	for(x=0;x<hasil.size();x++)
	{
		y++;
		printf("%c",hasil[x]);
		if(y==76) 
		{
			printf("\n");
			y=0;
		}
	}
	
	if(hasil.size()%76!=0) printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
