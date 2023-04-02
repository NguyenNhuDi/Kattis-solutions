#include <cstdio>
#include <cassert>



int main(){

    int c, res = scanf("%d", &c);
    assert(c > 0 && c <= 50);

    for(int j = 0; j < c; j++){
        
        float students , res = scanf("%f", &students); 
        
        assert(students > 0 && students <= 1000);

        float *scores = new float[(int)students];

        for(int i = 0; i < students; i++){
            scores[i], res = scanf("%f",&scores[i]);
            assert(scores[i] >= 0 && scores[i] <= 100);
            
        }
        float sum = 0;

        for(int i = 0; i < students; i++){
            sum += scores[i];
        }

        float average = sum / students;
        
        int higher = 0;

        for(int i = 0; i < students; i++){

            if(scores[i] > average){
                higher++;
            }
        }

        float test = higher / students;


        float pHigher = (higher / students) * 100;


        printf("%.3f",pHigher);
        printf("%% \n");

        delete [] scores;
        
    }


    return 0;
}
