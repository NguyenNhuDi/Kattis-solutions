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

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){

        int a,b;
        cin >> a >>b;

        vector<int> all(b);

        for(auto & x : all){
            cin >> x;
        }

        int lo = min(all[0], a-all[0]);
        int hi = max(all[0], a-all[0]);

        for(auto & x : all){
            lo = max(lo, min(x, a-x));
            hi = max(hi, max(x, a-x));
        }
        printf("%d %d\n",lo,hi);
    }



    return 0;
}
