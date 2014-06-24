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

using namespace std;

#define X first
#define Y second
#define mk make_pair
#define rep(i, s, t) for (int i = (s); i <= (t); ++i)
#define per(i, s, t) for (int i = (s); i >= (t); --i)
#define REP(i, n) rep(i, 1, n)
#define PER(i, n) per(i, n, 1)
typedef pair<int, int> PII;
typedef long long LL;
typedef double LD;

#define BASE 900

class FoxAndFlowerShopDivOne {
public:
    int s[33][33], s2[33][33];
    char a[33][33];
    int U[33][BASE * 2 + 1], L[33][BASE * 2 + 1], R[33][BASE * 2 + 1], D[33][BASE * 2 + 1];
    int n, m;
	inline int gg(char t) { return (t == '.') ? (0) : (t == 'L' ? 1 : -1); }
	inline int gts(int s[][33], int x, int y, int a, int b) { return s[x][y] - s[x][b - 1] - s[a - 1][y] + s[a - 1][b - 1]; }
	inline void checkmax(int &x, int y) { if (x < y) x = y; }
	int theMaxFlowers(vector <string> flowers, int maxDiff) {
		n = flowers.size();
		m = flowers[0].size();
		rep(i, 0, n + 1) rep(s, 0, BASE * 2) U[i][s] = -1000000000;
		rep(i, 0, n + 1) rep(s, 0, BASE * 2) D[i][s] = -1000000000;
		rep(i, 0, m + 1) rep(s, 0, BASE * 2) L[i][s] = -1000000000;
		rep(i, 0, m + 1) rep(s, 0, BASE * 2) R[i][s] = -1000000000;
		REP(i, n) REP(j, m) a[i][j] = flowers[i - 1][j - 1];
		REP(i, n) REP(j, m) s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + (a[i][j] != '.');
		REP(i, n) REP(j, m) s2[i][j] = s2[i][j - 1] + s2[i - 1][j] - s2[i - 1][j - 1] + gg(a[i][j]);
		REP(i, n) REP(j, m) REP(k, i) REP(p, j){
               int a2 = gts(s2, i, j, k, p), a1 = gts(s, i, j, k, p);
               checkmax(U[i][a2 + BASE], a1);
               checkmax(D[k][a2 + BASE], a1);
               checkmax(L[j][a2 + BASE], a1);
               checkmax(R[p][a2 + BASE], a1);
               //printf("%d %d %d %d   (%d, %d)\n", k, p, i, j, a2, a1);
        }
        REP(i, n) rep(s, 0, BASE * 2) checkmax(U[i][s], U[i - 1][s]);
        PER(i, n) rep(s, 0, BASE * 2) checkmax(D[i][s], D[i + 1][s]);
        REP(j, m) rep(s, 0, BASE * 2) checkmax(L[j][s], L[j - 1][s]);
        PER(j, m) rep(s, 0, BASE * 2) checkmax(R[j][s], R[j + 1][s]);
        // -
        int ans = -1;
        rep(e, -BASE, BASE) rep(e2, -BASE, BASE)
               if (abs(e + e2) <= maxDiff){
                  REP(i, n - 1) checkmax(ans, U[i][e + BASE] + D[i + 1][e2 + BASE]);
                  REP(j, m - 1) checkmax(ans, L[j][e + BASE] + R[j + 1][e2 + BASE]);
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	FoxAndFlowerShopDivOne *obj;
	int answer;
	obj = new FoxAndFlowerShopDivOne();
	clock_t startTime = clock();
	answer = obj->theMaxFlowers(p0, p1);
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
	
	vector <string> p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"LLL","PPP","LLL"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 7;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"LLL","PPP","LLL"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 6;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"...","...","..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"LLPL.LPP","PLPPPPLL","L.P.PLLL","LPL.PP.L",".LLL.P.L","PPLP..PL"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 38;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"LLLLLLLLLL","LLLLLLLLLL","LLLLLLLLLL","LLLLLLLLLL","LLLLLLLLLL"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = -1;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"LLLP..LLP.PLL.LL..LP","L.PL.L.LLLL.LPLLPLP.","PLL.LL.LLL..PL...L..",".LPPP.PPPLLLLPLP..PP","LP.P.PPL.L...P.L.LLL","L..LPLPP.PP...PPPL..","PP.PLLL.LL...LP..LP.","PL...P.PPPL..PLP.L..","P.PPPLPLP.LL.L.LLLPL","PLLPLLP.LLL.P..P.LPL","..LLLPLPPPLP.P.LP.LL","..LP..L..LLPPP.LL.LP","LPLL.PLLPPLP...LL..P","LL.....PLL.PLL.P....","LLL...LPPPPL.PL...PP",".PLPLLLLP.LPP...L...","LL...L.LL.LLLPLPPPP.","PLPLLLL..LP.LLPLLLL.","PP.PLL..L..LLLPPL..P",".LLPL.P.PP.P.L.PLPLL"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 9;
	p2 = 208;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
// Fox Jiro came to a flower shop to buy flowers.
// The flowers in the shop are arranged in some cells of a rectangular grid.
// The layout of the grid is given as a vector <string> flowers.
// There are two types of flowers in the shop: lilies and petunias.
// If the j-th cell of the i-th row of the grid contains a flower, then the j-th character of the i-th element of flowers will be 'L' if it is a lily, and 'P' if it is a petunia.
// (All indices in the previous sentence are 0-based.)
// If the particular cell is empty, the corresponding character will be '.' (a period).
// 
// In order to buy flowers, Jiro has to draw two disjoint rectangles on this grid and buy all the flowers which lie inside the rectangles.
// Of course, the sides of the rectangles must be on cell boundaries.
// (Therefore, the sides of the rectangles will necessarily be parallel to the coordinate axes.)
// The rectangles are allowed to touch, but they may not intersect.
// In other words, the rectangles may share a common boundary, but no cell may belong to both rectangles.
// Each of the two rectangles must contain at least one cell.
// 
// Jiro wants to buy approximately the same number of lilies and petunias.
// More precisely, the positive difference between the number of lilies and petunias must be at most maxDiff, inclusive.
// Given that constraint, Jiro wants to buy as many flowers as possible.
// 
// You are given the vector <string> flowers and the int maxDiff.
// Return the maximum possible number of flowers Jiro can buy in this situation.
// If there is no valid way to buy flowers, return -1 instead.
// 
// DEFINITION
// Class:FoxAndFlowerShopDivOne
// Method:theMaxFlowers
// Parameters:vector <string>, int
// Returns:int
// Method signature:int theMaxFlowers(vector <string> flowers, int maxDiff)
// 
// 
// CONSTRAINTS
// -flowers will contain between 2 and 30 elements, inclusive.
// -Each element of flowers will contain the same number of characters.
// -Each element of flowers will contain between 1 and 30 characters, inclusive.
// -Each character in flowers will be either 'L', 'P', or '.'.
// -maxDiff will be between 0 and 900, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"LLL",
//  "PPP",
//  "LLL"}
// 1
// 
// Returns: 7
// 
// Jiro cannot buy all the flowers, because the difference between the number of lilies and the number of petunias would be too large.
// The best he can do is to buy 7 flowers: 4 lilies and 3 petunias.
// One way of doing so is to draw two rectangles: (0,0)-(1,2) and (2,0)-(2,0).
// Note that (r1,c1)-(r2,c2) denotes a rectangle with cell (r1,c1) in the top left corner and cell (r2,c2) in the bottom right corner.
// (All indices are 0-based.)
// 
// 1)
// {"LLL",
//  "PPP",
//  "LLL"}
// 0
// 
// Returns: 6
// 
// This time Jiro is required to buy the same number of lilies and petunias.
// Therefore the best he can do is to buy three of each kind.
// 
// 2)
// {"...",
//  "...",
//  "..."}
// 3
// 
// Returns: 0
// 
// There are no flowers.
// 
// 3)
// {"LLPL.LPP",
//  "PLPPPPLL",
//  "L.P.PLLL",
//  "LPL.PP.L",
//  ".LLL.P.L",
//  "PPLP..PL"}
// 2
// 
// Returns: 38
// 
// 
// 
// 4)
// {"LLLLLLLLLL",
//  "LLLLLLLLLL",
//  "LLLLLLLLLL",
//  "LLLLLLLLLL",
//  "LLLLLLLLLL"}
// 0
// 
// Returns: -1
// 
// Here it is impossible to draw the two rectangles. Regardless of how Jiro draws them, he will surely buy more lilies than petunias, and that is not allowed.
// 
// 5)
// {"LLLP..LLP.PLL.LL..LP",
//  "L.PL.L.LLLL.LPLLPLP.",
//  "PLL.LL.LLL..PL...L..",
//  ".LPPP.PPPLLLLPLP..PP",
//  "LP.P.PPL.L...P.L.LLL",
//  "L..LPLPP.PP...PPPL..",
//  "PP.PLLL.LL...LP..LP.",
//  "PL...P.PPPL..PLP.L..",
//  "P.PPPLPLP.LL.L.LLLPL",
//  "PLLPLLP.LLL.P..P.LPL",
//  "..LLLPLPPPLP.P.LP.LL",
//  "..LP..L..LLPPP.LL.LP",
//  "LPLL.PLLPPLP...LL..P",
//  "LL.....PLL.PLL.P....",
//  "LLL...LPPPPL.PL...PP",
//  ".PLPLLLLP.LPP...L...",
//  "LL...L.LL.LLLPLPPPP.",
//  "PLPLLLL..LP.LLPLLLL.",
//  "PP.PLL..L..LLLPPL..P",
//  ".LLPL.P.PP.P.L.PLPLL"}
// 9
// 
// Returns: 208
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
