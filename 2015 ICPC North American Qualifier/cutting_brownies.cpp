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

#define outLoose(x) std::cout << x << " cannot win" << std::endl;
#define outWin(x) std::cout << x << " can win" << std::endl;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    FOR(i,0,n){
        int v, h;
        string name;

        std::cin >> v >> h >> name;

        int v2 = log2(v);
        int h2 = log2(h);

        if(name == "Vicky"){
            if(v2 > h2){
                outWin(name);
            }
            else{
                outLoose(name);
            }
        }
        else{
            if(h2 > v2){
                outWin(name);
            }
            else{
                outLoose(name);
            }
        }

    }


    return 0;
}