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

    int n, w; std::cin >> n >> w;

    std::vector<int> inpoo(n);
    FOR(i,0,n) std::cin >> inpoo[i];

    size_t out = 0;

    FOR(i, 0, n){
        int charge = w * 60;
        size_t curr = 0;
        FOR(j, i, n){
            charge -= inpoo[j] * 2;

            if(charge < 0)
                break;
            else
                curr++;
        }

        out = std::max(out, curr);
    }

    std::cout << out << std::endl;

    return 0;
}
