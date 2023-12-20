/*****************************
*  Author :: Πρασαννα Κ. Ροι *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

template<typename t>
using minpq = priority_queue<t, vc<t>, greater<t>>;

template<typename t>
using maxpq = priority_queue<t>;

void merge(vector<int> &a, int n, int st, int sz) {
    int s1 = st;
    int e1 = min(s1 + sz, n);
    int s2 = min(s1 + sz, n);
    int e2 = min(s2 + sz, n);

    vector<int> aux;

    int i, j;
    for (i = s1, j = s2; i < e1 and j < e2; ) {
        if (a[i] < a[j]) {
            aux.push_back(a[i++]);
        } else {
            aux.push_back(a[j++]);
        }
    }
    while (i < e1) 
        aux.push_back(a[i++]);
    while (j < e2) 
        aux.push_back(a[j++]);

    for (int i = s1; i < e2; i++) {
        a[i] = aux[i - s1];
    }
}

void mergeSort(vector<int> &a, int n) {
    for (int i = 1; i < n; i *= 2) {
        for (int j = 0; j < n; j += (i * 2)) {
            merge(a, n, j, i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) 
        cin >> i;

    mergeSort(a, n);
    for (auto &i: a) 
        cout << i << ' ';
    cout << '\n';
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
  // cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}
