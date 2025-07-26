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

typedef long long ll;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set<ll> used_index;

    ll n; cin >> n;


    map<pair<ll, ll>, int> quests;

    ll index = 0;
    FOR(i,0,n){
        string op; cin >> op;
        if (op == "add"){
            pair<ll, ll> cQuest; cin >> cQuest.first >> cQuest.second;

            if(quests.find(cQuest) != quests.end()){
                quests[cQuest]++;
            }
            else{
                quests[cQuest] = 1;
            }
        }   
        else{
            ll x; cin >> x;
            ll out = 0;

            while(1){
                pair<ll, ll> temp = {x, LLONG_MAX};

                auto it = quests.upper_bound(temp);

                if(it == quests.begin()) break;

                --it;

                out += it->first.second;
                x -= it->first.first;

                if(--it->second <= 0) quests.erase(it);

            }
            cout << out << endl;
        }

    }

    return 0;
}
