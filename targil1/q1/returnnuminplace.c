 #include "headers.h"
  //return the number in the index that was given.
  int returnNumInPlace(int num,int index){
    int length=lengthOf(num);
      
    for(int i=length-1;i>=0;i--){  
      if(index==i) return num%10;
      num/=10;      
    }   
  }
