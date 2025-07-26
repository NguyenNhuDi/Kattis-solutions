#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<climits>
#include<queue>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()

using namespace std;

typedef vector<int> vi;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;

    cin >> x >> y;

    if(x > 0 && y > 0){
        cout << 1 << endl;
    }
    else if (x < 0 && y > 0){
        cout << 2 << endl;
    }
    else if (x < 0 && y < 0){
        cout << 3 << endl;
    }
    else{
        cout << 4 << endl;
    }

    return 0;
}
