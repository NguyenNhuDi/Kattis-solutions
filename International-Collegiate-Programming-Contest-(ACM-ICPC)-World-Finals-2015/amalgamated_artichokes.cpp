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

    double p, a, b, c , d, n;

    cin >> p >> a >> b >> c >> d >> n;

    double price;

    double maxDec = 0;
    double maxNum =  p*(sin(a+b)+cos(c+d)+2);

    FORE(i,2,n){
        double curr = p*(sin(a*i+b)+cos(c*i+d)+2);
        if(maxNum > curr){
            if(maxDec < maxNum - curr){
                maxDec = maxNum - curr;
            }
        }
        else{
            maxNum = curr;
        }
    }

    printf("%.10f\n",maxDec);

    return 0;
}
