//temperature confusion
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

long long gcd(long long a, long long b){
    if(b){
        return gcd(b, a % b);
    }
    else{
        return a;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long num, den;
    char op;

    cin >> num >> op >> den;

    if (den < 0){
        num *= -1;
        den *= -1;
    }

    long long div = gcd(num,den);

    num /= div;
    den /= div;

    long long top = 32 * den;

    num -= top;
    num *= 5;
    den *= 9;

    

    div = gcd(num,den);

    num /= div;
    den /= div;

    if(den < 0){
        num *= -1;
        den *= -1;
    }

    cout << num << "/" << den << endl;

    return 0;
}
