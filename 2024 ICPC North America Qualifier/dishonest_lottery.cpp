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
    std::vector<int> storage(51, 0);

    FOR(i, 0, n * 10){
        int a, b, c, d, e;
        std::cin >> a >> b >> c >> d >> e;
        storage[a]++;
        storage[b]++;
        storage[c]++;
        storage[d]++;
        storage[e]++;
    }

    std::vector<int> out;

    FOR(i, 1, 51){
        if(storage[i] > 2 * n)
            out.push_back(i);
    }

    std::sort(out.begin(), out.end());

    fe(x, out)
        std::cout << x << " ";

    if(out.size() == 0)
        std::cout << -1;

    std::cout << std::endl;


    return 0;
}
