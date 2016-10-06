/*
	ID: felikju1
	TASK: fence9
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

const string filename = "fence9"; //fill this with your filename

int n, m, p;
int area, edgePoint, ans;

int main()
{
	freopen((char*)(filename + ".in").c_str(), "r", stdin);
	freopen((char*)(filename + ".out").c_str(), "w", stdout);
	
	scanf("%d %d %d",&n, &m, &p);
	area = m * p * 0.5;
	edgePoint = 0;
	
	//counting number of lattice points from (0,0) to (n,m)
	edgePoint += __gcd(n,m) + 1;
	
	//counting number of lattice points from (n,m) to (p,0)
	edgePoint += __gcd(abs(n-p),m) + 1;
	
	//counting number of lattice points from (p,0) to (0,0)
	edgePoint += p + 1;
	
	//subtracts number of duplicate points {(0,0), (n,m), (p,0)}
	edgePoint -= 3;

	//using Pick's Theorem to find number of lattice point INSIDE region
	ans = area - edgePoint/2 + 1;
	
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
