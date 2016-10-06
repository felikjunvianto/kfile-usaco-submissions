/* 
	ID 	 : felikju1
	PROB : runround
	LANG : C++
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

bool ketemu,cek,lanjut;
long long digit[15]; 
long long masuk,x,y,z,data;

int main()
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	scanf("%lld",&data);
	ketemu=false;
	
	do
	{
		data++;
		masuk=data;
		int exp=1;
		int panjang=1;
		while(masuk/(exp*10)>0)
		{
			exp *= 10;
			panjang++;
		}
		
		int counter[15];
		memset(counter,0,sizeof(counter));
		for(x=panjang-1;x>=0;x--)
		{
			digit[x]=masuk%10;
			counter[masuk%10]++;
			masuk /= 10;
		}
		
		lanjut=true;
		for(x=0;x<10;x++) if(counter[x]>1)
		{
			lanjut=false;
			break;
		}
		
		if(lanjut)
		{
			bool udah[15];
			memset(udah,false,sizeof(udah));
			
			udah[0]=true;
			int next=0;
		
			bool temp=true;
			while(temp)
			{
				next=(next+digit[next])%panjang;
				if(udah[next]) 
				{
					temp=false;
					break;
				} 
				else
				{
					cek=true;
					udah[next]=true;
				
					for(x=0;x<panjang;x++) if(!udah[x])
					{
						cek=false;
						break;
					}
				}
		
				if(cek)
				{
					next=(next+digit[next])%panjang; // kembali ke digit awal;
					if(next==0) 
					{
						ketemu=true;
						temp=false;
					}
				}
			}
		}
	}while(!ketemu);
	printf("%lld\n",data);//cout << data << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
