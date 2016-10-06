/*
	ID: felikju1
	PROG: camelot
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
#define INF 1000000000
#define PII pair<int,int> 
#define PDD pair<double,double> 
#define LL long long

using namespace std;

int kx[]={ 2, 1,-1,-2,-2,-1, 1, 2};
int ky[]={ 1, 2, 2, 1,-1,-2,-2,-1};

int rx[]={ 1, 1, 0,-1,-1,-1, 0, 1};
int ry[]={ 0,-1,-1,-1, 0, 1, 1, 1};

PII king;
int N,bawah,samping,x,y,z;
int kni[800][35][35];
int jarak[35][35][35][35];
int raja[35][35];
char msk[3];
queue<PII> q;

int main()
{
	freopen ("camelot.in","r",stdin);
	freopen ("camelot.out","w",stdout);
	
	scanf("%d %d",&bawah,&samping);
	scanf("%s %d",msk,&y);
	king=mp(msk[0]-'A'+1,y);
	
	for(int a=1;a<=samping;a++) //precompute jarak
		for(int b=1;b<=bawah;b++)
		{
			memset(jarak[a][b],-1,sizeof(jarak[a][b]));
			q.push(mp(a,b));
			jarak[a][b][a][b]=0;
			while(!q.empty())
			{
				x=q.front().fi,y=q.front().se;
				q.pop();
			
				for(z=0;z<8;z++)
				{
					int sx=x+kx[z],sy=y+ky[z];
					if((sx>=1)&&(sx<=samping)&&(sy>=1)&&(sy<=bawah)&&(jarak[a][b][sx][sy]==-1))
					{
						jarak[a][b][sx][sy]=jarak[a][b][x][y]+1;
						q.push(mp(sx,sy));
					}
				}
			}
		}
		
	N=0;
	while(scanf("%s %d",msk,&y)!=EOF)
	{
		memset(kni[N],-1,sizeof(kni[N]));
		q.push(mp(msk[0]-'A'+1,y));
		kni[N][msk[0]-'A'+1][y]=0;
		
		while(!q.empty())
		{
			x=q.front().fi,y=q.front().se;
			q.pop();
			
			for(z=0;z<8;z++)
			{
				int sx=x+kx[z],sy=y+ky[z];
				if((sx>=1)&&(sx<=samping)&&(sy>=1)&&(sy<=bawah)&&(kni[N][sx][sy]==-1))
				{
					kni[N][sx][sy]=kni[N][x][y]+1;
					q.push(mp(sx,sy));
				}
			}
		}
		N++;
	}
	
	if(!N) //no knight
	{
		printf("0\n");
		return 0;
	}
	
	int ans=INF,temp;
	for(y=1;y<=bawah;y++)
		for(x=1;x<=samping;x++) 
		{
			temp=0;
			bool oke=true;
			for(z=0;z<N;z++) if(kni[z][x][y]!=-1) temp+=kni[z][x][y]; else oke=false;
			if(!oke) continue;
			
			
			memset(raja,-1,sizeof(raja));
			while(!q.empty()) q.pop();
			raja[king.fi][king.se]=0;
			q.push(king);
			
			while(!q.empty())
			{
				int xx=q.front().fi,yy=q.front().se;
				q.pop();
				
				bool dapat=false;
				if((xx==x)&&(yy==y)) dapat=true; //nyampe
				for(z=0;(z<N)&&(!dapat);z++) 
					if((kni[z][xx][yy]!=-1)&&(kni[z][xx][yy]<kni[z][x][y]))
						if(jarak[x][y][xx][yy]+kni[z][xx][yy]==kni[z][x][y]) dapat=true;
						
				if(dapat) //nyampe ato nebeng knight
				{
					temp+=raja[xx][yy];
					break;
				}
				
				for(z=0;z<8;z++)
				{
					int sx=xx+rx[z],sy=yy+ry[z];
					if((sx>=1)&&(sx<=samping)&&(sy>=1)&&(sy<=bawah)&&(raja[sx][sy]==-1))
					{
						raja[sx][sy]=raja[xx][yy]+1;
						q.push(mp(sx,sy));
					}
				}
			}
			//cout << x << " " << y << " " << temp << endl;
			ans=min(ans,temp);
		}
		
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
