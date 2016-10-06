/*
	ID: felikju1
	PROG: ratios
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
#define PII pair<int,int> 
#define PDD pair<double,double> 
#define LL long long

using namespace std;

typedef struct
{
	int satu,dua,tiga;
} f;

f feed[3],jawab,akhir,temp;
int x,a,b,c,d,e;
bool ada;

int gcd(int n,int m)
{
	if((n==0)&&(m==0)) return(1);
	if(n==0) return(m);
	if(m==0) return(n);
	
	return(gcd(m,n%m));
}

int main()
{
	freopen ("ratios.in","r",stdin);
	freopen ("ratios.out","w",stdout);
	
	scanf("%d %d %d",&a,&b,&c);
	akhir=(f){a,b,c};
	for(x=0;x<3;x++) 
	{
		scanf("%d %d %d",&a,&b,&c);
		feed[x]=(f){a,b,c};
	}
	
	jawab=(f){1000,1000,1000};
	ada=false;
	for(a=0;a<=100;a++)
		for(b=0;b<=100;b++)
			for(c=0;c<=100;c++)
			{
				temp=(f){feed[0].satu*a+feed[1].satu*b+feed[2].satu*c,
						 feed[0].dua*a+feed[1].dua*b+feed[2].dua*c,
						 feed[0].tiga*a+feed[1].tiga*b+feed[2].tiga*c};

				for(d=1;d<=100;d++)
				if((temp.satu==akhir.satu*d)&&(temp.dua==akhir.dua*d)&&(temp.tiga==akhir.tiga*d))
				{
					ada=true;
					if(a+b+c<jawab.satu+jawab.dua+jawab.tiga) 
					{
						jawab=(f){a,b,c};
						e=d;
					}
					break;
				}
			}
			
	if(!ada) printf("NONE\n"); else printf("%d %d %d %d\n",jawab.satu,jawab.dua,jawab.tiga,e);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
