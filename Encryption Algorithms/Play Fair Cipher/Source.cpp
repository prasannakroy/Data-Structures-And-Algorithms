#include<bits/stdc++.h>
using namespace std;
#define int long long

template<typename t>
using vc = vector<t>;

vc<vc<char>> keyMat(5, vc<char>(5));
map<char, array<int, 2>> idx;
map<int, int> spcl;
char def, def2;
bool check = 0;
vc<bool> flag(26, 0);

void generatKey(string key) {
	fill(begin(flag), end(flag), 0);
	int len = key.length(), cnt(0);
	char val = key[0];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (flag[val - 'a']) {
				if (cnt + 1 == len) val = 'a', cnt++;
				else if (cnt + 1 < len) val = key[++cnt];
				else val++;
				j--;
			}
			else {
				idx[val] = {i, j};
				keyMat[i][j] = val, flag[val- 'a'] = 1;
			}
		}
	}
	def = keyMat[4][4];
	def2 = keyMat[4][3];
}

string encrypt(string &s) {
	vector<array<char, 2>> lst;
	int n = s.length(), cnt(0);
	if (n & 1) s += 'z', n++, check = 1;
	for (int i = 0; i < n; i += 2) {
		if (s[i] == s[i + 1]) {
			spcl[cnt++] = 1;
			spcl[cnt++] = 1;
			if (s[i] != def) {
				lst.push_back({s[i], def});
				lst.push_back({s[i + 1], def});
			}
			else {
				lst.push_back({s[i], def2});
				lst.push_back({s[i + 1], def2});
			}
		}
		else lst.push_back({s[i], s[i + 1]}), cnt++;
	}
	if (check) spcl[cnt - 1] = 1;

	string res;

	for (auto &[x, y]: lst) {
		char a, b;
		if (idx[x][1] == idx[y][1]) {
			a = keyMat[(idx[x][0] + 1) % 5][idx[x][1]];
			b = keyMat[(idx[y][0] + 1) % 5][idx[y][1]];
		}
		else if (idx[x][0] == idx[y][0]) {
			a = keyMat[idx[x][0]][(idx[x][1] + 1) % 5];
			b = keyMat[idx[y][0]][(idx[y][1] + 1) % 5];
		}
		else {
			a = keyMat[idx[x][0]][idx[y][1]];
			b = keyMat[idx[y][0]][idx[x][1]];
		}
		res += a;
		res += b;
	}
	return res;
}

string decrypt(string &s) {
	vector<array<char, 2>> lst;
	int n = s.length(), cnt(0);
	if (n & 1) s += 'z', n++, check = 1;
	for (int i = 0; i < n; i += 2) {
		if (s[i] == s[i + 1]) {
			spcl[cnt++] = 1;
			lst.push_back({s[i], def});
			i--;
		}
		else lst.push_back({s[i], s[i + 1]}), cnt++;
	}

	string res;
	int i = 0;

	for (auto &[x, y]: lst) {
		char a, b;
		if (idx[x][1] == idx[y][1]) {
			a = keyMat[(((idx[x][0] - 1) % 5) + 5) % 5][idx[x][1]];
			b = keyMat[(((idx[y][0] - 1) % 5) + 5) % 5][idx[y][1]];
		}
		else if (idx[x][0] == idx[y][0]) {
			a = keyMat[idx[x][0]][(((idx[x][1] - 1) % 5) + 5) % 5];
			b = keyMat[idx[y][0]][(((idx[y][1] - 1) % 5) + 5) % 5];
		}
		else {
			a = keyMat[idx[x][0]][idx[y][1]];
			b = keyMat[idx[y][0]][idx[x][1]];
		}
		res += a;
		if (!spcl[i]) 
			res += b;
		i++;
	}
	return res;
}


void solve() {
	string key, text;
	cin >> key >> text;
	transform(begin(key), end(key), begin(key), ::tolower);
	transform(begin(text), end(text), begin(text), ::tolower);
	for (auto &i: text) if (!flag[i - 'a']) 
		flag[i - 'a'] = 1;
	char leave = '.';
	for (char i = 'a'; i <= 'z'; i++) if (!flag[i - 'a']) {
		leave = i;
		break;
	}
	if (leave == '.') return void(cout << "Simple PlayFair Cipher not applicable");

	generatKey(key);

	text = encrypt(text);
	cout << "Encrypted - " << text << "\n";
	text = decrypt(text);
	cout << "Decrypted - " << text << "\n";
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