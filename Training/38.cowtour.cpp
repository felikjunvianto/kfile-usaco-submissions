/*
	ID: felikju1
	PROG: cowtour
	LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <cmath>
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

typedef struct
{
	int x,y,koloni;
} num;

int n,x,y,z;
num titik[160];
double dis[160][160],dia[160];
bool adjmat[160][160];
char masuk[160];
double huge=1e+20;
double min_dia,jarak1,jarak2;

void ff(int t)
{
	titik[t].koloni=z;
	for(int a=0;a<n;a++) if((adjmat[t][a])&&(titik[a].koloni==0)) ff(a);
}

int main()
{
	freopen ("cowtour.in","r",stdin);
	freopen ("cowtour.out","w",stdout);
	
	scanf("%d\n",&n);
	for(x=0;x<n;x++)
	{
		scanf("%d %d",&titik[x].x,&titik[x].y);
		titik[x].koloni=0;
	}
	
	for(y=0;y<n;y++)
	{
		scanf("%s",&masuk);
		for(x=0;x<n;x++) adjmat[x][y]=masuk[x]-'0';
	}
	
	z=0;
	for(x=0;x<n;x++) if(titik[x].koloni==0)
	{
		z++;
		ff(x);
	}

	for(y=0;y<n;y++)
		for(x=0;x<n;x++)
			if(x==y) dis[x][y]=0; else
				if((!adjmat[x][y])&&(titik[x].koloni==titik[y].koloni)) dis[x][y]=huge; else
					dis[x][y]=sqrt(pow((double)(titik[x].x-titik[y].x),2)+pow((double)(titik[x].y-titik[y].y),2));
	
	for(z=0;z<n;z++)
		for(x=0;x<n;x++)
			for(y=0;y<n;y++) if((titik[x].koloni==titik[z].koloni)&&(titik[z].koloni==titik[y].koloni))
				dis[x][y]=min(dis[x][y],dis[x][z]+dis[z][y]);
	
	for(x=0;x<n;x++) dia[x]=0;
	for(y=0;y<n-1;y++)
		for(x=y+1;x<n;x++) if(titik[x].koloni==titik[y].koloni)
			dia[titik[x].koloni]=max(dia[titik[x].koloni],dis[x][y]);
			
	min_dia=huge;
	for(x=0;x<n-1;x++)
		for(y=x+1;y<n;y++) if(titik[x].koloni!=titik[y].koloni)
		{
			jarak1=jarak2=0;
			for(z=0;z<n;z++) 
			{
				if(titik[x].koloni==titik[z].koloni) jarak1=max(jarak1,dis[x][z]);
				if(titik[y].koloni==titik[z].koloni) jarak2=max(jarak2,dis[y][z]);
			}
			
			double temp_min_dia=max(max(dia[titik[x].koloni],dia[titik[y].koloni]),dis[x][y]+jarak1+jarak2);
			min_dia=min(min_dia,temp_min_dia);
			//printf("%d %d %.6f %.6f %.6f %.6f %.6f %.6f\n",x+1,y+1,dis[x][y],jarak1,jarak2,dis[x][y]+jarak1+jarak2,temp_min_dia,min_dia);
		}
		
	printf("%.6f\n",min_dia);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
