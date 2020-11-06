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

template<typename t> // Class for Fenwick Tree
class FenwickTree {
public:
    vector<t> tr; // Fenwick Tree Array
    t n; // Size of array

    FenwickTree(t n, vector<t> &a) : n(n) { // Cunstructor call (n = size of array, a is given array)
        tr.resize(n + 1); // Initializing Fenwick tree array with size of array
        for (t i = 0; i < n; i++) // Creating tree
            update(i, a[i]); // updating the value on each index
    }

    void update(t s, t val) { // update function for tree
        for (; s < n; s |= (s + 1)) tr[s] += val; // adding values to all corresponding indices
    }
    
    int query(t r, t l = -1) { // function for range sum query
        if (~l) { // if the sum includes zeroeth index
            int sum(0); 
            for (; r >= 0; r = (r & (r + 1)) - 1) sum += tr[r]; // compute sum
            return sum; // return sum
        }
        else return query(r) - query(l - 1); // simple prefix sum logic
    }
};

void solve() {
    int n, q; // n = size of array, q = number of queries
    cin >> n >> q; 
    vector<int> a(n);
    for (auto &i: a) cin >> i; // taking array input
    FenwickTree<int> bit(n, a); // creating tree
    while (q--) { 
        int t;
        cin >> t;
        if (t == 1) { // update query
            int idx, val;
            cin >> idx >> val;
            idx--; // zero based indexing
            bit.update(idx, -a[idx]); // remove previous value
            a[idx] = val;
            bit.update(idx, a[idx]); // update new value
        }
        else { // range sum query
            int l, r;
            cin >> l >> r; 
            l--, r--; // zero based indexing
            cout << bit.query(r, l) << "\n"; // call sum query
        }
    }
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