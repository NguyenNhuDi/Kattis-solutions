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

    int sum = 0;
    for(int i = 0; i < N; i++){
        int temp;

        cin >> temp;
        if (i == 0){
            sum += temp;
        }
        else{
            sum += temp - 1;
        }
        

    }

    cout << sum << endl;

    return 0;
}
