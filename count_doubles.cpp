//count doubles
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


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int evens = 0, out = 0;

    vi all;


    //initial m values
    FOR(i,0,m){ 
        int t;
        cin >> t;
        if(t % 2 == 0){
            evens++;
        }
        all.push_back(t);

    }

    if(evens >= 2){
        out++;
    }
    
    int left = 1;
    FOR(i,m,n){
        int t;
        cin >> t;
        if(t % 2 == 0){
            evens++;
        }
        all.push_back(t);
        if(all[left -1] % 2 == 0){
            evens--;
        }

        if(evens >= 2){
            out++;
        }
        left++;
    }


    cout << out << endl;

    return 0;
}
