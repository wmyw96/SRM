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

class HyperKnight {
public:
	long long countCells(int a, int b, int numRows, int numColumns, int K) {
		int fx[8] = {a, a, -a, -a, b, b, -b, -b};
		int fy[8] = {b, -b, b, -b, a, -a, a, -a};
		LL ans[256];
		LL lstans = 0;
		memset(ans, 0, sizeof ans);
		for (int s = 255; s >= 0; --s){
			int XL = 1, XR = numRows, YL = 1, YR = numColumns;
			for (int k = 0; k < 8; ++k){
				if (((s >> k) & 1) == 0) continue;
				int xl = 1, xr = numRows;
				if (fx[k] > 0)
					xr = numRows - fx[k];
				else xl -= fx[k];
				int yl = 1, yr = numColumns;
				if (fy[k] > 0)
					yr = numColumns - fy[k];
				else yl -= fy[k];
				XL = max(xl, XL);
				XR = min(xr, XR);
				YL = max(yl, YL);
				YR = min(yr, YR);
			}
			ans[s] = LL(XR - XL + 1) * (YR - YL + 1);
			//printf("%d %lld\n", s, ans[s]);
			for (int s2 = 255; s2 > s; --s2)
				if ((s2 & s) == s)
					ans[s] -= ans[s2];
			int t = 0;
			for (int k = s; k; k -= k & (-k))
				++t;
			if (t == K)
				lstans += ans[s];
		}
		return lstans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, bool hasAnswer, long long p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	HyperKnight *obj;
	long long answer;
	obj = new HyperKnight();
	clock_t startTime = clock();
	answer = obj->countCells(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
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
	
	int p0;
	int p1;
	int p2;
	int p3;
	int p4;
	long long p5;
	
	{
	// ----- test 0 -----
	p0 = 2;
	p1 = 1;
	p2 = 8;
	p3 = 8;
	p4 = 4;
	p5 = 20ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 2;
	p2 = 8;
	p3 = 8;
	p4 = 2;
	p5 = 16ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 3;
	p2 = 7;
	p3 = 11;
	p4 = 0;
	p5 = 0ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 3;
	p1 = 2;
	p2 = 10;
	p3 = 20;
	p4 = 8;
	p5 = 56ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 1;
	p1 = 4;
	p2 = 100;
	p3 = 10;
	p4 = 6;
	p5 = 564ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 2;
	p1 = 3;
	p2 = 1000000000;
	p3 = 1000000000;
	p4 = 8;
	p5 = 999999988000000036ll;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, true, p5) && all_right;
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
// Fernando loves to play chess. One day he decided to play chess on an unusually large rectangular board. To compensate for the board's size he also decided to change the distance a knight can move in a single jump.
// 
// To describe the moves easily, we will now introduce a coordinate system. Each cell of the chessboard can be described using two integers (r,c): its row number and its column number. Now, if we have a piece at (r,c), the move (x,y) takes the piece to the cell (r+x,c+y).
// 
// The new chess piece will be called an (a,b)-hyperknight. The hyperknight always has 8 possible moves: (+a,+b), (+a,-b), (-a,+b), (-a,-b), (+b,+a), (+b,-a), (-b,+a), and (-b,-a). Note that the original chess knight is a (2,1)-hyperknight.
// 
// Of course, as the chessboard is finite, it is not always possible to make each of the 8 moves. Some of them may cause our hyperknight to leave the chessboard. A move is called valid if the destination cell is on the chessboard. Fernando would like to know the number of cells on his board such that his hyperknight will have exactly k valid moves from that cell.
// 
// You are given the ints a, b, numRows, numColumns and k. The values numRows and numColumns define the number of rows and number of columns on the chessboard, respectively. The other three values were already explained above. Compute and return the number of cells on the chessboard that have exactly k valid (a,b)-hyperknight moves.
// 
// DEFINITION
// Class:HyperKnight
// Method:countCells
// Parameters:int, int, int, int, int
// Returns:long long
// Method signature:long long countCells(int a, int b, int numRows, int numColumns, int k)
// 
// 
// NOTES
// -If you wish, you may assume that the rows are numbered 0 through numRows-1 and columns 0 through numColumns-1. However, note that the actual row/column numbers do not matter, as long as they are consecutive.
// 
// 
// CONSTRAINTS
// -a will be between 1 and 1,000,000,000 (10^9), inclusive.
// -b will be between 1 and 1,000,000,000 (10^9), inclusive.
// -a will not be equal to b.
// -numRows will be between 1 and 1,000,000,000 (10^9), inclusive.
// -numColumns will be between 1 and 1,000,000,000 (10^9), inclusive.
// -2*max(a,b) will be strictly less than min(numRows,numColumns).
// -k will be between 0 and 8, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 1
// 8
// 8
// 4
// 
// Returns: 20
// 
// This is a standard chessboard. We have a traditional chess knight and we are looking for cells such that the knight has exactly 4 valid moves.
// 
// 1)
// 3
// 2
// 8
// 8
// 2
// 
// Returns: 16
// 
// 
// 
// 2)
// 1
// 3
// 7
// 11
// 0
// 
// Returns: 0
// 
// 
// 
// 3)
// 3
// 2
// 10
// 20
// 8
// 
// Returns: 56
// 
// 
// 
// 4)
// 1
// 4
// 100
// 10
// 6
// 
// Returns: 564
// 
// 
// 
// 5)
// 2
// 3
// 1000000000
// 1000000000
// 8
// 
// Returns: 999999988000000036
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!