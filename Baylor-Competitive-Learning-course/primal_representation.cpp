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

void sieve(std::vector<ll> & primes){
    std::vector<bool> nums(MAXI + 1, false);

    for(size_t i = 2; i <= MAXI; i++){
        if(nums[i])
            continue;
        primes.push_back(i);
        for(size_t j = i; j < nums.size(); j += i)
            nums[j] = true;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::vector<ll> primes;
    sieve(primes);

    ll n;
    while(std::cin >> n){
        std::map<ll, size_t> tracker;

        if(n < 0)
            std::cout << -1 << " ";

        n = std::abs(n);

        ll temp = n;
        fe(p, primes){
            if(p * p > temp)
                break;
            while(temp % p == 0){
                tracker[p]++;
                temp /= p;
            }
        }

        if(temp > 1)
            tracker[temp]++;

        fe(x, tracker){
            std::cout << x.f;
            if(x.s > 1) std::cout << "^" << x.s;
            std::cout << " ";
        }

        std::cout << std::endl;

    }

    return 0;
}
