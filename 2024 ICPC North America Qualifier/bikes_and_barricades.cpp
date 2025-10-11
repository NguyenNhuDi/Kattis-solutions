#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second
#define OUTSIDE(a, b) (a < 0 && b < 0) || (a > 0 && b > 0)

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; std::cin >> n;

    std::vector<double> heights;

    FOR(i, 0, n){
        double x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        if(x1 == x2 || OUTSIDE(x1, x2)) continue;

        double m = (y1 - y2) / (x1 - x2);

        double b = y1 - m * x1;

        heights.push_back(b);
    }

    double mini = 200000;
    
    fe(x, heights){
        if (x > 0){
            mini = std::min(x, mini);
        }
    }
    std::cout << (mini == 200000 ? -1 : mini) << std::endl;

    return 0;
}
