#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define fe(x,y) for(auto & x : y)
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q; cin >> n >> q;

    map<int,int> aNums;

    FOR(i,0,n){
        int cNum; cin >> cNum;

        if(aNums.find(cNum) != aNums.end()){
            aNums[cNum]++;
        }
        else{
            aNums[cNum] = 1;
        }
    }

    FOR(i,0,q){
        int query, x; cin >> query >> x;

        if(aNums.empty()){
            cout << -1 << endl;
            continue;
        }

        if(query == 1){
            auto it = aNums.upper_bound(x);

            if(it == aNums.end()){
                cout << -1 << endl;
            } 
            else if(it == aNums.begin()){
                cout << aNums.begin()->first << endl;

                if(--aNums.begin()->second <= 0) aNums.erase(aNums.begin());

            }
            else{
                cout << it->first << endl;

                if(--it->second <= 0) aNums.erase(it);
            }
        }
        else{

            auto it = aNums.lower_bound(x);


            if(it == aNums.end()){
                auto it = --aNums.end();
                cout << it->first << endl;

                if(--it->second <= 0) aNums.erase(it);
            }
            else{
                // found an in between
                if(it->first > x){
                    it--;

                    if(it->second <= 0){
                        cout << -1 << endl;
                        continue;
                    }

                    if(it->first <= x){
                        cout << it->first << endl;

                        if(--it->second <= 0) aNums.erase(it);
                    }
                    else{
                        cout << -1 << endl;
                    }
                }
                else if(it->first == x){
                    cout << it->first << endl;
                    if(--it->second <= 0) aNums.erase(it);

                }
            }
        }
    }

    return 0;
}
