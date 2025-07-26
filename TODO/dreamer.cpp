#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>

using namespace std;

struct Date{

    int d, m , y;

};

bool isLeap(int year){
return (((year % 4 == 0) &&
         (year % 100 != 0)) ||
         (year % 400 == 0));
}

bool isValidDate(Date  const &date){
    if ( date.y < 2000){
        return false;
    }
    
    if (date.m < 1 || date.m > 12){
        return false;
    }

    if (date.d < 1 || date.d > 31){
         return false;
    }

    if (date.m == 2){
        if (isLeap(date.y)){
            return (date.d <= 29);
        }
        else{
            return (date.d <= 28);
        }
    }
 
    if (date.m == 4 || date.m == 6 ||
        date.m == 9 || date.m == 11){
            return (date.d <= 30);
        }
 
    return true;
}

int toYear(vector<int> a, vector<int> s){
    return a[s[4]] * 1000 + a[s[5]] * 100 + a[s[6]] * 10 + a[s[7]]; 
}
int toMonth(vector<int> a, vector<int> s){
    return a[s[2]] * 10 + a[s[3]];
}
int toDay(vector<int> a, vector<int> s){
    return a[s[0]] * 10 + a[s[1]];
}

bool sortDate(const string f, const string s){
    int y1 = (f[6] - '0') * 1000 + (f[7] - '0') * 100 + (f[8] - '0') * 10 + (f[9] - '0');
    int y2 = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
    int m1 = (f[3] - '0') * 10 + (f[4] - '0');
    int m2 = (s[3] - '0') * 10 + (s[4] - '0');
    int d1 = (f[0] - '0') * 10 + (f[1] - '0');
    int d2 = (s[0] - '0') * 10 + (s[1] - '0');
    if(y1 < y2){
        return true;
    }
    if(y1 == y2 && m1 < m2){
        return true;
    }

    if(y1 == y2 && m1 == m2 && d1 < d2){
        return true;
    }
    return false;
}

int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){

        // vector<Date> all;
        vector<int> input;
        vector<int> starting;
        set<string> all;

        for(int j = 0; j < 8; j++){
            starting.push_back(j);
        }

        string d, m , y;
        
        cin >> d >> m >> y;  

        for(int j = 0; j < 2; j++){
            input.push_back(d[j] - '0');
            input.push_back(m[j] - '0');
        }
        for(int j = 0; j < 4; j++){
            input.push_back(y[j] - '0');
        }
 
        do{
            Date temp;

            temp.d = toDay(input,starting);
            temp.m = toMonth(input,starting);
            temp.y = toYear(input,starting);
            
            if(isValidDate(temp)){

                string date = to_string(input[starting[0]]) 
                + to_string(input[starting[1]]) + " "
                + to_string(input[starting[2]]) 
                + to_string(input[starting[3]]) + " "
                + to_string(input[starting[4]]) 
                + to_string(input[starting[5]]) 
                + to_string(input[starting[6]]) 
                + to_string(input[starting[7]]);

                all.insert(date);
            }
        }
        while(next_permutation(starting.begin(), starting.end()));

        vector<string> test(all.begin(), all.end());
        sort(test.begin(), test.end(), sortDate);

        if(all.size() == 0){
            cout << all.size() << "\n";
        }
        else{
            cout << all.size() << " " << test[0] << "\n";
        }
    }
    return 0;   
}
