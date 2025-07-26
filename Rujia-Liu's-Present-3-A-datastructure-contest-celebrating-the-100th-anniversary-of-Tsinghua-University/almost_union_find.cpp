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
#define vi vector<long long>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;

typedef long long ll;
typedef vector<unordered_set<ll>> vusi;


void join(ll x, ll y, vi & arr, vusi & sets){
    ll rX = arr[x]; 
    ll rY = arr[y];

    // in same set
    if(rX == rY) return;


    if(sets[rX].size() >= sets[rY].size()){
        fe(i, sets[rY]){
            sets[rX].insert(i);
            arr[i] = rX;
        }

        sets[rY].clear();
    }
    else{
        fe(i, sets[rX]){
            sets[rY].insert(i);
            arr[i] = rY;
        }

        sets[rX].clear();
    }

}

void mX_Y(ll x, ll y, vi & arr, vusi & sets){
    ll rX = arr[x];
    ll rY = arr[y];

    // in same set
    if(rX == rY) return;

    sets[rX].erase(x);
    sets[rY].insert(x);
    arr[x] = rY;
}

ll gSum(ll x, vusi & sets){
    ll out = 0; fe(i, sets[x]) out += i;

    return out;
}

ll gSize(ll x, vusi & sets){
    return sets[x].size();
}

void print(vi & arr, vusi & sets){
    FOR(i,1, sets.size()){
        cout << "num: " << i << " | root: " << arr[i] << " | in set: ";

        fe(x, sets[i]) cout << x << " ";

        cout << endl;
    }
    cout << "\n==========\n\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m; 

    while(cin >> n >> m){

        //hold the position of the set
        vi nums(n+1);
        vusi sets(n+1);

        FOR(i,1,n+1){
            sets[i] = {i};
            nums[i] = i;
        }


        while(m--){
            ll op; cin >> op;

            if(op == 1){
                ll x, y; cin >> x >> y;

                join(x, y, nums, sets);
            }
            else if(op == 2){
                ll x, y; cin >> x >> y;

                mX_Y(x, y, nums, sets);
            }
            else{
                ll x; cin >> x;

                cout << gSize(nums[x], sets) << " " << gSum(nums[x], sets) << endl;

            }

            // print(nums, sets);
        }
    }


    return 0;
}
