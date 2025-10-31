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

    int n, c; std::cin >> n >> c;

    std::vector<int> inpoo(n + 1);
    FOR(i, 1, n+1) std::cin >> inpoo[i];

    std::vector<int> entry(n + 1);
    std::vector<int> exit(n + 1);

    int s = 1, e = 1;
    int total = inpoo[1] + inpoo[2];
    int turn = 1;
    while(s <= n){
        if(e + 1 > n){
            total -= inpoo[s];
            exit[s] = turn;
            s++;
        }
        else if(total > c){
            total -= inpoo[s];
            exit[s] = turn;
            s++;
        }
        else{
            e++;
            total += inpoo[e + 1];
            entry[e] = turn;
        }
        turn++;
    }
    FOR(i, 1, n + 1){
        std::cout << exit[i] - entry[i] << std::endl;
    }

    return 0;
}
