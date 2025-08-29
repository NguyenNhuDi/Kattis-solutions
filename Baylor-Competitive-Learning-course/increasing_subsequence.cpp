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

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    do{
        std::cin >> n;

        if(n == 0)
            continue;

        std::vector<int> nums(n);
        std::vector<std::pair<size_t, size_t>> dp;
        FOR(i, 0, n){ 
            std::cin >> nums[i];
            dp.emplace_back(i, 1);
        }

        size_t maxi = 1;
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(nums[i] < nums[j] && dp[i].s < dp[j].s + 1){
                    dp[i].s = dp[j].s + 1;
                    dp[i].f = (size_t)j;
                }
                else if(nums[i] < nums[j] && dp[i].s == dp[j].s + 1){
                    if(nums[j] < nums[dp[i].f]){
                        dp[i].f = j; 
                    }
                }
            } 

            maxi = std::max(maxi, dp[i].s);
        }

        size_t m_index = n + 1;
        int temp = std::numeric_limits<int>::max();
        for(size_t i = 0; i < n; i++)
            if(dp[i].s == maxi && nums[i] < temp){
                temp = nums[i];
                m_index = i;
            }

        size_t prev = n + 1;
        std::cout << maxi << " ";
        do{
            prev = m_index;
            std::cout << nums[m_index] << " ";
            m_index = dp[m_index].f;
        }
        while(m_index != prev);

        std::cout << std::endl;
    }
    while(n > 0);

    return 0;
}
