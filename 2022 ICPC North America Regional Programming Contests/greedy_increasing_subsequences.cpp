//Greedy Increasing Subsequences

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

int bSearch(vector<vi> & arr, int x, int l, int r){
    int m = (l + r) / 2;

    if(m == 0){
        if(x > arr[m][SIZE(arr[m])-1]){
            return m;
        }
        else{
            return -1;
        }
    }
    
    if(l == r){
        if(x > arr[l][SIZE(arr[l])-1] && x <= arr[m-1][SIZE(arr[m-1])-1]){
            return l;
        }
        else{
            return -1;
        }
    }

    if(l > r){
        return -1;
    }


    if(x > arr[m][SIZE(arr[m])-1] && x <= arr[m-1][SIZE(arr[m-1])-1]){
        return m;
    }
    else if(x > arr[m][SIZE(arr[m])-1]){
        return bSearch(arr,x,l,m);
    }
    else{
        return bSearch(arr,x,m+1,r);
    }

}


int main(){

    int n;

    cin >> n;

    vector<vector<int>> all;
    all.push_back(vi(1,-1));
    cin >> all[0][0];
    n--;

    while(n--){
        int t;
        cin >> t;

        if(SIZE(all) < 3){
            bool flag = true;
            FOR(j,0,SIZE(all)){
                if(t > all[j][SIZE(all[j])-1]){
                    all[j].push_back(t);
                    flag = false;
                    break;
                }

            }

            if(flag){
                all.push_back(vi(1,t));
            }
            continue;
        }

        int index = bSearch(all,t,0,SIZE(all)-1);


        if(index < 0){
            all.push_back(vi(1,t));
        }
        else{
            all[index].push_back(t);
        }


    }

    cout << SIZE(all) << endl;
    for(const auto & x : all){
        for(const auto & y: x){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
