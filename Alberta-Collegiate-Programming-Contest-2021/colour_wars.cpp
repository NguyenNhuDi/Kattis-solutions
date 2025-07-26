// colour wars
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


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    unordered_map<int,int> input;

    FOR(i,0,n){
        int n; cin >> n;

        if (input.find(n) != input.end()){
            input[n]++;
        }
        else{
            input[n] = 1;
        }
    }

    int out = 0;

    fe(x, input){
        int count = x.second; int num = x.first;

        if(count <= num + 1){
            out += num + 1;
        }
        else{
            int mul = ceil(double(count) / double((num + 1)));

            out += mul* (num + 1);
        }
        
    }

    cout << out << endl;


    return 0;
}
