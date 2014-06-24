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

class MapGuessing {
public:
	int cnt[(1 << 17) + 1];
	char b[15 * 55], a[55];
	int n, m, L, R, len, mx, mst;
	LL ans;
	LL go[55];
	char ff[55];
	
	long long calc(int pos){
		LL ls = 0, ret = 0;
		memset(ff, 0, sizeof ff);
		REP(i, m){
			if (b[i] == '<') {--pos; continue;}
			if (b[i] == '>') {++pos; continue;}
			ff[pos] = b[i];
			int ok = 1;
			ls = 0;
			REP(j, n)
				if (ff[j]){
					if (ff[j] != a[j])
						ok = 0;
					else ls |= (1LL << j-1);
				}
			if (ok) ret = ls;//, cout << "pp" << i << endl;;
		}
		return ret;
	}
	
	inline int countint(LL x){
		return cnt[x >> 16] + cnt[x & ((1 << 16) - 1)];
	}
	
	inline int countLL(LL x){
		return countint(x & ((1LL << 32) - 1)) + countint(x >> 32);
	}
	
	void solve(int x, int fh, int e, LL sta){
		if (x > mx){
			if (!e) return;
			ans += fh * (1LL << countLL(sta));
			return;
		}
		// not choose
		if (x < mx || mst == 0)
			solve(x + 1, fh, e, sta);
		if (go[x] == -1) return;
		if (e)
			solve(x + 1, -fh, e, sta & go[x]);
		else solve(x + 1, -fh, 1, go[x]);
	}
	long long binom[1111][1111];
	long long countPatterns(string goal, vector <string> code) {
		n = goal.size();
		ans = 0;
		binom[0][0] = 1;
		REP(i, 1000){
			binom[i][0] = binom[i][i] = 1;
			REP(j, i) binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
		}
		string opr;
		rep(i, 0, (1 << 16) - 1)
			for (int j = i; j; j -= j & (-j))
				cnt[i]++;
		REP(i, code.size()) REP(j, code[i - 1].size())
			opr += code[i - 1][j - 1];
		m = opr.size();
		REP(i, m) b[i] = opr[i - 1];
		REP(i, n) a[i] = goal[i - 1];
		L = 0, R = 0;
		int pos = 0;
		REP(i, m){
			if (b[i] == '<') --pos;
			if (b[i] == '>') ++pos;
			L = min(L, pos);
			R = max(R, pos);
		}
		//cout << L << " " << R << endl;
		len = R - L + 1;
		L = -L + 1;
		R = n - len + 1;
		//printf("%d %d %d\n", L, R, len);
		if (R < 1) return 0;
		rep(i, 1, R) go[i] = calc(i + L - 1);
		//rep(i, 1, R) printf("%lld\n", go[i]);
		mst = 0;
		//cout << L << " " << R << endl;
		if (R <= 20){
			mx = R;
			solve(1, -1, 0, 0);
		}
		else{
			mx = len;
			mst = 0;
			solve(1, -1, 0, 0);
			rep(i, 2, R - len + 1){
				mx = i + len - 1;
				mst = 1;
				solve(i, -1, 0, 0);
			}
			REP(i, R)
				ans += binom[R][i] * ((i & 1) ? (1) : (-1));
			REP(i, R){
				int le = min(R - i + 1, len);
				REP(j, le) ans -= binom[le - 1][j - 1] * ((j & 1) ? (1) : (-1));
			}
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
bool KawigiEdit_RunTest(int testNum, string p0, vector <string> p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	MapGuessing *obj;
	long long answer;
	obj = new MapGuessing();
	clock_t startTime = clock();
	answer = obj->countPatterns(p0, p1);
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
	
	string p0;
	vector <string> p1;
	long long p2;
	
	{
	// ----- test 0 -----
	p0 = "000";
	string t1[] = {"0"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "001";
	string t1[] = {"0>1"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 5ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "000";
	string t1[] = {"1>1>1"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "11001";
	string t1[] = {">><<<<><<"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "1000101011";
	string t1[] = {"1<<0>>0>1"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 22ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "00000010000000000000000000000000";
	string t1[] = {"><>>0<0<>>1>0><>","<<0>>0<>><0>0>>><><",">>>0<>",">0><>>>>0<<><>>0>>>0<0>>0>"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 13601ll;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = "11100011010111111010100100110001101";
	string t1[] = {"11111111111111111111","1<><><><><><><><><>1","1<>000>000><0<><0<>1","1<0<><>0><0<00>00<>1","1<>00<>000><0<0<0<>1","1<><>0>0><0<0<><0<>1","1<000<>0><0<0<><0<>1","1<><><><><><><><><>1","1<>000><000<>000><>1","1<>0><><0<><>0><><>1","1<>000><000<>000><>1","1<><>0><><0<><>0><>1","1<>000><000<>000><>1","1<><><><><><><><><>1","11111111111111111111"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 90ll;
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
// Invader Squid Girl is a big fan of the Advanced Turing Game.
// This is a game in which the player programs a simple Turing machine (defined below).
// The goal of this game is to turn the starting tape into a pre-determined goal tape.
// 
// 
// 
// The picture above explains how the Turing machines in our problem operate.
// On the top you can see the goal tape: a finite sequence of cells, each containing a zero (0) or a one (1).
// The player starts with a tape of the same length as the goal tape.
// The player's tape is initially filled with some zeros and ones.
// The Turing machine has a "head": a reading and writing device.
// At each moment, the head points at one of the cells of the tape.
// In order to change it to the goal tape, the player picks a starting cell for the head and writes a program for the Turing machine.
// 
// In this problem, the program is simply a sequence of commands, executed one after another.
// There are just four commands:
// 
//  '0' : Write 0 into the cell where the head points. (The old content of the cell is lost.)
//  '1' : Write 1 into the cell where the head points. (The old content of the cell is lost.)
//  '<' : Move the head one cell to the left.
//  '>' : Move the head one cell to the right.
// 
// 
// It is not allowed for the head to leave the tape (i.e., move left from the leftmost cell or right from the rightmost one).
// Should that happen, the player loses -- even if the goal has been reached before the head left the tape.
// In other words, a level of the Advanced Turing Game is considered solved if the head never leaves the tape, and at any point during the execution of the program (including the beginning and the end) the content of the tape exactly matches the goal tape.
// 
// Squid Girl recently solved a level of the Advanced Turing Game.
// However, she forgot the initial contents of the tape, and her choice of the starting cell.
// All she remembers is the program she wrote, and the content of the goal tape.
// Help her by counting the number of possible initial contents of the tape.
// 
// You are given a string goal that describes the goal tape, and a vector <string> code.
// Concatenate all elements of code to get Squid Girl's program.
// Return a long long containing the number of possible initial contents of the tape.
// 
// 
// DEFINITION
// Class:MapGuessing
// Method:countPatterns
// Parameters:string, vector <string>
// Returns:long long
// Method signature:long long countPatterns(string goal, vector <string> code)
// 
// 
// NOTES
// -Note that we are only counting the possible initial contents of the tape. Even if multiple starting positions work for a given tape, we only count it once.
// -For some test cases the return value may be zero (0).
// -The constraints imply that code will contain at most 555 characters.
// -The automaton used in the problem is not an actual Turing machine. The actual Turing machines are more complex, with a potentially infinite tape and a more powerful "programming language". Of course, this has no relevance regarding the problem you have to solve.
// 
// 
// CONSTRAINTS
// -goal will contain between 1 and 36 characters, inclusive.
// -Each character in goal will be either '0' or '1'.
// -code will contain between 1 and 15 elements, inclusive.
// -Each element of code will contain between 1 and 37 characters, inclusive.
// -Each character in each element of code will be one of '0', '1', '<', and '>'.
// 
// 
// EXAMPLES
// 
// 0)
// "000"
// {"0"}
// 
// Returns: 4
// 
// There are 4 possible contents of the initial tape: "000", "001", "010", and "100".
// 
// 1)
// "001"
// {"0>1"}
// 
// Returns: 5
// 
// There are 5 possible contents of the initial tape: "000", "001", "010", "011", and "101".
// Note that for the initial tape "101" we have to choose the leftmost cell as the starting one.
// We will then reach the goal after the first command is executed.
// 
// 2)
// "000"
// {"1>1>1"}
// 
// Returns: 1
// 
// The goal can also be reached before any commands are executed.
// 
// 3)
// "11001"
// {">><<<<><<"}
// 
// Returns: 0
// 
// There is no possible contents of the initial tape. (We do reach the goal if the initial tape is equal to the goal tape, but as the head leaves the word, this does not count.)
// 
// 4)
// "1000101011"
// {"1<<0>>0>1"}
// 
// Returns: 22
// 
// 
// 
// 5)
// "00000010000000000000000000000000"
// {"><>>0<0<>>1>0><>", "<<0>>0<>><0>0>>><><", ">>>0<>", ">0><>>>>0<<><>>0>>>0<0>>0>"}
// 
// Returns: 13601
// 
// Don't forget to concatenate code.
// 
// 6)
// "11100011010111111010100100110001101"
// {"11111111111111111111"
// ,"1<><><><><><><><><>1"
// ,"1<>000>000><0<><0<>1"
// ,"1<0<><>0><0<00>00<>1"
// ,"1<>00<>000><0<0<0<>1"
// ,"1<><>0>0><0<0<><0<>1"
// ,"1<000<>0><0<0<><0<>1"
// ,"1<><><><><><><><><>1"
// ,"1<>000><000<>000><>1"
// ,"1<>0><><0<><>0><><>1"
// ,"1<>000><000<>000><>1"
// ,"1<><>0><><0<><>0><>1"
// ,"1<>000><000<>000><>1"
// ,"1<><><><><><><><><>1"
// ,"11111111111111111111"}
// 
// Returns: 90
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
