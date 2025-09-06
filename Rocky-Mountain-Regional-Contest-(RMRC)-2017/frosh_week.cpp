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

    int n, m; std::cin >> n >> m;

    std::vector<int> tasks(n), quite(m);

    FOR(i,0,n) std::cin >> tasks[i];
    FOR(i,0,m) std::cin >> quite[i];

    std::sort(tasks.begin(), tasks.end());
    std::sort(quite.begin(), quite.end());

    int ti = 0, qi = 0;

    while(ti < n && qi < m){
        if(tasks[ti] <= quite[qi]){
            ti++;
        }
        qi++;
    }
    std::cout << ti << std::endl;
    return 0;
}
