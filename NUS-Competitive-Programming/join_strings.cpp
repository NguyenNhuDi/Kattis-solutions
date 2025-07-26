#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()

using namespace std;

typedef vector<int> vi;

void p(vector<vi> &order, vector<string> &all, int l){
    cout << all[l];
    for(auto & i : order[l]){
        p(order,all,i);
    }
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<string> all(n);

    FOR(i,0,n){
        cin >> all[i];
    }

    vector<vi> order;
    order.assign(n,vi());
    int f, s, l = 0;
    FOR(i,0,n-1){
        cin >> f >> s;
        f--; s--;
        order[f].push_back(s);
        l = f;
    }

    p(order,all,l);
    cout << endl;

  
    return 0;
}
