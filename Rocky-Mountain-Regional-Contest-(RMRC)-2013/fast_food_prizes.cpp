#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int _; std::cin >> _;
    while(_--){
        int n, m; std::cin >> n >> m;

        std::vector<std::pair<int, std::vector<int>>> tracker;

        FOR(i, 0, n){
            int j; std::cin >> j;
            std::vector<int> temp(j);

            FOR(k, 0, j) std::cin >> temp[k];

            int key; std::cin >> key;
            tracker.emplace_back(key, temp);
        }

        std::vector<int> tickets(101, 0);

        FOR(i, 1, m + 1) std::cin >> tickets[i];
        
        unsigned long long ans = 0;

        fe(key, tracker){
            int mini = std::numeric_limits<int>::max();
            fe(x, key.s)
                mini = std::min(mini, tickets[x]);

            ans += mini * key.f;
        }

        std::cout << ans << std::endl;
    }
    

    return 0;
}
