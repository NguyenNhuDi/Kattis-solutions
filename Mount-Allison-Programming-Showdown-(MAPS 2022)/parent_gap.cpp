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



int findDay(int m,int d,int y){y-=m<3;return(y+y/4-y/100+y/400+"-bed=pen+mad."[m]+d)%7;}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int year;
    cin >> year;

    int may1 = findDay(5,1,year);
    int june1 = findDay(6,1,year);

    int maySecondSunday = 1 +(7*1) + ((7-may1)%7);
    int juneThirdSunday = 1 +(7*2) + ((7-june1)%7);
    
    int diff = 31 - maySecondSunday + juneThirdSunday;

    if(diff / 7 == 6){
        cout << "6 weeks\n";
    }
    else{
        cout << "5 weeks\n";
    }

    return 0;
}
