#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

typedef long long ll;

string table_ones[] = {"0","I","II","III","VI","V","IV","IIV","IIIV","XI"};
string table_tens[] = {"0","X","XX","XXX","LX","L","XL","XXL","XXXL","CX"};
string table_hundreds[] = {"0","C","CC","CCC","DC","D","CD","CCD","CCCD","MC"};
vector<string> all;
vector<string> rAll;

string toRoman(ll input){
    ll counter = 0;
    string output = "";
    while(counter <=2){
        ll remainder = input % 10;

        if(counter == 0){
            if(remainder != 0){
                output += table_ones[remainder];
            }
        }
        else if(counter == 1){
            if(remainder != 0){
                output += table_tens[remainder];
            }
        }
        else if(counter == 2){
            if(remainder != 0){
                output += table_hundreds[remainder];
            }
        }

        counter++;
        input /= 10;
    }
    reverse(output.begin(),output.end());
    return output;
}

void makeTable(){

    for(int i = 1; i<=999;i++){
        string temp;
        temp = toRoman(i);
        if(temp[0] == 'X' || temp[0] == 'V'){
            rAll.push_back(temp);
        }
        else{
            all.push_back(temp);
        }    
    }

    sort(all.begin(),all.end());
    sort(rAll.begin(),rAll.end());
    reverse(rAll.begin(),rAll.end());
    
}

int find(vector<string> a, string input){
    for(int i = 0; i < a.size(); i++){
        if(a[i] == input){
            return i;
        }
    }
    return -1;  
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    makeTable();
    ll N;
    cin >> N;

    for(ll i = 0; i < N; i++){

        ll input;
        cin >> input;

        string place;


        int counter = input /1000;
        int rSize =rAll.size();

        place = toRoman(input);
        if(place[0] == 'X' || place[0] == 'V'){
            int pos = find(rAll,place) + 1;
            cout << -1 * (counter*rSize + pos) << endl;
        }  
        else{
            ll pos = find(all,place) + 1;
            cout << counter * (1 + all.size()) + pos << endl;
        }
        
    }

    return 0;
}
