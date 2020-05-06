// find all primes from a to b using segmented sieve, 1 <= a <= b <= 1e9, b - a <= 1e5

#include <bits/stdc++.h>

const int LIMIT = 1e5;
const int maxN = 32001;

using namespace std;

static bool prime[maxN];
static bool arr[LIMIT];

void sieve() {
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for (int i = 4; i < maxN; i += 2)
        prime[i] = false;
    for (int i = 3; i < maxN; i += 2) {
        if (prime[i]) {
            for (int j = 2 * i; j < maxN; j += i)
                prime[j] = false;
        }
    }
}

void seg_sieve(int a, int b){
    int start = 0, len;
    len = b - a + 1;
    sieve();
    if(b <= maxN){
        for (int i = 2; i <= len; i++) {
            if (prime[i])
                cout << i << endl;
        }
        return;
    }
    if(a <= maxN && b > maxN){
        for (int i = a; i <= maxN; i++) {
            if (prime[i])
                cout << i << endl;
        }
        len = b - maxN;
        a = maxN + 1;
    }
    memset(arr, true, sizeof arr);
    if (a % 2)
        ++start;
    for (int i = start; i < len; i += 2)
        arr[i] = false;
    for (int i = 3; i < maxN; i += 2) {
        if (prime[i]) {
            start = a % i == 0 ? 0 : (i - (a % i));
            for (int j = start; j < len; j += i) 
                arr[j] = false;
        }
    }
    for (int i = 0; i < len; i++) {
        if (arr[i])
            cout << i + a << endl;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    seg_sieve(a, b);
    return 0;
}
