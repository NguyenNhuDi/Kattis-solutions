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


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, n;
    cin >> x >> y >> n;
    


    for(int i = 1; i <= n; i++){
        if(i % x == 0 && i % y == 0){
            cout << "FizzBuzz\n";
        }
        else if(i % x == 0){
            cout << "Fizz\n";
        }
        else if(i % y == 0){
            cout << "Buzz\n";
        }
        else{
            cout << i << endl;
        }
    }
    

    return 0;
}
