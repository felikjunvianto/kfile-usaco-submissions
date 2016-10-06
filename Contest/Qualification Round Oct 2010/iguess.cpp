/*
PROG: iguess     
LANG: C++           
ID: felikju1
*/


#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

long long kiri,kanan,hasil;
char judge;

int main()
{
	cin >> kanan;
	kiri=1;
	
	while(1)
	{
		hasil=(long long)(kiri+kanan)/2;
		cout << hasil << endl;
		cout << flush;
		
		cin >> judge;
		switch(judge)
		{
			case('L') : kiri=hasil+1;break;
			case('H') : kanan=hasil-1;break;
		}
	}
	return 0;
}

