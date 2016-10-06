/*
	ID: felikju1
	PROG: cryptcow
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
#define pii pair<int,int> 
#define pdd pair<double,double> 
#define ll long long

#define PI 2*acos(0.0)
#define EPS 1e-9
#define INF 1000000000

using namespace std;

const char* ans = "Begin the Escape execution at the Break of Dawn";
const int anslen = strlen(ans);
const int MOD = 10007;
const int ASCII_MAX = 128;

int cnt[ASCII_MAX], len, encryptTimes;
vector<unsigned char> hash[48][MOD];
bool contained;
char msg[100];

void readInput()
{
	freopen ("cryptcow.in","r",stdin);
	gets(msg); len = strlen(msg);
	fclose(stdin);
}

void printOutput(int a, int b)
{
	freopen ("cryptcow.out","w",stdout);
	printf("%d %d\n", a, b);
	fclose(stdout);
}

void decrypt(int times, char* now)
{
	//printf("%d %s\n", times, now);
	if(times == encryptTimes)
	{
		if(!strcmp(now, ans))
		{
			contained = true;
			printOutput(1, encryptTimes);
		}
		return;
	}
	
	int nowlen = strlen(now), Clen = 0, Olen = 0, Wlen = 0, alen = 0;
	int C[15], O[15], W[15], all[40];
	all[alen++] = -1;
	for(int i = 0; i < nowlen; i++) if(now[i] == 'C' || now[i] == 'O' || now[i] == 'W')
	{
		all[alen++] = i;
		switch(now[i])
		{
			case('C') : C[Clen++] = i; break;
			case('O') : O[Olen++] = i; break;
			case('W') : W[Wlen++] = i; break;
		}
	}
	all[alen++] = nowlen;
				
	/* pruning 4: first O must occurs AFTER first C, first W must occurs AFTER first C */
	if(O[0] < C[0] || W[0] < C[0]) return;
	
	/* pruning 5: last O must occurs BEFORE last W, last C must occurs BEFORE last W */
	if(O[Olen-1] > W[Wlen-1] || C[Clen-1] > W[Wlen-1]) return;
	
	/* pruning 6: any longest substring not containing C, O, W must also be substring of ans */
	for(int i = 0; i + 1 < alen; i++)
	{
		if(all[i + 1] - all[i] == 1) continue;
		
		int temp = 0, length = all[i + 1] - all[i] - 1;
		for(int j = all[i] + 1; j < all[i + 1]; j++) temp = (temp * ASCII_MAX + now[j]) % MOD;
			
		bool found = false;
		for(int j = 0, tot = (int) hash[length][temp].size(); j < tot && !found; j++) 
		{
			int start = hash[length][temp][j];
			found = true;
			for(int k = 0; k < length && found; k++) 
				if(ans[start + k] != now[all[i] + 1 + k]) found = false;
		}
			
		if(!found) return;
	}
	
	for(int i = 0; i < Clen && !contained; i++)
		for(int j = upper_bound(O, O + Olen, C[i]) - O; j < Olen && !contained; j++)
			for(int k = upper_bound(W, W + Wlen, O[j]) - W; k < Wlen && !contained; k++)
			{
				int c = C[i], o = O[j], w = W[k], nextlen = 0;
				char next[nowlen];
				
				if(c) { memcpy(next, now, c); nextlen += c; }
				memcpy(next + nextlen, now + (o + 1), w - o - 1); nextlen += w - o - 1;
				memcpy(next + nextlen, now + (c + 1), o - c - 1); nextlen += o - c - 1;
				if(w + 1 < nowlen) { memcpy(next + nextlen, now + (w + 1), nowlen - w - 1); nextlen += nowlen - w - 1; }
				next[nextlen] = '\0';
				
				/* pruning 7: for first C & any O & W combination, the resulting prefix must same */
				if(!i)
				{
					int nextC = 0;
					for(nextC = 0; nextC < nextlen; nextC++) if(next[nextC] == 'C') break;
					
					bool found = true;
					for(int x = 0; x < nextC && found; x++) if(ans[x] != next[x]) found = false;
					if(!found) break;
				}
				
				decrypt(times + 1, next);
			}
}

int main()
{
	readInput();
	
	for(int i = 0; i < anslen; i++)
	{
		int now = 0;
		for(int j = i; j < anslen; j++)
		{
			now = (now * ASCII_MAX + ans[j]) % MOD;
			hash[j - i + 1][now].pb(i);
		}
	}
			
	/* pruning 1: if strlen(msg) < anslen, it is impossible 
				  moreover, (strlen(msg) - anslen) mod 3 must equal to 0 */
	if(len < anslen || (len - anslen) % 3 != 0)
	{
		printOutput(0, 0);
		return 0;
	}
	
	/* pruning 2: both string must have same num of every character except C, O, and W */
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < len; i++) cnt[msg[i]]++;
	for(int i = 0; i < anslen; i++) cnt[ans[i]]--;
	for(int i = 0; i < ASCII_MAX; i++) if(cnt[i] != 0 && i != (int)'C' && i != (int)'O' && i != 'W')
	{
		printOutput(0, 0);
		return 0;
	}
	
	/* pruning 3: it is required that cnt['C'] == cnt['O'] == cnt['W'] == X after previous
				  subtraction, where X = (strlen(msg) - anslen) / 3 */
	encryptTimes = (len - anslen) / 3;
	if(cnt['C'] != encryptTimes || cnt['O'] != encryptTimes || cnt['W'] != encryptTimes)
	{
		printOutput(0, 0);
		return 0;
	}
	
	/* try decrypt it encryptTimes times to find out using simple backtracking */
	contained = false;
	decrypt(0, msg);
	
	if(!contained) printOutput(0, 0);
	return 0;
}
