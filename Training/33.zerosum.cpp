/*
	ID: felikju1
	PROG: zerosum
	LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int n,x,y,z,batas;
string tanda,operasi;

string digit(int x)
{
	string kata="";
	while(x>0)
	{
		kata=char((x%3)+'0')+kata;
		x/=3;
	}
	
	if(kata.size()<n-1)
	{
		int panjang=kata.size();
		int y;
		for(y=1;y<=n-1-panjang;y++) kata='0'+kata;
	}
	return(kata);
}

int hasil(string operasi)
{
	string temp="";
	int panjang=operasi.size();
	int x;
	for(x=0;x<panjang;x++) if(operasi[x]!= ' ') temp+=operasi[x];
	temp='+'+temp+'e';
	panjang=temp.size();
	char tanda=' ';
	int final=0;
	int masuk=0;
	
	for(x=0;x<panjang;x++) if((temp[x]>='1')&&(temp[x]<='9')) masuk=masuk*10+(temp[x]-'0'); else
	{
		switch(tanda)
		{
			case('+') : final+=masuk;break;
			case('-') : final-=masuk;break;
			default : break;
		}
		tanda=temp[x];
		masuk=0;
	}
	return(final);
}

int main()
{
	freopen ("zerosum.in","r",stdin);
	freopen ("zerosum.out","w",stdout);
	
	scanf("%d",&n);
	batas=1;
	for(x=1;x<n;x++) batas*=3;
	//cout << batas << endl;
	
	for(x=0;x<batas;x++) 
	{
		//cout << digit(x) << endl;
		tanda=digit(x);
		operasi="1";
		for(y=0;y<n-1;y++) 
			switch(tanda[y])
			{
				case('0') : operasi=operasi+" "+(char)(y+2+'0');break;
				case('1') : operasi=operasi+"+"+(char)(y+2+'0');break;
				case('2') : operasi=operasi+"-"+(char)(y+2+'0');break;
			}
		if(hasil(operasi)==0) cout << operasi << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
