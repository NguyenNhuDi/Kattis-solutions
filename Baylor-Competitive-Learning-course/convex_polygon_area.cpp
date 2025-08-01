#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define ll long long
#define uint unsigned int
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

    uint n; std::cin >> n;

    FOR(i, 0, n){
        uint x; std::cin >> x;

        std::vector<std::pair<double, double>> cords(x + 1);

        FOR(j, 0, x) std::cin >> cords[j].f >> cords[j].s;

        cords[x] = cords[0];

        double l = 0, r = 0;
        FOR(j, 0, x + 1){
            l += cords[j].f * cords[(j + 1) % (x + 1)].s;
            r += cords[j].s * cords[(j + 1) % (x + 1)].f;
        }

        std::cout << 0.5 * (l - r) << std::endl;

    }
    return 0;
}
