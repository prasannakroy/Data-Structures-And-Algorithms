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

template<typename t> 
class LCA{
public:
	t l, n, timer;
	vector<vector<t>> tr, parent;
	vector<t> bgn, ed, level;

	LCA(vector<vector<t>> &tr, t n) : tr(tr), n(n) {
		timer = 0;
		l = ceil(log2(n));
		bgn.resize(n + 1);
		ed.resize(n + 1);
		level.resize(n + 1);
		parent.resize(n + 1, vector<t>(l + 1));
		precomputeDFS(1, 1, 0);
	}

	void precomputeDFS(t u, t p, t lvl) {
		bgn[u] = ++timer;
		parent[u][0] = p;
		level[u] = lvl;
		for (int i = 1; i <= l; i++) parent[u][i] = parent[parent[u][i - 1]][i - 1];
		for (auto &v: tr[u]) if (v != p) precomputeDFS(v, u, lvl + 1);
		ed[u] = ++timer;
	}

	bool isAncestor (t u, t v) {
		return bgn[u] <= bgn[v] and ed[u] >= ed[v];
	}

	t lca(t u, t v) {
		if (isAncestor(u, v)) return u;
		if (isAncestor(v, u)) return v;
		for (t i = l; i >= 0; i--) if (!isAncestor(parent[u][i], v)) u = parent[u][i];
		return parent[u][0];
	}
	
	t kParent(t u, t k) {
	    t r = u;
	    for (t i = 0; i <= l; i++) if (k & (1 << i)) r = parent[r][i];
	    return r;
	}

	t dist(t u, t v) {
		return (level[u] + level[v] - (level[lca(u,v)] << 1));
	}
};

void solve() {
	int n, x, y;
	cin >> n;
	vector<vector<int>> v(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	LCA<int> tree(v, n);
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