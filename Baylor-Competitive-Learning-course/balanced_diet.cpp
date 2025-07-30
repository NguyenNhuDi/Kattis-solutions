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
    while(std::cin >> n){
        if (n == 0)
            break;

        std::vector<int> nums(n);

        int total = 0;
        for(int i = 0; i < n; i++){
            std::cin >> nums[i];
            total += nums[i];
        }
        std::vector<bool> possible_sums(total + 1);
        possible_sums[0] = true;

        int mini = std::numeric_limits<int>::max();

        fe(x, nums){
            std::vector<int> indicies;

            for(int i = 0; i < possible_sums.size(); i++)
                if(possible_sums[i]) indicies.push_back(i + x);
        
            fe(y, indicies)
                possible_sums[y] = true;
        }

        int l = 0, r = 0;
        for(int i = 0; i < possible_sums.size(); i++){
            if(possible_sums[i]){
                int diff = std::abs(i - (total - i));
                if (diff < mini){
                    mini = diff;
                    l = i;
                    r = total - i;
                }
            }
        }

        if(r > l){
            std::swap(l, r);
        }
        std::cout << l << " " << r << std::endl;
    }

    return 0;
}
