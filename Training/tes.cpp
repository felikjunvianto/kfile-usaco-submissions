#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const char* haha = "Hello";

int main(int cargv, char* argv[])
{
	int len = strlen(haha);
	for(int i = 0; i < len; i++) printf("%c\n", *(haha + i));
	return 0;
	
	int start, reg;
	sscanf(argv[1], "%d", &start);
	sscanf(argv[2], "%d", &reg);

	int cnt = 0;
	for(int a = start; cnt < reg; a++)
	{
		bool prima = true;
		for(int i = 2; i * i <= a && prima; i++) if(a % i == 0) prima = false;
		if(prima)
		{
			printf("%d\n", a);
			cnt++;
		}
	}
}