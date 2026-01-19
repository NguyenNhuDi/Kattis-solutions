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
    std::vector<std::pair<int,int>> arr(n, {-1, 1});

    FOR(i, 1, n + 1){
        int x; std::cin >> x;
        arr[i] = {x, i + 1};
    }

    std::sort(arr.begin(), arr.end(), 
        [](const std::pair<int, int> & l, std::pair<int,int> & r)
            {return l.f < r.f;}
    );

    fe(x, arr) std::cout << x.s << " ";
    std::cout << std::endl;

    return 0;
}
