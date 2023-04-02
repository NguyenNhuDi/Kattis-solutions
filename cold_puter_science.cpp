#include<iostream>
using namespace std;

int main(){
    int N;
    cin >>N;
    
    int counter = 0;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        
        if(temp < 0){
            counter++;
        }
    }
    cout << counter <<endl;
    
    return 0;
}
