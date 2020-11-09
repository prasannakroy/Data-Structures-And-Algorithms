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
#define sumr(l, r) sum(r) - sum(l);

void solve() {
    int n, amt; // n is number of coins, amt is target amount
    cin >> n >> amt;
    vector<int> val(n); // array of denominations
    for (auto &i: val) cin >> i;
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 1)); // dp matrix for memoization

    fill(dp[0].begin(), dp[0].end(), 0); // when number of coins is 0
    
    for (int i = 1; i <= n; i++)  // loop to fill all the indexes in dp
        for (int j = 1; j <= amt; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j < val[i - 1]) continue;
            dp[i][j] += dp[i][j - val[i - 1]];
        }

    cout << dp[n][amt] << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}