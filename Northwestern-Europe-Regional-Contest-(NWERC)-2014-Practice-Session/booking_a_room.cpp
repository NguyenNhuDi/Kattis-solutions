#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, n;

    cin >> r >> n;
    int f;

    if (r == n){
        cout << "too late \n";
    }

    set<int> full;

    for (int i = 1; i <= n; i++){
        cin >> f;
        full.insert(f);
    }

    for(int i = 1; i <= r; i++){
        if(full.count(i) == 0){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
