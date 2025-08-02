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

#define MAXI 46340

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

ll solve(const std::vector<ll> & primes, ll x){
    std::unordered_map<ll, ll> tracker;

    fe(p, primes){
        while(x % p == 0){
            if(tracker.find(p) == tracker.end()) tracker[p] = 1;
            else ++tracker[p];

            x /= p;
        }
    }

    ll out = 1;
    fe(x, tracker) out *= std::pow(x.s, x.f);
    return out;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::vector<ll> primes = sieve();

    ll n;
    while(std::cin >> n)
        std::cout << n << " " << solve(primes, n) << std::endl;
    
    return 0;
}
