#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second

using namespace std;

#define ll long long int
#define vi std::vector<ll>
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, min_size, max_size; std::cin >> n >> min_size >> max_size;

    std::vector<ll> inpoo(n);
    FOR(i, 0, n) std::cin >> inpoo[i];

    std::unordered_map<ll, vi> dp;
    
    FOR(c_range, min_size, max_size + 1){
        dp[c_range].assign(c_range, 0);
        ll l = 0, r = 0;
        ll c_sum = 0;
        while(r < c_range){
            c_sum += inpoo[r++];
        }

        if(c_sum > 0) 
            dp[c_range][0]++;

        bool first = true;
        ll left_sum = 0;
        while (r < n){
            first = l < c_range - 1;
            l++;
            ll rem = l % c_range;
            if(rem > 0 && first){
                left_sum += inpoo[l - 1];
                if(left_sum > 0)
                    dp[c_range][rem]++;
            }
            c_sum -= inpoo[l - 1];
            c_sum += inpoo[r++];

            if(c_sum > 0)
                dp[c_range][rem]++;
        }

        ll fr = n - 1;

        ll r_sum = 0;
        while(fr > l){
            ll rem = fr % c_range;
            r_sum += inpoo[fr--];
            if(r_sum > 0)
                dp[c_range][rem]++;
        }
    }

    ll maxi = std::numeric_limits<ll>::min();
    ll mini = std::numeric_limits<ll>::max();
    fe(x, dp){
        fe(y, x.s){
           mini = std::min(y, mini);
           maxi = std::max(y, maxi);
        }
    }

    std::cout << mini << " " << maxi << std::endl;

    return 0;
}
