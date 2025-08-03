#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07
#define pii pair<int,int>
#define f first
#define s second

#define MAXI 65536

using namespace std;

std::vector<ll> sieve(){
    std::vector<ll> out;

    std::vector<bool> nums(MAXI + 1, true);

    for(int i = 2; i <= MAXI; i++){
        if(nums[i]){
            out.push_back(i);

            for(int j = i * 2; j <= MAXI; j += i)
                nums[j] = false;
        }
    }

    return out;
}

bool is_prime(const std::vector<ll> & primes, const ll x){

    if(std::binary_search(primes.begin(), primes.end(), x))
        return true;

    fe(p, primes){
        if (x % p == 0)
            return false;
    }

    return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::vector<ll> primes = sieve();

    ll n;
    while(std::cin >> n){
        if(n == 0)
            break;

        ll original = n;
        bool prime = is_prime(primes,n);

        n *= 2;
        ++n;

        while(!is_prime(primes, n)) n++;
        
        std::cout << n; 
        if(!prime)
            std::cout << " (" << original << " is not prime)";
        std::cout << std::endl;
    }

    return 0;
}
