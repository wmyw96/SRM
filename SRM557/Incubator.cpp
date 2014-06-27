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

class Incubator {
public:
	int g[55][55], my[55], n;
	int vis[55], Fate;
	bool dfs(int x){
		REP(y, n) if (vis[y] != Fate && g[x][y]){
			vis[y] = Fate;
			if (!my[y] || dfs(my[y])){
				my[y] = x;
				return 1;
			}
		}
		return 0;
	}
	int maxMagicalGirls(vector <string> love) {
		n = love.size();
		int ans = n;
		REP(i, n) REP(j, n) g[i][j] = love[i - 1][j - 1] == 'Y';
		REP(k, n) REP(i, n) REP(j, n) g[i][j] |= g[i][k] & g[k][j];
		memset(my, 0, sizeof my);
		REP(i, n) {
			++Fate;
			ans -= dfs(i);
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	Incubator *obj;
	int answer;
	obj = new Incubator();
	clock_t startTime = clock();
	answer = obj->maxMagicalGirls(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	{
	// ----- test 0 -----
	string t0[] = {"NY","NN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"NYN","NNY","NNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"NNYNNNNN","NNNYNNNN","NNNNYNNN","NNYNNNNN","NNNNNYYN","NNNYNNNY","NNNNNNNN","NNNNNNNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	string t0[] = {"Y"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
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
// You are the Incubator.
// You have the ability to turn normal girls into magical girls.
// 
// 
// 
// There are n girls in the city.
// The girls are conveniently numbered 0 through n-1.
// Some girls love some other girls.
// Love is not necessarily symmetric.
// It is also possible for a girl to love herself.
// 
// 
// 
// You are given a vector <string> love.
// Character j of element i of love is 'Y' if girl i loves girl j.
// Otherwise, that character is 'N'.
// In the rest of the problem statement, we will use love[i][j] to denote the truth value of the statement "girl i loves girl j".
// 
// 
// 
// Each girl has two boolean properties: isMagical (is she a magical girl?) and isProtected (is she protected by some girl?).
// Initially, for each girl i we have isMagical[i] = False and isProtected[i] = False.
// 
// 
// 
// At any moment, you can choose an ordinary girl and turn her into a magical girl.
// That is, you can take a girl i such that isMagical[i] = False, and change isMagical[i] to True.
// 
// 
// 
// Each such change will trigger a series of events:
// 
// Each magical girl will protect all girls she loves: if isMagical[i] and love[i][j], then isProtected[j] is set to True.
// Each protected girl will also protect all girls she loves: if isProtected[i] and love[i][j], then isProtected[j] is set to True.
// 
// Note that some of these changes may in turn trigger other changes, as more and more girls become protected.
// 
// 
// 
// Once there are no more changes, you can again change another ordinary girl into a magical one, and so on.
// Your goal is to reach a situation with many girls that are magical, but not protected.
// That is, you are interested in girls such that isMagical[i] = True and isProtected[i] = False.
// Return the maximum number of such girls in a situation that can be reached using the above process.
// 
// DEFINITION
// Class:Incubator
// Method:maxMagicalGirls
// Parameters:vector <string>
// Returns:int
// Method signature:int maxMagicalGirls(vector <string> love)
// 
// 
// CONSTRAINTS
// -n will be between 1 and 50, inclusive.
// -love will contain exactly n elements.
// -Each element of love will contain exactly n characters.
// -Each character in each element of love will be either 'Y' or 'N'.
// 
// 
// EXAMPLES
// 
// 0)
// {"NY","NN"}
// 
// Returns: 1
// 
// One optimal solution is to change girl 0 to a magical girl.
// Girl 0 will be magical and she will not be protected.
// It is not possible to have two girls that are both magical and not protected:
// if you change both girls to magical girls (in any order), you will get a situation in which girl 1 is protected.
// 
// 1)
// {"NYN", "NNY", "NNN"}
// 
// Returns: 1
// 
// Again, there is no way to create more than one unprotected magical girl.
// For example, if we start by making girl 2 magical, and then make girl 0 magical, magical girl 0 will protect girl 1, and protected girl 1 will protect girl 2.
// Thus, in this case girl 0 will be magical and unprotected, girl 1 will be ordinary and protected, and girl 2 will be magical and protected.
// 
// 2)
// {"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"}
// 
// Returns: 2
// 
// 
// 
// 3)
// {"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"}
// 
// Returns: 2
// 
// 
// 
// 4)
// {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"}
// 
// Returns: 5
// 
// 
// 
// 5)
// {"NNYNNNNN","NNNYNNNN","NNNNYNNN","NNYNNNNN","NNNNNYYN","NNNYNNNY","NNNNNNNN","NNNNNNNN"}
// 
// Returns: 2
// 
// 
// 
// 6)
// {"Y"}
// 
// Returns: 0
// 
// Note that a girl may love herself.
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!