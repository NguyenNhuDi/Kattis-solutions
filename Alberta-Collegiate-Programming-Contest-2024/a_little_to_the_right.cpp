#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second

using namespace std;

struct node{
    size_t val, index;

    bool operator < (const node & other){
        return val < other.val;
    }
};

bool is_sorted(std::vector<node> & arr){
    FOR(i, 1, arr.size()) if(arr[i].val <= arr[i - 1].val) return false;
    return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t n, p; std::cin >> n >> p;

    std::vector<std::vector<node>> inpoo(p, std::vector<node>(n));

    FOR(i, 0, n){
        FOR(j, 0, p){
            size_t temp; std::cin >> temp;
            inpoo[j][i] = {temp, (size_t)i};
        }
    }
    
    size_t ans = 0;

    std::unordered_set<std::string> tracker;

    FOR(i, 0, p){
        sort(inpoo[i].begin(), inpoo[i].end());

        if(is_sorted(inpoo[i])){

            std::string temp = "";
            fe(x, inpoo[i]){
                temp += std::to_string(x.index);
            }

            if(tracker.count(temp) == 0){
                tracker.insert(temp);
                ans++;
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
