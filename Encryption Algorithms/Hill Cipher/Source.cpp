#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 29;

int power(int a, int b) {
	int res(1);
	while (b) {
		if (b & 1) (res *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return res;
}

int inverse(int a) {
	return power(a, mod - 2);
}

int len;

void getCofactor(vector<vector<int>> &mat, vector<vector<int>> &a, int x, int y, int sz) {
	int p(0), q(0);
	for (int i = 0; i < sz; i++) if (i != x) {
		for (int j = 0; j < sz; j++) if (j != y) {
			if (q == sz - 1) {
				p++;
				q = 0;
			}
			a[p][q] = mat[i][j];
			q++;
		}
	}
}

int findDeterminant(vector<vector<int>> &mat, int sz) {
	int res(0);
	if (sz == 1) return mat[0][0];
	vector<vector<int>> a(sz - 1, vector<int>(sz - 1, 0));
	int t(1);
	for (int i = 0; i < sz; i++) {
		getCofactor(mat, a, 0, i, sz);
		(res += (t * mat[0][i] * findDeterminant(a, sz - 1)) % mod) %= mod;
		t *= -1;
	}
	return res;
}

void generateAdj(vector<vector<int>> &mat, vector<vector<int>> &adj, int sz) {
	if (sz == 1) return void(adj[0][0] = 1);
	int t = 1;
	vector<vector<int>> a(sz - 1, vector<int>(sz - 1, 0));
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			getCofactor(mat, a, i, j, sz);
			t = ((i + j) % 2 ? -1 : 1);
			int det = findDeterminant(a, sz - 1);
			adj[j][i] = (t * det) % mod;
			if (adj[j][i] < 0) adj[j][i] += mod;
		}
	}
}

bool findInverse(vector<vector<int>> &mat, vector<vector<int>> &inv, int sz) {
	int det = findDeterminant(mat, sz);
	if (!det) return 0;
	vector<vector<int>> adj(sz, vector<int>(sz, 0));
	generateAdj(mat, adj, sz);
	for (int i = 0; i < sz; i++) 
		for (int j = 0; j < sz; j++) {
			inv[i][j] = (adj[i][j] * inverse(det)) % mod;
			if (inv[i][j] < 0) inv[i][j] += mod;
		}
	return 1;
}

void matProd(vector<vector<int>> &a, vector<vector<int>> &b, vector<vector<int>> &c, int l, int m, int n) {
	c.assign(l, vector<int>(m, 0));
	for (int i = 0; i < l; i++) 
		for (int j = 0; j < n; j++) 
			for (int k = 0; k < m; k++) 
				(c[i][j] += (a[i][k] * b[k][j]) % mod) %= mod;
}

string encrypt(vector<vector<int>> &mat, string s, int sz) {
	int n = s.length();
	len = n % sz;
	for (int i = 0; i < sz - len; i++) s += 'x';
	int it = (n + sz - 1) / sz;
	vector<vector<int>> a(sz, vector<int>(1));
	auto sol = a;
	int idx(0);
	string res("");
	for (int i = 0; i < it; i++) {
		for (int j = 0; j < sz; j++) a[j][0] = s[idx] - 'a', idx++;
		matProd(mat, a, sol, sz, sz, 1);
		for (int j = 0; j < sz; j++) 
			res += (char)(sol[j][0] + 'a');
	}
	return res;
}

string decrypt(vector<vector<int>> &mat, string s, int sz) {
	int n = s.length();
	int idx2 = n;
	if (len) idx2 = idx2 - sz + len;
	int it = (n + sz - 1) / sz;
	vector<vector<int>> a(sz, vector<int>(1, 0));
	auto sol = a;
	int idx(0);
	string res("");
	for (int i = 0; i < it; i++) {
		for (int j = 0; j < sz; j++) 
			a[j][0] = s[idx] - 'a', idx++;
		matProd(mat, a, sol, sz, sz, 1);
		for (int j = 0; j < sz; j++) if (idx2)  
			res += (char)(sol[j][0] + 'a'), idx2--;
	}
	return res;
}

void solve() {
	string key, s;
	cin >> s >> key;
	int n = key.length();
	int d = sqrt(n);
	if (d * d != n) d++;
	vector<vector<int>> mat(d, vector<int>(d));
	auto inv = mat;
	int idx = 0, i2(0);
	for (int i = 0; i < d; i++) 
		for (int j = 0; j < d; j++) 
			mat[i][j] = key[idx] - 'a', (idx += 1) %= n;
	bool t = findInverse(mat, inv, d);
	if (!t) return void(cout << "Encryption not possible\n");
	s = encrypt(mat, s, d);
	cout << "Encrypted : " << s << "\n";
	s = decrypt(inv, s, d);
	cout << "Decrypted : " << s << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t(1);
    // cin >> t;
    while (t--) solve();
}