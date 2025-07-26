#include <cstdio>
#include <cassert>

int main(){

    struct node{
        int min,max;
    };

    int n;

    scanf("%d",&n);

    node *all = new node[n];

    int room = n;

    for(int i = 0; i < n; i++){

        scanf("%d %d", &all[i].min, &all[i].max);

    }

    for(int i = 0; i < n; i++){

        for(int j = 0; j < (n - 1); j++){
            
            if (all[j].min > all[j + 1].min){
                node temp;
                temp.min = all[j].min;
                temp.max = all[j].max; 

                all[j] = all[j + 1];
                all[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){

        int a = all[i].min;
        int b = all[i].max;

        for(int j = i + 1; j < n; j++){
            
            int c = all[j].min;
            int d = all[j].max;

            if ((a <= c && c <= b)){
                room--;

                if (a < c){
                    all[j].min = a;
        
                }
                else if(a > c){
                    all[i].min = c;
                    a = c;
                }
                
                if(b > d){
                    all[i].max = d;
                    b = d;
                }
                else if(b < d){
                    all[j].max = b;
                }
                break;
            }

            else if ((a <= d && d <= b)){
                room--;

                if(b > d){
                    all[i].max = d;
                    b = d;
                }
                else if(b < d){
                    all[j].max = b;
                }
                
                if (a < c){
                    all[j].min = a;
        
                }
                else if(a > c){
                    all[i].min = c;
                    a = c;
                }
                break;
            }
        }
    }

    // for(int i = 0; i < n; i ++){
    //     printf("\n%d %d\n",all[i].min,all[i].max);
    // }

    delete [] all;

    printf("%d\n",room);

    return 0;
}


