//Smallest Calculated Value

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

typedef unsigned int ui;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ui x, y, z;
    cin >> x >> y >> z;

    ui out = UINT32_MAX;

    ui curr = (x * y) * z;
    if (curr < out && curr >= 0){
        out = curr;
    }
    curr = (x * y) / z;
    if (curr < out && curr >= 0 && ((x * y) % z == 0)){
        out = curr;
    }
    curr = (x * y) + z;
    if (curr < out && curr >= 0){
        out = curr;
    }
    curr = (x * y) - z;
    if (curr < out && curr >= 0){
        out = curr;
    }

    curr = (x / y) * z;
    if (curr < out && curr >= 0 && x % y == 0){
        out = curr;
    }
    curr = (x / y) / z;
    if (curr < out && curr >= 0 && ((x / y) % z == 0) && (x % y == 0)){
        out = curr;
    }
    curr = (x / y) + z;
    if (curr < out && curr >= 0 && x % y == 0){
        out = curr;
    }
    curr = (x / y) - z;
    if (curr < out && curr >= 0 && x % y == 0){
        out = curr;
    }

    curr = (x + y) * z;
    if (curr < out && curr >= 0){
        out = curr;
    }
    curr = (x + y) / z;
    if (curr < out && curr >= 0 && ((x + y) % z == 0)){
        out = curr;
    }
    curr = (x + y) + z;
    if (curr < out && curr >= 0){
        out = curr;
    }
    curr = (x + y) - z;
    if (curr < out && curr >= 0){
        out = curr;
    }

    curr = (x - y) * z;
    if (curr < out && curr >= 0){
        out = curr;
    }
    curr = (x - y) / z;
    if (curr < out && curr >= 0 && ((x - y) % z == 0)){
        out = curr;
    }
    curr = (x - y) + z;
    if (curr < out && curr >= 0){
        out = curr;
    }
    curr = (x - y) - z;
    if (curr < out && curr >= 0){
        out = curr;
    }

    cout << out << endl;

    return 0;
}
