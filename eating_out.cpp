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


bool cusSort(int a, int b){
    return a > b;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
        int m, a, b, c;
        cin >> m >> a >> b >> c;

        int max = 2 * m;

        if (a + b + c > max){
            cout << "impossible\n";
        }
        else{
            cout << "possible\n";
        }



    return 0;
}
