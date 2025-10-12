#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second

using namespace std;

bool solve(int id, std::vector<std::vector<int>> & am){
    int n = am.size();

    // check if the fella has >= 2 vertices
    // also get the neighbours

    std::vector<int> neighbours;

    FOR(i, 0, n){
        if(am[id][i] == 1)
            neighbours.push_back(i);
    }
    
    if (neighbours.size() <= 1)
        return false;

    fe(i, neighbours){
        fe(j, neighbours){

            if(i == j) continue;
            
            // if one of the neighbour is connected to another neighbour
            if(am[i][j] == 1)
                return true;
        }
    }

    return false;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    while(std::cin >> n){
        if (n < 0)
            break;

        std::vector<std::vector<int>> am(n, std::vector<int>(n));

        FOR(i, 0, n){
            FOR(j, 0, n)
                std::cin >> am[i][j];
        }

        std::vector<int> out;
        FOR(i, 0, n){
            if(!solve(i, am))
                out.push_back(i);
        }

        std::sort(out.begin(), out.end());

        fe(x, out) std::cout << x << " ";
        std::cout << "\n";
    }
    std::cout.flush();
    return 0;
}
