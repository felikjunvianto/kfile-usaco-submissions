/*
PROG: lkcount      
LANG: C++           
ID: felikju1
*/


#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

char peta[150][150];
int bawah,samping;
int jumlah,x,y;

void danau(int x, int y)
{
	int ver,hor;
	peta[x][y]='.';
	
	for(ver=-1;ver<=1;ver++)
		for(hor=-1;hor<=1;hor++)
			if(!((ver==0)&&(hor==0)))
				if((x+hor>=1)&&(x+hor<=samping)&&(y+ver>=1)&&(y+ver<=bawah))
					if(peta[x+hor][y+ver]=='W') danau(x+hor,y+ver);
	return;
}

int main()
{
	freopen("lkcount.in","r",stdin);
	freopen("lkcount.out","w",stdout);
	
	scanf("%d %d",&bawah,&samping);
	memset(peta,'.',sizeof(peta));
	for(y=1;y<=bawah;y++)
		for(x=1;x<=samping;x++) cin >> peta[x][y];
	
	jumlah=0;
	
	for(y=1;y<=bawah;y++)
		for(x=1;x<=samping;x++) if(peta[x][y]=='W')
		{	
			jumlah++;
			danau(x,y);
		}

	cout << jumlah << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

