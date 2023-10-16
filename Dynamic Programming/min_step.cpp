#include<bits/stdc++.h>
using namespace std; 

int minStep(int n){
  if(n == 1) {
    
  }
    return 0;
  
  int subOne = INT_MAX, divTwo = INT_MAX, divThree = INT_MAX;
  
  //If number is greater than or equal to 2, subtract one
  if(n >= 2)
    subOne = 1 + minStep(n-1);
  
  //If divsible by 2, divide by 2
  if(n % 2 == 0)
    divTwo = 1 + minStep(n/2);
  
  //If divisible by 3, divide by 3
  if(n%3 == 0)
    divThree = 1 + minStep(n/3);
  
  //Return the most optimal answer
  return min(subOne, min(divTwo, divThree));
}

int main(){
  int n = 10;
  vector<int>
  cout<<minStep(n);
}
