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
#define REP(i, n) rep(i, 1, n)
typedef pair<int, int> PII;
typedef long long LL;
typedef double LD;

class Ear {
public:
	int n, m;
	int a[333], bx[333], by[333];
	int esmaller(int x){
		return lower_bound(a + 1, a + 1 + n, x + 1) - a - 1;
	}
	int ebigger(int x){
		return n - (lower_bound(a + 1, a + 1 + n, x) - a) + 1;
	}
	long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) {
		int x = 0;
		REP(i, redX.size()) REP(j, redX[i - 1].size()){
			if (redX[i - 1][j - 1] == ' ')
				a[++n] = x, x = 0;
			else x = x * 10 + redX[i - 1][j - 1] - '0';
		}
		a[++n] = x;
		sort(a + 1, a + 1 + n);
		x = 0;
		REP(i, blueX.size()) REP(j, blueX[i - 1].size()){
			if (blueX[i - 1][j - 1] == ' ')
				bx[++m] = x, x = 0;
			else x = x * 10 + blueX[i - 1][j - 1] - '0';			
		}
		bx[++m] = x;
		x = 0;
		m = 0;
		REP(i, blueY.size()) REP(j, blueY[i - 1].size()){
			if (blueY[i - 1][j - 1] == ' ')
				by[++m] = x, x = 0;
			else x = x * 10 + blueY[i - 1][j - 1] - '0';			
		}
		by[++m] = x;
		LL ans = 0;
		REP(p, m) REP(q, m){
			if (p == q) continue;
			if (by[p] <= by[q]) continue;
			double x = double(by[q] * bx[p] - bx[q] * by[p]) / (by[q] - by[p]);
			int xl = (-by[q] * bx[p] + bx[q] * by[p] + by[p] - by[q] - 1) / (by[p] - by[q]) - 1;
			int xr = (-by[q] * bx[p] + bx[q] * by[p]) / (by[p] - by[q]) + 1;
			int sl, sr;
			if (bx[p] > bx[q]){
				int ls = ebigger(bx[p] + 1);
				int ls2 = ebigger(bx[q] + 1);
				ls2 -= ls;
				sr = ls * (ls - 1) / 2 + ls2 * ls;
				ls = esmaller(xl);
				ls2 = esmaller(bx[q] - 1);
				ls2 -= ls;
				sl = ls * (ls - 1) / 2 + ls2 * ls;
			}
			if (bx[p] == bx[q]){
				int ls = esmaller(bx[p] - 1);
				sl = ls * (ls - 1) / 2;
				ls = ebigger(bx[p] + 1);
				sr = ls * (ls - 1) / 2;
			}
			if (bx[p] < bx[q]){
				int ls = esmaller(bx[p] - 1);
				int ls2 = esmaller(bx[q] - 1);
				ls2 -= ls;
				sl = ls * (ls - 1) / 2 + ls * ls2;
				ls = ebigger(xr);
				ls2 = ebigger(bx[q] + 1);
				ls2 -= ls;
				sr = ls * (ls - 1) / 2 + ls * ls2;
			}
			ans += LL(sl) * sr;
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, vector <string> p2, bool hasAnswer, long long p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p2[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	Ear *obj;
	long long answer;
	obj = new Ear();
	clock_t startTime = clock();
	answer = obj->getCount(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	
	vector <string> p0;
	vector <string> p1;
	vector <string> p2;
	long long p3;
	
	{
	// ----- test 0 -----
	string t0[] = {"3 2 8 7"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"5 4"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"2 4"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"3 2 8 7"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"2 8"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"3 4"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 0ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"1 2 6 9"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"3 6 8 5"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"1 5 4 3"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 4ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"10000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"10000 9999"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"10000 9999"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 0ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"100 2","00"," 39","9"," 800 900 9","99"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"15","0 250 ","349"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"2 3 1"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 12ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"1"," ","2"," ","3"," ","4 5 6"," 7 8 9"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"4"," ","5"," ","6"," 7 ","8"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"1"," 2 ","3 4"," 5"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 204ll;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
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
// There are some red points and blue points on the Cartesian plane.
// All red points are on the x-axis and all blue points are in the upper half-plane. That is, the y-coordinate of each red point is 0, and the y-coordinate of each blue point is strictly positive.
// 
// Fox Ciel wants to form an ear-shaped figure using these points.
// She defines that the pair of four different red points A, B, C, D and two blue points P, Q is called an ear if and only if all the following conditions are satisfied.
// 
// 
// Both points B and C lie strictly inside the segment AD.
// The angles PAD, PDA, QBC and QCB are strictly less than 90 degrees.
// Point Q is strictly inside of the triangle PAD.
// 
// 
// In the following image, points in the left figure form an ear while points in the right figure do not.
// 
// 
// 
// You are given three vector <string>s redX, blueX and blueY.
// Concatenate all elements of redX to get a space-separate list of integers.
// The i-th integer of this list represents the x-coordinate of i-th red point.
// In the same way, blueX and blueY encode lists of x-coordinates and y-coordinates of blue points.
// 
// Your method must return the number of ways in which we can choose the four red and two blue points that form an ear.
// 
// 
// DEFINITION
// Class:Ear
// Method:getCount
// Parameters:vector <string>, vector <string>, vector <string>
// Returns:long long
// Method signature:long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY)
// 
// 
// NOTES
// -The order of points in an ear does not matter. I.e., if two ears have the same four red and two blue points, they are considered the same.
// 
// 
// CONSTRAINTS
// -redX, blueX and blueY will each contain between 1 and 50 elements, inclusive.
// -Each element of redX, blueX and blueY will contain between 1 and 50 characters, inclusive.
// -After concatenating the elements of redX, the resulting string will be a single space separated list of integers.
// -After concatenating the elements of blueX, the resulting string will be a single space separated list of integers.
// -After concatenating the elements of blueY, the resulting string will be a single space separated list of integers.
// -There will be between 1 and 300 integers in each of the lists.
// -The number of integers in the lists of blueX and blueY will be the same.
// -Each integer in the lists will be between 1 and 10,000, inclusive.
// -All the integers in each list will be distinct.
// -Integers in the lists will have no leading zeros.
// 
// 
// EXAMPLES
// 
// 0)
// {"3 2 8 7"}
// {"5 4"}
// {"2 4"}
// 
// Returns: 1
// 
// This case corresponds to the left figure in the statement.
// 
// 1)
// {"3 2 8 7"}
// {"2 8"}
// {"3 4"}
// 
// Returns: 0
// 
// This case corresponds to the right figure in the statement.
// 
// 2)
// {"1 2 6 9"}
// {"3 6 8 5"}
// {"1 5 4 3"}
// 
// Returns: 4
// 
// There exists only one possible combinations of A, B, C and D since there are only four red points. Possible combinations of P and Q are as follows.
// 
// {(5, 3), (3, 1)}
// {(6, 5), (3, 1)}
// {(8, 4), (3, 1)}
// {(6, 5), (5, 3)}
// 
// 
// 
// 
// 3)
// {"10000"}
// {"10000 9999"}
// {"10000 9999"}
// 
// Returns: 0
// 
// It is impossible to choose four red points from only one red point.
// 
// 4)
// {"100 2", "00", " 39", "9", " 800 900 9", "99"}
// {"15", "0 250 ", "349"}
// {"2 3 1"}
// 
// Returns: 12
// 
// Concatenate each element of the vector <string>s correctly.
// 
// 5)
// {"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"}
// {"4", " ", "5", " ", "6", " 7 ", "8"}
// {"1", " 2 ", "3 4", " 5"}
// 
// Returns: 204
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
