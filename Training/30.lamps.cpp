/*
	ID: felikju1
	PROG: lamps
	LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string kunci[2][8] = {{"00000","20011","20101","20110","21001","21010","21100","41111"},
				      {"10001","10010","10100","30111","11000","31011","31110","11111"}};
string list[20],temp;
int final[150];
bool lampu[150],cocok,ada;
int x,y,z,n,c,panjang,pos,basis;

int main()
{
	freopen ("lamps.in","r",stdin);
	freopen ("lamps.out","w",stdout);
	
	scanf("%d",&n);
	scanf("%d",&c);
	memset(final,-1,sizeof(final));
	
	do
	{
		scanf("%d",&x);
		if(x==-1) break;
		final[x]=1;
	}while(x!=-1);
	
	do
	{
		scanf("%d",&x);
		if(x==-1) break;
		final[x]=0;
	}while(x!=-1);
	
	panjang=-1;
	if(c%2==1) //odd
	{
		pos=7;
		basis=1;
	} else //even
	
	{
		pos=8;
		basis=0;
	}
	
	ada=false;
	for(x=0;x<pos;x++) if((kunci[basis][x][0]-'0')<=c)
	{	
		memset(lampu,true,sizeof(lampu));
		for(y=1;y<=4;y++) if(kunci[basis][x][y]-'0')
		{
			switch(y)
			{	
				case(1) : for(z=1;z<=n;z++) lampu[z]^=1;break;
				case(2) : for(z=1;z<=n;z+=2) lampu[z]^=1;break;
				case(3) : for(z=2;z<=n;z+=2) lampu[z]^=1;break;
				case(4) : for(z=0;(3*z+1)<=n;z++) lampu[3*z+1]^=1;break;
			}
		}
		//for(y=1;y<=n;y++) cout << lampu[y];
	
		cocok=true;
		for(y=1;y<=n;y++) if((final[y]!=-1)&&(final[y]!=lampu[y]))
		{
			cocok=false;
			break;
		}
		//cout << " " << cocok << endl;
	
		if(cocok)
		{
			ada=true;
			panjang++;
			list[panjang]="";
			for(y=1;y<=n;y++) list[panjang]+=(char)(lampu[y]+'0');
		}
	}
	
	if(!ada) printf("IMPOSSIBLE\n"); else
	{
		sort(list,list+panjang+1);
		for(x=0;x<=panjang;x++) cout << list[x] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
