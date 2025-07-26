//Class Field Trip
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

    string a, b;
    cin >> a >> b;

    string out = "";

    int i1, i2;
    i1 = i2 = 0;

    while(i1 < SIZE(a) && i2 < SIZE(b)){
        if(a[i1] < b[i2]){
            out += a[i1];
            i1++;
        }
        else{
            out += b[i2];
            i2++;
        }
    }

    while(i1 < SIZE(a)){
        out += a[i1];
        i1++;
    }

    while(i2 < SIZE(b)){
        out += b[i2];
        i2++;
    }

    cout << out << endl;
    return 0;
}
