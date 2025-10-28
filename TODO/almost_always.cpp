#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second

using namespace std;

inline void solve(const std::map<int, int> & inpoo){


    for(auto l = inpoo.begin(); l != inpoo.end(); l++){
        for (auto r = inpoo.begin(); r != inpoo.end(); r++){
            if (l == r) continue;

            int i = (*l).s;
            int j = (*r).s;

            if((*r).f % (*l).f == 0){
                std::cout << i + 1 << " " << j + 1 << std::endl;
                return;
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; std::cin >> n;

    std::map<int, int> inpoo;

    FOR(i, 0, n) {
        int in; std::cin >> in;
        inpoo[in] = i;
    }


    solve(inpoo);

    return 0;
}
