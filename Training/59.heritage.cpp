/*
	ID: felikju1
	TASK: heritage
	LANG: C++
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define INF 1000000000
#define eps 1e-9
#define PII pair<int,int> 

using namespace std;

const string filename = "heritage"; //fill this with your filename

char inord[30], preord[30];
PII child[30]; // first = left, second = right

void findTree(string pre, string in)
{
	int root;
	for(root = 0; root < in.size(); root++) if(in[root] == pre[0]) break;
		
	if(root > 0) 
	{
		child[pre[0] - 'A'].fi = pre[1] - 'A';
		findTree(pre.substr(1, root), in.substr(0, root));
	}
	
	if(root + 1 < in.size()) 
	{
		child[pre[0] - 'A'].se = pre[root + 1] - 'A';
		findTree(pre.substr(root + 1), in.substr(root + 1));
	}
}

void getPostOrder(int now)
{
	if(child[now].fi != -1) getPostOrder(child[now].fi);
	if(child[now].se != -1) getPostOrder(child[now].se);
	printf("%c",now + 'A');
}

int main()
{
	freopen((char*)(filename + ".in").c_str(), "r", stdin);
	freopen((char*)(filename + ".out").c_str(), "w", stdout);
	
	scanf("%s",inord);
	scanf("%s",preord);
	for(int i = 0; i < 26; i++) child[i] = mp(-1,-1);
	
	findTree(preord, inord);
	getPostOrder(preord[0] - 'A');
	printf("\n");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
