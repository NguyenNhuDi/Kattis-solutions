#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second

using namespace std;

#define ll long long
#define MAXI 1e6

std::vector<ll> sieve(){
    std::vector<bool> primes(MAXI + 1, true);
    std::vector<ll> out;

    primes[0] = primes[1] = false;
    
    for(ll i = 2; i < MAXI + 1; i++){
        if(!primes[i])
            continue;
        out.push_back(i);
        for(ll j = i * i; j < MAXI + 1; j += i)
            primes[j] = false;
    }
    return out;
}

void get_prime_factor(ll x, std::unordered_map<ll, ll> & tracker, const std::vector<ll> & primes){
    
    fe(p, primes){
        if (p * p > x) break;

        while(x % p == 0){
            tracker[p]++;
            x /= p;
        }
    }

    if(x > 1)
        tracker[x]++;
}

bool is_square(const std::unordered_map<ll, ll> & tracker){
    fe(e, tracker){
        if(e.s % 2 == 1) return false;
    }
    return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b; std::cin >> a >> b;

    if(a * b == 1)
        std::cout << 2 << std::endl;
    else{

        std::unordered_map<ll, ll> tracker;
        auto primes = sieve();

        get_prime_factor(a, tracker, primes);
        get_prime_factor(b, tracker, primes);

        ll divisors = 1;

        fe(x, tracker){
            divisors *= (x.s + 1);
        }

        if(is_square(tracker)) divisors++;

        std::cout << divisors << std::endl;
    }

    return 0;
}
