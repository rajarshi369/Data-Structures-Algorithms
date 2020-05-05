// find all primes from a to b using segmented sieve, 1 <= a <= b <= 1e9, b - a <= 1e6

#include <bits/stdc++.h>

const int LIMIT = 1e6;
const int maxN = 32001;

using namespace std;

static bool prime[maxN];
static int arr[LIMIT];

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

int main() {
    int a, b, start = 0, len;
    cin >> a >> b;
    len = b - a + 1;
    sieve();
    if(b <= maxN){
        for (int i = 2; i <= (b - a + 1); i++) {
            if (prime[i])
                cout << i << " ";
        }
        return 0;
    }
    if(a <= maxN && b > maxN){
        for (int i = a; i <= maxN; i++) {
            if (prime[i])
                cout << i << " ";
        }
        len = b - maxN;
        a = maxN + 1;
    }
    for (int i = 0; i < len; i++) {
        arr[i] = i + a;
    }
    if (a % 2)
        ++start;
    for (int i = start; i < len; i += 2) {
        while (arr[i] % 2 == 0) {
            arr[i] /= 2;
        }
    }
    for (int i = 3; i < maxN; i += 2) {
        if (prime[i]) {
            start = a % i == 0 ? 0 : (i - (a % i));
            for (int j = start; j < len; j += i) {
                while (arr[j] % i == 0) {
                    arr[j] /= i;
                }
            }
        }
    }
    for (int i = 0; i < len; i++) {
        if (arr[i] != 1)
            cout << i + a << " ";
    }
    return 0;
}
 
