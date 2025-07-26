#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    int sum = 0;
    int counter = 0;
    for(int i = 0; i < M; i++){
        string event;
        int num;

        cin >> event >> num;

        if(event == "enter"){
            sum += num;

            if(sum > N){
                sum -= num;
                counter++;
            }
        }
        else{
            sum -= num;
        }
    }
    
    cout << counter << endl;
    return 0;
}
