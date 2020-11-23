/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	double dp[101][101][101];
	memset(dp, 0, sizeof dp);

	function<double(int, int, int)> compute = [&] (int a, int b, int c) {
		if (a == 100 or b == 100 or c == 100) return 0.0;
		if (dp[a][b][c] > 0.0) return dp[a][b][c];

		dp[a][b][c] = 0;

		if (a) dp[a][b][c] += (((double)a / (a + b + c)) * (compute(a + 1, b, c) + 1));
		if (b) dp[a][b][c] += (((double)b / (a + b + c)) * (compute(a, b + 1, c) + 1));
		if (c) dp[a][b][c] += (((double)c / (a + b + c)) * (compute(a, b, c + 1) + 1));
		return dp[a][b][c];
	};

	cout << fixed << setprecision(7) << compute(a, b, c) << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}