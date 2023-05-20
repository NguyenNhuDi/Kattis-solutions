// successful zoom
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
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;

int find_k(int k, vi & arr, int n){
    if(n/k < 2){
        return -1;
    }

    
    int prevVal = -1;
    for(int i = k; i <= n; i += k){
        int currVal = arr[i];
        if(currVal <= prevVal){
            return find_k(k+1,arr,n);
        }

        prevVal = currVal;
    }
    return k;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vi input;
    input.push_back(-1);

    FORE(i,1,n){
        int t; cin >> t;
        input.push_back(t);
    }

    int ans = find_k(1,input,n);

    if(ans > 0){
        cout << ans << endl;
    }
    else{
        cout << "ABORT!\n";
    }
    return 0;
}
