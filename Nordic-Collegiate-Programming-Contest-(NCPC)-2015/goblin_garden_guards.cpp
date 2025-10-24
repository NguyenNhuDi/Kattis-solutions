#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second

using namespace std;

void kill_goblins(std::multiset<double> & gobs, double gx, double sx, double sy, double r){
    double dx = gx - sx;
    double t = r * r - dx * dx;
    if (t < 0) return;

    double dy = std::sqrt(t);
    double ymin = sy - dy;
    double ymax = sy + dy;

    auto it1 = gobs.lower_bound(ymin);
    auto it2 = gobs.upper_bound(ymax);
    gobs.erase(it1, it2);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; std::cin >> n;
    std::map<double, std::multiset<double>> goblins;

    FOR(i, 0, n){
        double x, y; std::cin >> x >> y;
        goblins[x].insert(y);
    }

    int m; std::cin >> m;
    FOR(i, 0, m){
        double sx, sy, r; std::cin >> sx >> sy >> r;

        double min_x = sx - r;
        double max_x = sx + r;

        auto left = goblins.lower_bound(min_x);
        auto right = goblins.upper_bound(max_x);

        for(auto it = left; it != right; it++){
            kill_goblins(it->s, (*it).f, sx, sy, r);
        }
    }

    ll out = 0;
    fe(x, goblins)
        out += x.s.size();

    std::cout << out << std::endl;

    return 0;
}
