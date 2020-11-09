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
    vector<vector<int>> dp(n, vector<int>(amt + 1, -1));

    // Computation function to compute result
    function<int(int, int)> compute = [&](int idx, int sum) {
        // when we use coins till index idx and target amount is equal to sum then the number of total ways is this return value
        if (sum == 0) return 1ll; // When sum = 0, total number of ways is 1
        if (sum < 0 or idx < 0) return 0ll; // when sum is less than 0 then total number of ways should be 0
        if (dp[idx][sum] != -1) return dp[idx][sum];
        
        if (val[idx] > sum) return dp[idx][sum] = compute(idx - 1, sum); // If the new coin is greater than required amount then it will not make any contribution and result will be same as it was without it.
        // If the coin is includable then we can either use it or don't and total number of ways is sum of both.
        return dp[idx][sum] = (compute(idx - 1, sum) + compute(idx, sum - val[idx]));
    };

    cout << compute(n - 1, amt) << "\n";
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