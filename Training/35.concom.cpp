/*
	ID: felikju1
	PROG: concom
	LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int n,x,y,z,i,j,k,banyak;
int com[110][110];

void kuasa(int x,int y)
{
	if(x==y) return;
	int z;
	for(z=1;z<=100;z++) if((z!=x)&&(z!=y)&&(com[x][z]<=50))
	{
		com[x][z]+=com[y][z];
		if(com[x][z]>50) kuasa(x,z);
	}
	return;
}

int main()
{
	freopen ("concom.in","r",stdin);
	freopen ("concom.out","w",stdout);
	
	scanf("%d",&n);

	while(n--)
	{
		scanf("%d %d %d",&i,&j,&k);
		com[i][j]=k;
	}
	
	for(x=1;x<=100;x++) 
		for(y=1;y<=100;y++) if((x!=y)&&(com[x][y]>50)) kuasa(x,y);
	/*	
	for(x=1;x<=100;x++)
	{
		cout << x << " ";
		for(y=1;y<=100;y++) cout << com[x][y] << " ";
		cout << endl;
	}*/
			
	for(x=1;x<=100;x++) 
		for(y=1;y<=100;y++) if((com[x][y]>50)&&(x!=y)) printf("%d %d\n",x,y);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
