#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        int index, K;

        cin >> index >> K;

        int ans = 2;
        for(int j = 1; j < K; j++){
            ans += (2 + j);
        }

        cout << index << " " << ans <<"\n";

    }

    return 0;
}
