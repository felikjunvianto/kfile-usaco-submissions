/*
	ID: felikju1
	PROG: fence4
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
#define INF 1000000000

using namespace std;

int N, i, j, k;
PII pos, p[222];

map<PII,int> idx;
vector<pair<PII,PII> > seen;

int ccwTest(PII p, PII q, PII r)
{
	int temp = p.fi*(q.se-r.se)+q.fi*(r.se-p.se)+r.fi*(p.se-q.se);
	if(temp < 0) return -1;
	if(temp > 0) return 1;
	return 0;
}

int ccwTest(PII p, PII q, PDD r)
{
	double temp = (double) (p.fi*(q.se-r.se)+q.fi*(r.se-p.se)+r.fi*(p.se-q.se));
	if(temp < 0) return -1;
	if(temp > 0) return 1;
	return 0;
}

bool isIntersect(PII p1, PII p2, PII q1, PII q2)
{
	int qtop1 = ccwTest(q1, q2, p1), qtop2 = ccwTest(q1, q2, p2);
	int ptoq1 = ccwTest(p1, p2, q1), ptoq2 = ccwTest(p1, p2, q2);
	
	if(!qtop1 || !qtop2 || !ptoq1 || !ptoq2) return false;
	if(qtop1 != qtop2 && ptoq1 != ptoq2) return true;
	return false;
}

bool isIntersect(PII p1, PDD p2, PII q1, PII q2)
{
	int qtop1 = ccwTest(q1, q2, p1), qtop2 = ccwTest(q1, q2, p2);
	int ptoq1 = ccwTest(q1, p1, p2), ptoq2 = ccwTest(q2, p1, p2);
	
	if(!qtop1 || !qtop2 || !ptoq1 || !ptoq2) return false;
	if(qtop1 != qtop2 && ptoq1 != ptoq2) return true;
	return false;
}

bool cf(pair<PII,PII> i, pair<PII,PII> j)
{
	if(i.se != j. se) return(idx[i.se] < idx[j.se]);
	return(idx[i.fi] < idx[j.fi]);
}

int main() 
{
	srand(time(0));
	freopen ("fence4.in","r",stdin);
	freopen ("fence4.out","w",stdout);
	
	scanf("%d",&N);
	scanf("%d %d",&pos.fi,&pos.se);
	for(i=0;i<N;i++) 
	{
		scanf("%d %d",&p[i].fi,&p[i].se);
		idx[p[i]] = i;
	}
	
	for(i=0;i<N;i++)
		for(j=i+1;j<N;j++)
			if(isIntersect(p[i], p[(i+1)%N], p[j], p[(j+1)%N]))
			{
				printf("NOFENCE\n");
				return 0;
			}
			
	for(i=0;i<N;i++)
	{
		if(!ccwTest(pos,p[i],p[(i+1)%N])) continue;
		
		int dx = p[(i+1)%N].fi - p[i].fi;
		int dy = p[(i+1)%N].se - p[i].se;
		int segment = 300;
		
		bool clear = false;
		double t = 0, adder = (double)1/(segment + 1.0);
		for(j = 0; j < segment && !clear; j++)
		{
			t += adder;
			PDD testPoint = mp(p[i].fi + (double) t * dx, p[i].se + (double) t * dy);
			clear = true;
			
			for(k=0;k<N && clear; k++) if(i!=k)
			{
				if(isIntersect(pos,testPoint,p[k],p[(k+1)%N])) clear = false;
				if(clear && !ccwTest(p[k],p[(k+1)%N],p[(k+2)%N]) && isIntersect(pos,testPoint,p[k],p[(k+2)%N])) clear = false;
			}
		}
		
		if(clear)
		{
			if(i + 1 == N) seen.pb(mp(p[0], p[i]));
				else seen.pb(mp(p[i], p[i + 1]));
		}
	}
			
	sort(seen.begin(), seen.end(), cf);
	printf("%d\n",seen.size());
	for(i = 0; i < seen.size(); i++) 
		printf("%d %d %d %d\n", seen[i].fi.fi, seen[i].fi.se, seen[i].se.fi, seen[i].se.se);

	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
