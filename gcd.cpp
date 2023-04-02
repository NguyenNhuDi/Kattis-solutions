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

int gcd(int a, int b){

    if (b > a){
        int temp = a;
        a = b;
        b = temp;
    }

    if(a == 0){
        return b;
    }
    else if(b == 0){
        return a;
    }

    int remainder = a % b;

    return gcd(b,remainder);

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    cin >> a >> b;

    cout << gcd(a,b) << endl;

    return 0;
}
