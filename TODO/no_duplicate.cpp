#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

int bSearch(vector<int> a, int x){
    int size = a.size();
    int l = 0;
    int r = size - 1;
    int result = -1;
    while(l <= r){
        int m = (l + r) /2;
        if(a[m] <= x){
            l = m + 1;
            result = m;
        }
        else{
            r = m -1;
        }
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> all;

    string input;

    while(cin >> input){
        if(all.count(input)){
            cout << "no" <<"\n";
            return 0;
        }
        else{
            all.insert(input);
        }

    }
    cout << "yes" << "\n";
    return 0;
}
