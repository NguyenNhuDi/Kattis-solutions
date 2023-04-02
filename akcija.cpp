#include<iostream>
using namespace std;

static void mergesort(int Array[], int left, int right);
static void merge(int Array[], int left, int mid, int right);
static void PrintArray(int Array[], int n);


static void mergesort(int Array[], int left, int right) {
  if (left < right) { 
    int mid = left + (right - left)/2;
    mergesort(Array, left, mid);
    mergesort(Array, mid+1, right);
    merge(Array, left, mid, right);
  }
}


static void merge(int Array[], int left, int mid, int right) {
 
  int n1 = mid - left + 1; 
  int n2 = right - mid;         
  int LeftArray[n1], RightArray[n2];
  for(int i=0; i < n1; i++) { 
     LeftArray[i] = Array[left + i];
  }
  for(int i=0; i < n2; i++) { 
     RightArray[i] = Array[mid + i + 1];
  }

  int x=0, y=0, z=left;
  while(x < n1 && y < n2) {
    if(LeftArray[x] < RightArray[y]) { 
      Array[z] = LeftArray[x]; 
      x++; 
    }
    else { 
      Array[z] = RightArray[y];  
      y++; 
    }
    z++;
  }

 
  while(x < n1) { 
     Array[z] = LeftArray[x];  
     x++;  
     z++;
  }


  while(y < n2) { 
    Array[z] = RightArray[y]; 
    y++;  
    z++; 
  }
}

int main (){

  int n;
  scanf("%d",&n);

  int *input = new int[n];

  for(int i = 0; i < n; i++){
      scanf("%d",&input[i]);
  }

  mergesort(input, 0, n-1);
  
  int sum = 0;
  int r = n % 3;

  if(r == 0){
   for(int i = 0; i < n; i++){
       if(i % 3 != 0){
           sum += input[i];
       }
  }
  }
  else if(r == 1){
         for(int i = 0; i < n; i++){
       if(i % 3 != 1){
           sum += input[i];
       }
         }
  }
  else{
         for(int i = 0; i < n; i++){
       if(i % 3 != 2){
           sum += input[i];
       }
         
  } 

  }


printf("%d\n",sum);
  
  return 0;
}
