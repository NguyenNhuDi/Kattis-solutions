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

    vi p_sum(n);
    std::inclusive_scan(inpoo.begin(), inpoo.end(), p_sum.begin());

    ll mini = std::numeric_limits<ll>::max();
    ll maxi = std::numeric_limits<ll>::min();

    FOR(c_range, min_size, max_size + 1){

        FOR(s_pos, 0, c_range){
        
            ll profit = 0;
            ll l = s_pos, r = s_pos + c_range - 1;
            
            if(l > 0)
                if(p_sum[l - 1] > 0) profit++;

            while(r < n){
                ll sum = p_sum[r]; 

                if(l > 0) sum -= p_sum[l - 1];
                
                if(sum > 0) profit++;

                l += c_range; r += c_range;
            }
            
            if(n - 1 >= l)
            if(p_sum[n - 1] - p_sum[l - 1] > 0)
            profit++;
            
            maxi = std::max(maxi, profit);
            mini = std::min(mini, profit);
        }

    }

    std::cout << mini << " " << maxi << std::endl;

    return 0;
}
