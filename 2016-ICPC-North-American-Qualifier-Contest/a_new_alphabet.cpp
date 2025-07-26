#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()

using namespace std;

typedef vector<int> vi;


int bSearch(char arr[], char x,int l, int r){
    if(l > r){
        return -1;
    }

    int m = (l + r) / 2;
    if (x == arr[m]){
        return m;
    }
    else if(x > arr[m]){
        return bSearch(arr, x, m+1,r);
    }
    else{
        return bSearch(arr,x,l,m-1);
    }
}

char oAlph[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
string nAlph[] = {"@","8","(","|)","3","#","6","[-]","|","_|","|<","1","[]\\/[]","[]\\[]","0","|D","(,)","|Z","$",
"']['","|_|","\\/","\\/\\/","}{","`/","2"};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string out;
    
    string input;
    
    while(getline(cin,input)){
        for(const auto & x : input){
            char y = tolower(x);
            int index = bSearch(oAlph,y,0,25);

            if(index >= 0){
                out += nAlph[index];
            }
            else{
                out += x;
            }
        }
    }

    cout << out << endl;
   

    return 0;
}
