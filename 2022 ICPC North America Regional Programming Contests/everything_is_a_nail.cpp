#pragma GCC optimize("O3", "unroll-loops", "fast-math")
#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second

using namespace std;


int get_lis(const std::vector<int> & inpoo, const int order[3]){
    std::vector<int> lis;
    lis.reserve(inpoo.size());

    int rank[3];
    FOR(i, 0, 3) rank[order[i]] = i;

    fe(num, inpoo){
        int r = rank[num];
        auto it = std::upper_bound(lis.begin(), lis.end(), r);
        if(it == lis.end()) lis.push_back(r);
        else *it = r;
    }
    return lis.size();
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    constexpr int perms[6][3] = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 0, 2},
        {1, 2, 0},
        {2, 0, 1},
        {2, 1, 0}
    };

    int n; std::cin >> n; 
    std::vector<int> inpoo(n);
    FOR(i, 0, n) std::cin >> inpoo[i];
    int maxi = -1;

    FOR(i, 0, 6){
        maxi = std::max(maxi, get_lis(inpoo, perms[i]));
    }
    std::cout << maxi << std::endl;

    return 0;
}
