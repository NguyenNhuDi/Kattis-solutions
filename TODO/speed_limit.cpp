#include<iostream>

using namespace std;

int main(){

    int N;
    cin >> N;


    while(1){    
        if (N == -1){
            return 0;
        }

        int dis = 0;   
        int prevTime = 0; 
        for(int i = 0; i < N; i++){
            int s,t;

            cin >> s >> t;

            if(i == 0){
                dis += (s * t); 
            }
            else{
                dis += (s * (t - prevTime));
            }

            prevTime = t;
        }
        cout << dis << " miles\n";

        cin >> N;
    }



    return 0;
}
