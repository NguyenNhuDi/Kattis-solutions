#include<iostream>

using namespace std;

int main(){

    int N;
    int x;

    cin >> N;

    for(int i = 0; i < N; i++){

        cin >> x;

        int ans = 1;

        for(int i = 1; i <= x; i++){
            
            ans *= i;

            ans %= 10;


        }

        cout << ans << "\n";


    }

    return 0;
}
