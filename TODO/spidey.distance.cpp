//spidey distance

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>

#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define FORD(i,a,b) for(ll i = b; i >= a; i--)
#define FORE(i,a,b) for(ll i = a; i <=b; i++)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>

using namespace std;

typedef long long ll;


ll gcd(ll a, ll b){

    if (b > a){
        ll temp = a;
        a = b;
        b = temp;
    }

    if(a == 0){
        return b;
    }
    else if(b == 0){
        return a;
    }

    ll remainder = a % b;

    return gcd(b,remainder);

}


int main(){
    ll t, s;
    cin >> t >> s;

        ll mid = floor(s/1.5);

        ll sDist, tDist;
        sDist = tDist = 0;

        ll currSDist = s;
        ll diff = 0;

        FORE(i,0,mid){
            if(i % 2){
                currSDist--;
            }
            sDist += currSDist + 1;

            diff = (currSDist + 1) - ((t + 1) - i);

            if(diff <= 0){
                               
                tDist += currSDist + 1;
                
            }
            else if(diff > 0 && diff < (currSDist +1)){
                
                tDist += currSDist+ 1 - diff;
                
            }
        }

        FORE(i,mid+1,s){
            if(s % 3 == 0){
                currSDist -= 2;
            }
            else{
                if(i == mid+1){
                    currSDist--;
                }
                else{
                    currSDist -= 2;
                }
            }

            sDist += currSDist + 1;

            ll tPost = t+1 - i;


            diff = currSDist + 1 - ((t + 1) - i);

            if(diff <= 0){

                tDist += currSDist + 1;

            }
            else if(diff > 0 && diff < (currSDist +1)){

                tDist += currSDist + 1 - diff;
                
            }

        }
        // cout << tDist << endl << sDist << endl;

        if(t >= s){
            tDist *= 4;
            tDist -= (s+1)*3;
            tDist -= s;
        }
        else{
            tDist *= 4;
            tDist -= (t + 1) *3;
            tDist -= t;
        }


        sDist *= 4;
        sDist -= (s+1)*3;
        sDist -= s;


        
        ll GCD = gcd(tDist,sDist);
        sDist /= GCD;
        tDist /= GCD;

        if(sDist == 1){
            cout << tDist << endl;
            return 0;
        }

        cout << tDist << "/"<<sDist << endl;
        return 0;

}
