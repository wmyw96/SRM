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
#define MOD 1234567891
typedef long long LL;
typedef double LD;

class TheBrickTowerHardDivOne {
public:
    int M[55555];
    int N, ColorCount;
    int a[11];
    vector<int> Gk[22][22]; vector<LL> Gv[22][22];
    void dfs(int x, int mx){
         if (x > 4){
            int s = 0;
            REP(i, 4) s = s * 10 + a[i];
            M[s] = ++N;
            return;
         }
         REP(i, mx + 1){
            a[x] = i;
            dfs(x + 1, max(mx, i));
         }
    }
    inline int ff(int x, int y){
           return a[x] == a[y];
    }
    inline int O_O(int x){
           return max(x, 0);
    }
    int vis[11];
    void connect(int x, int mx){
         if (x > 8){
            int s = 0;
            REP(i, 4) s = s * 10 + a[i];
            int s2 = 0;
            LL tv = 1;
            int pp = 0;
            memset(vis, 0, sizeof vis);
            REP(i, 8){
               if (!a[i]) continue;
               if (!vis[a[i]]){
                  vis[a[i]] = ++pp;
                  if (i > 4)
                     tv = tv * O_O(ColorCount - pp + 1) % MOD;
               }
            }
            memset(vis, 0, sizeof vis);
            pp = 0;
            rep(i, 5, 8){
               if (!vis[a[i]])
                  vis[a[i]] = ++pp;
               if (i > 4)
                  s2 = s2 * 10 + vis[a[i]];
            }
            s = M[s];
            s2 = M[s2];
            int kk = ff(1, 5) + ff(2, 6) + ff(3, 7) + ff(4, 8) + ff(5, 6) + ff(5, 7) + ff(6, 8) + ff(7, 8);
            Gk[s][s2].push_back(kk);
            Gv[s][s2].push_back(tv);
            return;
         }
         REP(i, mx + 1){
            a[x] = i;
            connect(x + 1, max(mx, i));
         }
    }
    LL d[130][130], c[130][130], b[130][130];
    int n;
    int mark[8][16];
    void mul(LL c[][130], LL a[][130], LL b[][130]){
    	 REP(i, n) REP(j, n) c[i][j] = 0;
         REP(i, n) REP(k, n) REP(j, n)
             c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
    }
	int find(int C, int K, long long H) {
        //freopen("1.txt", "w", stdout);
		ColorCount = C;
		memset(M, 0, sizeof M);
		dfs(1, 0);
		connect(1, 0);
		memset(a, 0, sizeof a);
		connect(5, 0);
		rep(k, 0, K) rep(s, 0, N) mark[k][s] = ++n;
		++n;
		memset(c, 0, sizeof c);
		rep(k, 0, K) rep(s, 0, N){
           rep(s2, 0, N)
              REP(e, Gv[s][s2].size()){
                 int dk = Gk[s][s2][e - 1];
                 LL tv = Gv[s][s2][e - 1];
                 if (k + dk <= K)
                    (c[mark[k + dk][s2]][mark[k][s]] += tv) %= MOD;
              }
        }
        rep(k, 0, K) rep(s, 0, N)
           c[n][mark[k][s]] = 1;
        c[n][n] = 1;
        memcpy(d, c, sizeof d);
        memset(c, 0, sizeof c);
        H++;
        REP(i, n) c[i][i] = 1;
        for (int i = 0; i < 61; ++i){
            if ((H >> i) & 1){
               memcpy(b, c, sizeof b);
               mul(c, d, b);
            }
            memcpy(b, d, sizeof b);
            mul(d, b, b);
        }
        int ans = c[n][1] - 1;
        if (ans < 0) ans += MOD;
		return ans;
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, long long p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	TheBrickTowerHardDivOne *obj;
	int answer;
	obj = new TheBrickTowerHardDivOne();
	clock_t startTime = clock();
	answer = obj->find(p0, p1, p2);
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
	
	int p0;
	int p1;
	long long p2;
	int p3;
	
	{
	// ----- test 0 -----
	p0 = 2;
	p1 = 0;
	p2 = 2ll;
	p3 = 4;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 7;
	p2 = 19ll;
	p3 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 2;
	p1 = 3;
	p2 = 1ll;
	p3 = 14;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 4;
	p1 = 7;
	p2 = 47ll;
	p3 = 1008981254;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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
// 
// John and Brus are building towers using toy bricks.
// They have an unlimited supply of bricks of C different colors.
// Each brick is a 1x1x1 cube.
// A tower of height X is a 2x2xX rectangular prism, built using 4X bricks.
// 
// 
// 
// John and Brus want their towers to look nice.
// A tower is nice if it has the following two properties:
// 
// There are at most K pairs of neighboring bricks with the same color. (Two bricks are neighboring if they share a common side.)
// The height of the tower is between 1 and H, inclusive.
// 
// 
// 
// 
// You are given the ints C and K and the long long H.
// Return the number of nice towers, modulo 1,234,567,891.
// 
// 
// 
// DEFINITION
// Class:TheBrickTowerHardDivOne
// Method:find
// Parameters:int, int, long long
// Returns:int
// Method signature:int find(int C, int K, long long H)
// 
// 
// CONSTRAINTS
// -C will be between 1 and 4747, inclusive.
// -K will be between 0 and 7, inclusive.
// -H will be between 1 and 474,747,474,747,474,747, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 0
// 2
// 
// Returns: 4
// 
// No two neighboring bricks may share the same color.
// As we only have two colors, the entire tower must be colored like a chessboard.
// There are two such towers of height 1, and two of height 2.
// 
// 
// 1)
// 1
// 7
// 19
// 
// Returns: 1
// 
// Only one tower of height 1 is acceptable here.
// 
// 
// 2)
// 2
// 3
// 1
// 
// Returns: 14
// 
// There are 16 possible towers of height 1.
// If all bricks share the same color, the tower is not nice.
// There are two such towers.
// Each of the remaining 14 towers is nice.
// 
// 
// 3)
// 4
// 7
// 47
// 
// Returns: 1008981254
// 
// END KAWIGIEDIT TESTING




//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
