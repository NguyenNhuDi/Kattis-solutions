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
#define fe(x,y) for(const auto & x : y)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;

bool desSort(pair<int, int> a, pair<int, int> b){
    if (a.second != b.second){
        return a.second < b.second;
    }
    else{
        return a.first < b.first;
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;

    unordered_map<int, int> input;

    FOR(i,0,k){
        input[i+1] = 0;
    }

    FOR(i,0,n){
        int t; cin >> t;
        input[t]++;

    }

    vector<pair<int, int>> cCounter;

    fe(x, input){
        cCounter.push_back(pair<int,int>(x.first, x.second));
    }

    sort(cCounter.begin(), cCounter.end(), desSort);

    int min = cCounter[0].second;
    int i = 0;

    queue<int> out;

    while(cCounter[i].second == min){
        out.push(cCounter[i++].first);
    }

    cout << out.size() << endl;
    while(!out.empty()){
        cout << out.front() << " ";
        out.pop();
    }
    cout << endl;


    return 0;
}
