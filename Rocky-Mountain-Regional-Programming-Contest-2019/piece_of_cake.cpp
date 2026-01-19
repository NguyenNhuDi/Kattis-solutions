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

    int s, h, v; std::cin >> s >> h >> v;

    std::cout << (std::max(s-h, h) * std::max(s-v, v) * 4) << std::endl; 

    return 0;
}
