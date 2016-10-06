/*
	ID: felikju1
	PROG: nocows
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

using namespace std;

int tinggimin[250];
int dp[300][300];
int n,k,x,y,z,height,kiri,kanan;
int batas=9901;

int main()
{
	freopen ("nocows.in","r",stdin);
	freopen ("nocows.out","w",stdout);
	
	scanf("%d %d",&n,&k);
	for(x=1;x<=200;x++) tinggimin[x]=(int)floor(log10(x)/log10(2));
	
	if(n%2==0) printf("0\n"); else
	{
		memset(dp,0,sizeof(dp));
		dp[1][1]=1;
		
		for(x=3;x<=n;x+=2)
			for(height=tinggimin[x];2*height-1<=x;height++)
			{
				//printf("%d %d\n",x,height);
				
				for(y=1;y<=height-1;y++)
					for(kiri=1;kiri<=x-1;kiri+=2)
					{
						kanan=x-1-kiri;
						int temp=(dp[kiri][y]*dp[kanan][height-1])%batas;
						if((!((kiri==kanan)&&(y==height-1)))&&(y!=height-1)) temp=(temp*2)%batas;
						dp[x][height]+=temp;
						dp[x][height]%=batas;
						//cout << "memanggil " << kiri <<"," << y<<"("<<dp[kiri][y]<<") "
						//	  <<kanan<<","<<height-1<<"("<<dp[kanan][height-1]<<") = "<<temp<<endl;
					}
					
				
				//for(y=1;y<=k;y++)
				//{
				//	for(z=1;z<=n;z++) cout << dp[z][y] << " ";
				//	cout << endl;
				//}
				//cout << dp[x][height] << endl;
				//cout << endl;
			}
		printf("%d\n",dp[n][k]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
