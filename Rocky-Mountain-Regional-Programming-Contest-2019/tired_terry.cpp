#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second

using namespace std;

int solve_same(const string & inpoo, const int & d){
    int s = 0;
    int ans = 0;
    FOR(i, 0, inpoo.size()){
        if(!(inpoo[i] == 'Z' && d == 1))
            ans++;

    }
    return ans;
}

int main(){

    int n, p, d; std::cin >> n >> p >> d;
    string inpoo; std::cin >> inpoo;

    if(p == 1){
        std::cout << solve_same(inpoo, d) << std::endl;
    }
    else{

        int s = 0;
        int l = 0, r = 0;

        while(r < l + p ){
            if(inpoo[r] == 'Z'){
                s++;
            }
            r++;
        }

        int ans = (s < d) ? 1 : 0;
        l++; r++;
        while(l < n){
            if(inpoo[(r - 1) % n] == 'Z')
                s++;
            
            if(l != r){
                if(inpoo[l - 1] == 'Z')
                    s--;
            }
            if(s < d)
                ans++;
            l++; r++;
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
