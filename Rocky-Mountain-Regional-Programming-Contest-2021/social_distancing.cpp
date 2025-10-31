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

    int s, n; std::cin >> s >> n;

    std::vector<int> seats(s, 0);

    FOR(i, 0, n){
        size_t in; std::cin >> in;
        seats[--in] = 1;
    }
    int out = 0;
    FOR(i, 0, s){


        if(seats[i]) continue;

        if(i == 0){
            if(!seats[s - 1] && !seats[1]){
                out++;
                seats[i] = 1;
            }
        }
        else{
            if(!seats[i - 1] && !seats[(i + 1) % s]){
                out++;
                seats[i] = 1;
            }
        }
    }

    std::cout << out << std::endl;

    return 0;
}
