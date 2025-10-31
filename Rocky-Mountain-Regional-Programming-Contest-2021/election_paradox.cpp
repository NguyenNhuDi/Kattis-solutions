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

    int n; std::cin >> n;

    std::vector<int> inpoo(n);
    FOR(i, 0, n) std::cin >> inpoo[i];
    std::sort(inpoo.begin(), inpoo.end(), [](const int & l, const int & r) {return l > r;});
    
    int out = 0;


    FOR(i, 1, n + 1){
        if(i <= n / 2){
            out += inpoo[i - 1];
        }
        else{
            out += inpoo[i - 1] / 2;
        }
    }
    std::cout << out << std::endl;

    return 0;
}
