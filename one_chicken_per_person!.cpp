//One Chicken Per Person!

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

    int n, m, diff;
    cin >> n >> m;

    diff = m - n;

    if(diff < -1){
        cout << "Dr. Chaz needs " << diff * -1 << " more pieces of chicken!\n";
    }
    else if (diff < 0){
        cout << "Dr. Chaz needs " << diff * -1 << " more piece of chicken!\n";
    }
    else if(diff > 1){
        cout << "Dr. Chaz will have " << diff << " pieces of chicken left over!\n";
    }
    else{
        cout << "Dr. Chaz will have " << diff << " piece of chicken left over!\n";
    }

    return 0;
}
