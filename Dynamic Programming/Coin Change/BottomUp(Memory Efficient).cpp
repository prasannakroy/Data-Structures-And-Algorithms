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
    vector<int> dp(amt + 1, 0); // dp matrix for memoization
    // when amount is 0 (base case)
    dp[0] = 1;

    // loop to fill the dp array
    for (int i = 0; i < n; i++) 
        for (int j = val[i]; j <= amt; j++) 
            dp[j] += dp[j - val[i]];
    cout << dp[amt] << "\n";
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