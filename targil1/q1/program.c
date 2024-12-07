#include <stdio.h>
#include "headers.h"

  int main(){
    int num,indices,result;
    printf("give number and indices\n");    
    result=scanf("%d %d",&num,&indices);
    
    //if ctrl+d
    if(result==-1){
      printf("2\n");
      return 2;
    }
    
    //if result not numerical
    else if(result==0){
      printf("4\n");
      return 4;
    }  
            
    printf("%d\n",createNumByIdx(num,indices));
       
    return 0;
  }
  
 
  int createNumByIdx(int num,int indices){
    //if number negative
    if(num<0 || indices<0) return 3;
        
    int numLength=lengthOf(num); 
    int indicesLength=lengthOf(indices);
    int result=0;
        
    //if input invalid case 1
    int temp=indices;
    while(temp!=0){
      if(temp%10>=numLength) return 1;
      temp/=10;
    }

    for(int i=0;i<indicesLength;i++){
      result=result*10;

      int index=returnNumInPlace(indices,i);
     
      int indexToAdd=returnNumInPlace(num,index);
     
      result=result+indexToAdd;
    }
    return result; 
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
