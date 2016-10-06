/*
	ID: felikju1
	PROG: prefix
	LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string pref[210];
string kata,temp;
int dp[200100];
int x,length,banyak;

bool depan(int x,int indeks)
{
	if(indeks+pref[x].size()-1>length) return(false); else
	{
		int y;
		for(y=0;y<pref[x].size();y++) if(kata[indeks+y]!=pref[x][y])
			return(false);
			
		return(true);
	}
}

int panjang(int indeks)
{
	if(dp[indeks]==-1) if(indeks>=length) dp[indeks]=0;else
	{
		int x;
		dp[indeks]=0;
		for(x=0;x<banyak;x++) if(depan(x,indeks))
		{
			int temp=pref[x].size()+panjang(indeks+pref[x].size());
			dp[indeks] = max(dp[indeks],temp);
		}
	}
	return(dp[indeks]);
}

int main()
{
	freopen ("prefix.in","r",stdin);
	freopen ("prefix.out","w",stdout);
	
	banyak=-1;
	do
	{
		banyak++;
		cin >> pref[banyak];
	}while(pref[banyak]!=".");
	
	kata="";
	while(cin >> temp) kata += temp;
	length=kata.size();
	
	memset(dp,-1,sizeof(dp));

	printf("%d\n",panjang(0));
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
