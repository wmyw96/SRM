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
#define INF 1000000000
#define rep(i, s, t) for (int i = (s); i <= (t); ++i)
#define REP(i, n) rep(i, 1, n)
typedef pair<int, int> PII;
typedef long long LL;
typedef double LD;

const int MAX_N = 55, MAX_M = 55 * 55 * 10;
class OldBridges {
public:
	int g[MAX_M], flow[MAX_M], nxt[MAX_M], c[MAX_N], h[MAX_N], nm;
	int d[MAX_N], q[MAX_N];
	char st[MAX_N][MAX_N];
	int n, a1, a2, an, b1, b2, bn;
	int S, T;
	void addedge(int x, int y, int w){
		g[nm] = y; nxt[nm] = c[x]; c[x] = nm; flow[nm] = w; nm++;
	}
	void add(int x, int y, int w){
		addedge(x, y, w);
		addedge(y, x, 0);
	}
	void Build(){
		memset(c, -1, sizeof c);
     	nm = 0;
     	REP(i, n){
        	REP(j, i){
           		if (st[i][j] == 'N')
              		addedge(i, j, INF), addedge(j, i, INF);
           		if (st[i][j] == 'O')
              		addedge(i, j, 2), addedge(j, i, 2);
        	}
     	}
	}
	bool bfs(){
     	memset(d, -1, sizeof d);
     	d[q[1] = S] = 0;
     	for (int l = 1, r = 1; l <= r; ++l){
         	int i = q[l];
         	for (int k = c[i]; ~k; k = nxt[k]){
             	int j = g[k];
             	if (!~d[j] && flow[k]) d[q[++r] = j] = d[i] + 1;
         	}
     	}
     	return d[T] != -1;
	}
	int dfs(int i, int now){
    	if (!now) return 0;
    	if (i == T) return now;
    	int w = 0;
    	for (int k = c[i]; ~k; k = nxt[k]){
        	int j = g[k];
        	if (flow[k] && d[j] == d[i] + 1){
           		int res;
           		if ((res = dfs(j, min(now - w, flow[k]))) > 0){
              		flow[k] -= res;
              		flow[k ^ 1] += res;
              		w += res;
              		if (w == now) return w;
           		}
        	}
    	}
    	return w;
	}
	
	int dinic(){
    	int ans = 0;
    	memcpy(h, c, sizeof h);
    	while (bfs()){
        	ans += dfs(S, INF);
          	memcpy(c, h, sizeof h);
    	}
    	return ans;
	}

	string isPossible(vector <string> bridges, int a1, int a2, int an, int b1, int b2, int bn) {
		n = bridges.size();
		S = n + 1, T = n + 2;
     	a1++; a2++; b1++; b2++;
     	REP(i, n) REP(j, n) st[i][j] = bridges[i - 1][j - 1];
     	Build();
     	add(S, a1, an * 2);
     	add(a2, T, an * 2);
     	add(S, b1, bn * 2);
     	add(b2, T, bn * 2);
     	int cks = (dinic() == an * 2 + bn * 2);
     	Build();
     	add(S, a1, an * 2);
     	add(a2, T, an * 2);
     	add(S, b2, bn * 2);
     	add(b1, T, bn * 2);
     	cks &= (dinic() == an * 2 + bn * 2);
     	return cks ? "Yes" : "No";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, int p2, int p3, int p4, int p5, int p6, bool hasAnswer, string p7) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1 << "," << p2 << "," << p3 << "," << p4 << "," << p5 << "," << p6;
	cout << "]" << endl;
	OldBridges *obj;
	string answer;
	obj = new OldBridges();
	clock_t startTime = clock();
	answer = obj->isPossible(p0, p1, p2, p3, p4, p5, p6);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p7 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p7;
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
	int p3;
	int p4;
	int p5;
	int p6;
	string p7;
	
	{
	// ----- test 0 -----
	string t0[] = {"XOXX","OXOX","XOXO","XXOX"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 1;
	p3 = 1;
	p4 = 2;
	p5 = 3;
	p6 = 1;
	p7 = "Yes";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, p6, true, p7) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"XOXX","OXOX","XOXO","XXOX"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 2;
	p3 = 1;
	p4 = 1;
	p5 = 3;
	p6 = 1;
	p7 = "No";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, p6, true, p7) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"XOXO","OXOX","XOXO","OXOX"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 2;
	p3 = 1;
	p4 = 1;
	p5 = 3;
	p6 = 1;
	p7 = "Yes";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, p6, true, p7) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"XNXO","NXOX","XOXO","OXOX"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 2;
	p3 = 1;
	p4 = 1;
	p5 = 3;
	p6 = 2;
	p7 = "No";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, p6, true, p7) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"XOXOO","OXOXO","XOXOO","OXOXO","OOOOX"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 2;
	p3 = 2;
	p4 = 1;
	p5 = 3;
	p6 = 2;
	p7 = "Yes";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, p6, true, p7) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"XOOOX","OXOOX","OOXOX","OOOXN","XXXNX"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 4;
	p3 = 3;
	p4 = 1;
	p5 = 2;
	p6 = 2;
	p7 = "No";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, p5, p6, true, p7) && all_right;
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
// Alice and Bob live in a country that consists of N islands. The islands are numbered 0 through N-1. Several pairs of islands are connected by bridges. Some of the bridges are very old. They will collapse after the second passage. The other bridges are new and never collapse. Only one person can cross a bridge at a time.
// 
// You are given a vector <string> bridges. Character j of element i of bridges is 'O' (uppercase letter o) if the island i and the island j are connected by an old bridge; 'N' if they are connected by a new bridge; and 'X' if they are not connected by a bridge.
// 
// Alice wants to make an round trips between the islands a1 and a2.
// That is, she wants to make an consecutive trips, where each trip starts at a1, gets somehow to a2, and after some more steps ends back at a1.
// At the same time, Bob wants to make bn round trips between the islands b1 and b2.
// Each round trip may use any sequence of consecutive bridges.
// Different round trips may, but don't have to, use the same sequence of bridges.
// Of course, each old bridge may only be used at most twice. 
// (I.e., it may be used twice by Alice, or twice by Bob, or once by each of them, or just once, or not at all.)
// 
// You are given the vector <string> bridges
// and the ints a1, a2, an, b1, b2, and bn.
// If it is possible to plan all the round trips for Alice and Bob, return "Yes", otherwise return "No".
// 
// DEFINITION
// Class:OldBridges
// Method:isPossible
// Parameters:vector <string>, int, int, int, int, int, int
// Returns:string
// Method signature:string isPossible(vector <string> bridges, int a1, int a2, int an, int b1, int b2, int bn)
// 
// 
// CONSTRAINTS
// -bridges will contain between 4 and 50 elements, inclusive.
// -Each element of bridges will contain exactly N characters, where N is the number of elements of bridges.
// -Each character in each element of bridges will be 'O', 'N', or 'X'.
// -For each i, the i-th character of the i-th element of bridges will be 'X'.
// -For each i and j, the i-th character of the j-th element of bridges will be equal to the j-th character of the i-th element of bridges.
// -The country will be connected, i.e., there will exist a path consisting of one or more bridges between any pair of islands.
// -a1, a2, b1, and b2 will be between 0 and N-1, inclusive.
// -a1, a2, b1, and b2 will be pairwise distinct.
// -an and bn will be between 1 and 50, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"XOXX","OXOX","XOXO","XXOX"}
// 0
// 1
// 1
// 2
// 3
// 1
// 
// Returns: "Yes"
// 
// Alice can travel from the island 0 to the island 1 and go back to the island 0, and Bob can travel from the island 2 to the island 3 and go back to the island 2.
// 
// 1)
// {"XOXX","OXOX","XOXO","XXOX"}
// 0
// 2
// 1
// 1
// 3
// 1
// 
// Returns: "No"
// 
// In order to make a round trip between the island 0 and the island 2, Alice must use the old bridge between the island 1 and the island 2 twice. So Bob cannot travel from the island 1 to the island 3.
// 
// 2)
// {"XOXO","OXOX","XOXO","OXOX"}
// 0
// 2
// 1
// 1
// 3
// 1
// 
// Returns: "Yes"
// 
// One possible pair of tours is 0->1->2->3->0 for Alice and 1->2->3->0->1 for Bob.
// 
// 3)
// {"XNXO","NXOX","XOXO","OXOX"}
// 0
// 2
// 1
// 1
// 3
// 2
// 
// Returns: "No"
// 
// 
// 
// 4)
// {"XOXOO","OXOXO","XOXOO","OXOXO","OOOOX"}
// 0
// 2
// 2
// 1
// 3
// 2
// 
// Returns: "Yes"
// 
// 5)
// {"XOOOX","OXOOX","OOXOX","OOOXN","XXXNX"}
// 0
// 4
// 3
// 1
// 2
// 2
// 
// Returns: "No"
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
