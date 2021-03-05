#include<bits/stdc++.h>
using namespace std;
#define int long long

// For all ascii characters
string encrypt(string s, int k) {
	for (auto &i: s) {
		int idx = i;
		idx += k;
		if (idx < 0) idx += 128;
		if (idx >= 128) idx %= 128;
		i = (char)idx;
	}
	return s;
}

string decrypt(string s, int k) {
	for (auto &i: s) {
		int idx = i;
		idx -= k;
		if (idx < 0) idx += 128;
		if (idx >= 128) idx %= 128;
		i = (char)idx;
	}
	return s;
}

// For all characters that are printable
string encryptSpecial(string s, int k) {
	for (auto &i: s) {
		int idx = i - 31;
		idx += k;
		if (idx < 0) idx += 96;
		if (idx >= 96) idx %= 96;
		i = (char)(idx + 31);
	}
	return s;
}

string decryptSpecial(string s, int k) {
	for (auto &i: s) {
		int idx = i - 31;
		idx -= k;
		if (idx < 0) idx += 96;
		if (idx >= 96) idx %= 96;
		i = (char)(idx + 31);
	}
	return s;
}

signed main() {
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s;
    int k;
    cin >> s >> k;
    s = encryptSpecial(s, k);
    cout << "Encrypted : " << s << "\n";
    s = decryptSpecial(s, k);
    cout << "Decrypted : " << s << "\n";
    return 0;
}