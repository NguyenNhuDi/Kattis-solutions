//Array Smoothening

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>

using namespace std;

typedef long long ll;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    if(k == n){
        cout << 0 << endl;
        return 0;
    }

    map<int,int> all;
    vector<ll> values(n,0);

    ll index = 0;
    ll sum = 0;
    FOR(i,0,n){
        int t;

        cin >> t;
        sum += t;
        if(all.count(t)){
            values[all[t]]++;
        }
        else{
            all.insert(pair<int,int>(t,index));
            values[all[t]]++;
            index++;
        }
    }

    sort(values.begin(),values.end(), greater<>());
    
    index = 0;
    while(k > 0){
        if(values[index] <= values[index + 1]){
            index++;
            continue;
        }
        FORE(i,0,index){
            if(k<=0){
                break;
            }
            values[i]--;
            k--;

        }

    }
    sort(values.begin(),values.end(), greater<>());
    cout << values[0] << endl;
    return 0;
}
