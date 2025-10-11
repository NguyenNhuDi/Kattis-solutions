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

    int out = 0;
    FOR(i, 0, n){
        int num; std::cin >> num;
    
        out += num & 1;
    }   

    std::cout << out << std::endl;

    return 0;
}
