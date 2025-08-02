#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07
#define pii pair<int,int>
#define f first
#define s second

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t n; std::cin >> n;

    FOR(_, 0, n){
        double sx, sy; std::cin >> sx >> sy;

        size_t m; std::cin >> m;

        bool good = false;
        FOR(i, 0, m){
            double x, y; std::cin >> x >> y;

            x -= sx;
            y -= sy;
            if(std::sqrt(powf(x, 2) + powf(y, 2)) <= 8)
                good = true;

        }

        if(good) std::cout << "light a candle" << std::endl;
        else std::cout << "curse the darkness" << std::endl;

    }

    return 0;
}
