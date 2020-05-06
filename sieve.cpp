// print all primes from 1 to LIMIT using sieve of Erastosthenes

#include <iostream>

const int LIMIT = 1e6;
static bool prime[LIMIT];

void sieve() {
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for (int i = 4; i < LIMIT; i += 2)
        prime[i] = false;
    for (int i = 3; i < LIMIT; i += 2) {
        if (prime[i]) {
            for (int j = 2 * i; j < LIMIT; j += i)
                prime[j] = false;
        }
    }
}

int main(){
    sieve();
    for(int i = 2; i < LIMIT; i++){
        if(prime[i]) 
            std :: cout << i << " ";
    }
}
