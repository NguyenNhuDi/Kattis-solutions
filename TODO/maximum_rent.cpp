//maximum rent

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

typedef long long ll;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll max = 0;
    ll a, b, m, s;

    cin >> a >> b >> m >> s;

    ll x, y;



    //priotize x
    if(a > b){
        x = m -1;
        y = 1;
        
        while(x + y <= m && y >= 1 && x >= 1){
            ll price = a * x + b * y;
            if((2 * x) + y >= s){
                if(price > max){
                    max = price;
                }
            }

            x--;
            y++;
        }   
    }
    //priotize y
    else{
        y = m - 1;
        x = 1;

        while(x + y <= m && y >= 1 && x >= 1){
            ll price = a * x + b * y;
            if((2 * x) + y >= s){
                if(price > max){
                    max = price;
                }
            }
            y--;
            x++;
        }  
    }

    
    cout << max << endl;


    return 0;
}
