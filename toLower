//toLower
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>
#include<cstring>

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

    int n, p;

    cin >> n >> p;

    int pass = n;

    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = 0; j < p; j++){
            string t;
            cin >> t;

            for(int k = 1; k < SIZE(t); k++){
                if(isupper(t[k]) && flag == true){
                    pass--;
                    flag = false;
                    break;
                }
            }
        }
    }

    cout << pass << endl;

    return 0;
}
