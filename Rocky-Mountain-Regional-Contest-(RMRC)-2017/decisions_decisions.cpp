#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second

using namespace std;
#define pii std::pair<int, int>

inline pii solve(const int & n, std::vector<int> p, const std::vector<int> & inpoo){

    
    if(p.size() == n){
        uint32_t idx = 0;

        FOR(i, 0, n){
            idx |= (p[i] << i);
        }

        return {inpoo[idx], 1};
    }

    p.push_back(0);    
    pii l = solve(n, p, inpoo);
    p.back() = 1;
    pii r = solve(n, p, inpoo);

    if(l.f == r.f && l.f != -1){
        return {l.f, 1};
    }

    return {-1, l.s + r.s + 1};

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; std::cin >> n;
    std::vector<int> inpoo((1 << n));
    FOR(i, 0, (1 << n)) std::cin >> inpoo[i];

    pii ans = solve(n, {}, inpoo);
    std::cout << ans.s << std::endl;

    return 0;
}
