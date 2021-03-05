#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<char> cipher(26);
vector<char> decipher(26);
vector<int> getIdx(26);

void shuffle() {
	srand(time(NULL));
	for (int i = 25; i > 0; i--) {
		int idx = rand() % (i + 1);
		swap(cipher[idx], cipher[i]);
	}
}

void generateCipher() {
	iota(begin(cipher), end(cipher), 'a');
	iota(begin(decipher), end(decipher), 'a');
	shuffle();
	for (int i = 0; i < 26; i++) getIdx[cipher[i] - 'a'] = i;
}

void encrypt(string &s, int k) {
	for (auto &i: s) {
		int idx = i - 'a';
		idx += k;
		if (idx < 0) idx += 26;
		if (idx >= 26) idx %= 26;
		i = cipher[idx];
	}
}

void decrypt(string &s, int k) {
	for (auto &i: s) {
		int idx = getIdx[i - 'a'];
		idx -= k;
		if (idx < 0) idx += 26;
		if (idx >= 26) idx %= 26;
		i = decipher[idx];
	}
}

void solve() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	encrypt(s, k);
	cout << "Encrypted : " << s << "\n";
	decrypt(s, k);
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

    generateCipher();

    int t(1);
    // cin >> t;
    while (t--) solve();
}