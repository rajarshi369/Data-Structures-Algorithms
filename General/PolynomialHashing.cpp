#include <iostream>
#include <string>
#define ll unsigned long long
using namespace std;

const int mod = 1e9 + 7;
const int base = 26;
const int N = 10;
ll Powerof26[N];
ll invPowerof26[N];

int main() {
    Powerof26[0] = invPowerof26[0] = 1LL, invPowerof26[1] = 576923081LL;
    for(int i = 1; i < N; i++){
        Powerof26[i] = (Powerof26[i - 1] * 26) % mod;
        if(i + 1 < N)
            invPowerof26[i + 1] = (invPowerof26[i] * invPowerof26[1]) % mod;
    }
	string s, temp;
	cin >> s;
	ll hash[N], revHash[N];
	hash[0] = s[0] - 'a', revHash[s.size() - 1] = s[s.size() - 1] - 'a';
	for(int i = 1, j = s.size() - 2; i < s.size(); i++, j--){
	    hash[i] = (hash[i - 1] + ((s[i] - 'a') * Powerof26[i]) % mod) % mod;
	    revHash[j] = (revHash[j + 1] + ((s[j] - 'a') * Powerof26[i]) % mod) % mod;
	}
	cout << hash[s.size() - 1] << " " << revHash[0] << endl;
	if(hash[s.size() - 1] == revHash[0])
	    cout << "Yes\n";
    else
        cout << "No\n";
    cout << "Concatenated hash = " << (hash[s.size() - 1] + (Powerof26[s.size()] * revHash[0]) % mod) % mod << endl;
	int q;
	cin >> q;
	while(q--){
	    int i, j, k, l;
	    cin >> i >> j;
	    if(i == 0)
	        cout << hash[j] << endl;
        else
	        cout << ((hash[j] - hash[i - 1]) * invPowerof26[i]) % mod << endl;
	}
	return 0;
}

