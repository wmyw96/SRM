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
typedef pair<int, int> PII;
typedef long long LL;
typedef double LD;

class CirclesGame {
public:
	int cx[55], cy[55], cr[55];
	int q[55], sg[55], du[55], chs[55], ch[55][55], fa[55];
	bool inTo[55][55], ha[55];
	int n;
	int sqr(int x) {return x * x;}
	string whoCanWin(vector <int> _x, vector <int> _y, vector <int> _r) {
		n = _x.size();
		memset(du, 0, sizeof du);
		memset(chs, 0, sizeof chs);
		memset(ch, 0, sizeof ch);
		memset(fa, 0, sizeof fa);
		memset(inTo, 0, sizeof inTo);
		REP(i, n) cx[i] = _x[i - 1], cy[i] = _y[i - 1], cr[i] = _r[i - 1];
		REP(i, n) REP(j, n)
			inTo[i][j] = (cr[i] < cr[j] && sqr(cx[i] - cx[j]) + sqr(cy[i] - cy[j]) < sqr(cr[j]));
		
		cr[n + 1] = 1000000000;
		REP(i, n){
			fa[i] = n + 1;
			REP(j, n) if (inTo[i][j] && cr[j] < cr[fa[i]])
				fa[i] = j;
			//printf("%d\n", fa[i]);
			ch[fa[i]][++chs[fa[i]]] = i;
			++du[fa[i]];
		}
		int r = 0;
		REP(i, n) if (du[i] == 0){
			sg[i] = 1;
			q[++r] = i;
		}
		for (int l = 1; l <= r; ++l){
			int i = q[l];
			memset(ha, 0, sizeof ha);
			int s = 0;
			REP(k, chs[i]) s ^= sg[ch[i][k]];
			ha[s] = 1;
			REP(k, chs[i]){
				s ^= sg[ch[i][k]];
				rep(j, 0, sg[ch[i][k]]){
					if ((j ^ s) <= 51)
						ha[j ^ s] = 1;
				}
				s ^= sg[ch[i][k]];
			}
			int x = 0;
			for (; ha[x]; ++x);
			sg[i] = x;
			du[fa[i]]--;
			if (du[fa[i]] == 0)
				q[++r] = fa[i];
		}
		int ans = 0;
		REP(i, chs[n + 1])
			ans ^= sg[ch[n + 1][i]];
		return ans ? "Alice" : "Bob";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, bool hasAnswer, string p3) {
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
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	CirclesGame *obj;
	string answer;
	obj = new CirclesGame();
	clock_t startTime = clock();
	answer = obj->whoCanWin(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p3 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	vector <int> p2;
	string p3;
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// Alice is playing a game with her old friend, Bob.
// 
// There are n circles on a paper. The center of the i-th circle is (x[i], y[i]), and the radius is r[i].
// No two different circles share a common point on their boundary.
// However, it is allowed for circles to be located entirely within other circles.
// In the game, the players take alternating turns.
// Alice starts.
// In each move, the current player must:
// 
// Choose a circle such that there is no red point strictly inside the circle.
// Pick one point that is strictly inside the chosen circle and color it red.
// 
// If a player can't do such a move, he/she loses the game.
// 
// You are given the vector <int>s x, y, and r that describe a set of circles with the above property.
// Return "Alice" (quotes for clarity) if Alice has a winning strategy for the given set of circles.
// Otherwise, return "Bob".
// 
// 
// DEFINITION
// Class:CirclesGame
// Method:whoCanWin
// Parameters:vector <int>, vector <int>, vector <int>
// Returns:string
// Method signature:string whoCanWin(vector <int> x, vector <int> y, vector <int> r)
// 
// 
// NOTES
// -Points located on the boundary of a circle are not considered to be strictly inside that circle.
// 
// 
// CONSTRAINTS
// -x will contain between 1 and 50 elements, inclusive.
// -x, y, and r will each contain the same number of elements.
// -Each element in x will be between -10,000 and 10,000, inclusive.
// -Each element in y will be between -10,000 and 10,000, inclusive.
// -Each element in r will be between 1 and 10,000, inclusive.
// -No two circles intersect. That is, the boundaries of the given circles are pairwise disjoint.
// 
// 
// EXAMPLES
// 
// 0)
// {0}
// {0}
// {1}
// 
// Returns: "Alice"
// 
// This test case has just one circle. Alice draws a red point anywhere inside the circle and Bob has no valid move.
// 
// 1)
// {0, 3}
// {0, 0}
// {1, 1}
// 
// Returns: "Bob"
// 
// Two separate circles. Alice draws a red point in one of them, Bob draws a red point in another one, then Alice has no valid moves.
// 
// 2)
// {0, 0, 5}
// {0, 0, 0}
// {1, 2, 1}
// 
// Returns: "Alice"
// 
// In her first move, Alice should draw a point within the circle 1, but so that it's not within the circle 0. (Both indices are 0-based.)
// 
// 3)
// {0, 0, 0, 10, 10, 20}
// {0, 0, 0, 0, 0, 0}
// {1, 2, 3, 1, 2, 1}
// 
// Returns: "Bob"
// 
// 
// 
// 4)
// {10,20,30,40,50,60,70,80}
// {8,7,6,5,4,3,2,1}
// {2,2,2,2,2,2,2,2}
// 
// Returns: "Bob"
// 
// 
// 
// 5)
// {0, 3, 6, 9, 12, -4747, -4777}
// {-5858, -5858, -5858, -5858, -5858, 777, 777}
// {58, 1, 1, 1, 1, 44, 8}
// 
// Returns: "Bob"
// 
// 
// 
// 6)
// {5202, 5699, -7433, 5068, -9483, -684, -6593, 5108, -7813, 6823, 3267, -8222, -8547, 2878, 2413, 8557, 5149, 5073, -8638, -6108, 8097}
// {8728, -7407, 4338, -8414, 7652, -3705, -984, 5976, -9180, -9119, 9301, 2398, 7915, 6205, 7665, 717, -9884, 11, -8579, -6903, -746}
// {4196, 9303, 7152, 5875, 2943, 788, 502, 416, 1958, 3174, 182, 1256, 1147, 444, 979, 65, 1040, 1233, 438, 175, 1140}
// 
// Returns: "Alice"
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
