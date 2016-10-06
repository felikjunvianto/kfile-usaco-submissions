/*
	ID: felikju1
	PROG: ttwo
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

typedef struct
{
	int x,y,arah;
} gerak;

int hor[]={0,1,0,-1};
int ver[]={-1,0,1,0};
int x,y,z,waktu,waktu_loop[2],total;
bool pos[2][15][15][5]={0};
bool loop[2],ketemu;
char peta[15][15],gps[2]={'C','F'};
gerak objek[2],temp_objek[2];//0 itu sapi,1 itu orang

int main()
{
	freopen ("ttwo.in","r",stdin);
	freopen ("ttwo.out","w",stdout);
	waktu=0;
	for(y=0;y<10;y++) 
	{
		scanf("%s",peta[y]);
		
		if(waktu<2) for(z=0;z<2;z++)
			for(x=0;x<10;x++) if(peta[y][x]==gps[z])
			{
				temp_objek[z].x=x;
				temp_objek[z].y=y;
				temp_objek[z].arah=0;
				peta[y][x]='.';
				waktu++;
			}
	}
	
	for(x=0;x<2;x++) 
	{
		objek[x]=temp_objek[x];
		waktu_loop[x]=0;
	
		while(1)
		{
			if(!pos[x][objek[x].x][objek[x].y][objek[x].arah]) pos[x][objek[x].x][objek[x].y][objek[x].arah]=true;
				else break;
			
			if((objek[x].y+ver[objek[x].arah]<0)||(objek[x].y+ver[objek[x].arah]>9)||
			   (objek[x].x+hor[objek[x].arah]<0)||(objek[x].x+hor[objek[x].arah]>9)||
			   (peta[objek[x].y+ver[objek[x].arah]][objek[x].x+hor[objek[x].arah]]=='*')) objek[x].arah=(objek[x].arah+1)%4; else
			   {
					objek[x].x+=hor[objek[x].arah];
					objek[x].y+=ver[objek[x].arah];
			   }
			waktu_loop[x]++;
		}
	}

	total=(waktu_loop[0]*waktu_loop[1])/__gcd(waktu_loop[0],waktu_loop[1]);

	waktu=0;
	for(x=0;x<2;x++) objek[x]=temp_objek[x];
	ketemu=false;
	while(waktu<=total)
	{
		//printf("%d %d %d %d %d %d %d\n",objek[0].x,objek[0].y,objek[0].arah,objek[1].x,objek[1].y,objek[1].arah,waktu);
		if((objek[0].x==objek[1].x)&&(objek[0].y==objek[1].y))
		{
			ketemu=true;
			break;
		}
			
		for(x=0;x<2;x++)
		{
			if((objek[x].y+ver[objek[x].arah]<0)||(objek[x].y+ver[objek[x].arah]>9)||
			   (objek[x].x+hor[objek[x].arah]<0)||(objek[x].x+hor[objek[x].arah]>9)||
			   (peta[objek[x].y+ver[objek[x].arah]][objek[x].x+hor[objek[x].arah]]=='*')) objek[x].arah=(objek[x].arah+1)%4; else
			   {
					objek[x].x+=hor[objek[x].arah];
					objek[x].y+=ver[objek[x].arah];
			   }
		}
		waktu++;
	}
	
	if(ketemu) printf("%d\n",waktu); else printf("0\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
