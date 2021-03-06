#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define X first
#define Y second
#define mk make_pair
#define rep(i, s, t) for (int i = (s); i <= (t); ++i)
#define REP(i, n) rep(i, 1, n)
#define INF 1000000000
typedef pair<int, int> PII;
typedef long long LL;
typedef double LD;

class SpellCards {
public:
	
	int f[55][55];
	int a[55], b[55];
	int n;
	
	void rotate(int a[]){
		int x = a[1];
		REP(i, n - 1) a[i] = a[i + 1];
		a[n] = x;
	}
	void relax(int &x, int y){
		if (x < y) x = y;
	}
	
	int calc(int i, int k){
		if (k > n) return -INF;
		if (i == n + 1)
			return k == 0 ? 0 : -INF;
		if (f[i][k] != -1)
			return f[i][k];
		f[i][k] = -INF;
		// use it
		relax(f[i][k], calc(i + 1, k + a[i] - 1) + b[i]);
		// del it
		relax(f[i][k], calc(i + 1, max(k - 1, 0)));
		//printf("f[%d,%d] %d\n", i, k, f[i][k]);
		return f[i][k];
	}
	
	int maxDamage(vector <int> level, vector <int> damage) {
		n = level.size();
		REP(i, n) a[i] = level[i - 1];
		REP(i, n) b[i] = damage[i - 1];
		int ans = 0;
		REP(st, n){
			//printf("==st = %d==\n", st);
			rotate(a);
			rotate(b);
			memset(f, -1, sizeof f);
			relax(ans, calc(1, 0));
		}
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	SpellCards *obj;
	int answer;
	obj = new SpellCards();
	clock_t startTime = clock();
	answer = obj->maxDamage(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	
	{
	// ----- test 0 -----
	int t0[] = {1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {10,20,30};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 60;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {3,3,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {10,20,30};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 30;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {4,4,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {10,20,30};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {50,1,50,1,50};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {10,20,30,40,50};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 60;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {2,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {40,40,10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 80;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {1,2,1,1,3,2,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {10,40,10,10,90,40,10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 170;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	int t0[] = {1,2,2,3,1,4,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {113,253,523,941,250,534,454};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1918;
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// You are playing a card game.
// In the card game, each card holds a magic spell with two properties: its level and its damage.
// During the game, you will play some of the cards (possibly none or all of them) to attack your enemy.
// 
// 
// 
// Initially, there are n cards.
// The cards are placed in a row and they are labeled from 0 to n-1, in order.
// You are given two vector <int>s: level and damage.
// For each i, the level of card i is level[i], and its damage is damage[i].
// 
// 
// 
// In each turn of the game, you can do one of two possible actions:
// 
// 
// Let L be the level and D the damage of the card that is currently the leftmost card in the row.
// If there are at least L cards in the row, you may play the leftmost card.
// Playing it deals D damage to your enemy.
// After you play this card, the first L cards in the row (including the played one) are discarded.
// That is, the cards currently labeled 0 through (L-1), inclusive, are discarded.
// The order of the remaining cards does not change.
// 
// 
// If you have at least one card, you can take the last card in the row and move it to the beginning.
// For example, if the row initially contained cards A,B,C,D,E, in this order, after this operation it will contain E,A,B,C,D.
// 
// 
// After each turn, the cards are relabeled 0 through x-1, where x is their current count.
// 
// 
// 
// Return the maximal total damage you can deal to your opponent.
// 
// DEFINITION
// Class:SpellCards
// Method:maxDamage
// Parameters:vector <int>, vector <int>
// Returns:int
// Method signature:int maxDamage(vector <int> level, vector <int> damage)
// 
// 
// CONSTRAINTS
// -level will contain between 1 and 50 elements, inclusive.
// -level and damage will contain the same number of elements.
// -Each element in level will be between 1 and 50, inclusive.
// -Each element in damage will be between 1 and 10,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1,1,1}
// {10,20,30}
// 
// Returns: 60
// 
// You can play card 0 three times in a row, dealing 10+20+30 = 60 damage.
// 
// 1)
// {3,3,3}
// {10,20,30}
// 
// Returns: 30
// 
// Here, it is optimal to start by moving the last card to the beginning of the row.
// In the second turn we then use the card and deal 30 damage.
// Afterwards, all three cards are discarded.
// 
// 2)
// {4,4,4}
// {10,20,30}
// 
// Returns: 0
// 
// This time you can't use any spell card.
// 
// 3)
// {50,1,50,1,50}
// {10,20,30,40,50}
// 
// Returns: 60
// 
// You can use 2 cards with damage 20 and 40.
// 
// 4)
// {2,1,1}
// {40,40,10}
// 
// Returns: 80
// 
// 
// 
// 5)
// {1,2,1,1,3,2,1}
// {10,40,10,10,90,40,10}
// 
// Returns: 170
// 
// 
// 
// 6)
// {1,2,2,3,1,4,2}
// {113,253,523,941,250,534,454}
// 
// Returns: 1918
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
