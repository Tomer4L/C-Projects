#include <stdio.h>

int sumDigits(int); 
int searchOnce(int,int); 
int countAll(int,int);
int getMax(int);
int sort(int);
int findMinDigit(int);
int removeMinDigit(int,int);
int sort(int num);  
int countNumLength(int);
int reverse(int);
int merge(int,int);
int make10InThePowerOfCount(int);
void adjacentHanoi(int,int,int,int);
      
   
  //question 9     
  int main(){
  
   int sum=sumDigits(123456);
   printf("%d\n",sum);
   
   int search=searchOnce(122456,2);
   printf("%d\n",search);
   
   int count=countAll(123400,0);
   printf("%d\n",count);
   
   int max=getMax(729456);
   printf("%d\n",max);
   
   int sor=sort(1434);
   printf("%d\n",sor);
   
   int rev=reverse(987654321);
   printf("%d\n",rev);
   
   int mer=merge(4321,8765);
   printf("%d\n",mer);
   
    printf("You have 3 towers in this game, you can move only the top ring in each tower and only to a towers that are near each other, for example you can move the smallest ring in the first tower to the second tower but you can not move the first ring in the first tower to the third tower, you need to go through the second tower to get to the third tower.\n");
   adjacentHanoi(4,1,2,3);
  
  return 0;
  }
  
  //question 1
  int sumDigits(int num){

   if(num/10==0) return num;
   
   return num%10 + sumDigits(num/10); 
  }
  
  //question 2
  int searchOnce(int num,int digit){
   if(num%10==digit) return 1;
   if(num/10==0) return 0;

   return searchOnce(num/10,digit);  
  }
  
  //question 3
  int countAll(int num,int digit){

   if(num==0) return 0;
   
   if(num%10==digit) 
     return 1 + countAll(num/10,digit);
     
     return countAll(num/10,digit);     
  }
  
  //question 4
  int getMax(int num){
   if(num==0) return 0;

   if(num%10>=getMax(num/10))
     return num%10;
   return getMax(num/10);
  
  }
  
  //question 5 Helper function
  int findMinDigit(int num) { 
    if(num < 10) return num;
    
    return (num%10 < findMinDigit(num/10)) 
    ? num%10 : findMinDigit(num/10);
    //if true-> return num%10
    //else-> return findMinDigit(num/10)
  }
  
  
  //question 5 Helper function
  int removeMinDigit(int num, int minDigit) {
    int result=0;
    int place=1;
    int found=0;
    //found=0->false
    //!found=1->true

    while (num > 0) {
        if(num%10 == minDigit && !found) 
            found = 1; // Skip this digit once
        else 
        {
            result += (num%10) * place;
            place *=10;
        }
        num/=10;
    }
    return result;
  } 

  //question 5
  int sort(int num) {
    if(num==0) return 0;
   
    // Find the smallest digit in the number
    int minDigit = findMinDigit(num);

    // Remove the smallest digit from the number
    int remainingNum = removeMinDigit(num, minDigit);

    // Return the sorted number: smallest digit + recursively sorted rest of the number
    return minDigit + sort(remainingNum)*10;
  }

  //question 6 Helper function
  int countNumLength(int num){
  int count=0;
    while(num>0){
      count++;
      num/=10;
    }
    return count;
    //return the length of the number
  //12345 --> 54321
  //5*10^4 + 4*10^3 + 3*10^2 + 2*10^1 +1*10^0 -->54321
  //num%10*(10^count-1)
  }
  
  
  //question 6 Helper
  int make10InThePowerOfCount(int count){
    int inThePower=1;
    
    for(int i=1;i<count;i++)
      inThePower *=10;
      
    return inThePower;
  }
  
  
  //question 6
  int reverse(int num){
    if(num==0) return 0;
    
    int count=countNumLength(num);
    int place=make10InThePowerOfCount(count);
    
    return num%10*place + reverse(num/10);   
  }

  	
  //qeustion 7
  int merge(int num1,int num2){
    if(num1==0) return num2;
    if(num2==0) return num1;
    
    if(num1%10<num2%10)
      return num1%10 + merge(num1/10,num2)*10;
    	
    else num2%10 + merge(num1,num2/10)*10;			
  
  //num1=321
  //num2=654
  //if(1<4)=T --> 1+merge(32,654)*10
  //merge(32,654)*10=654320
  }
  
  
  //question 8
  void adjacentHanoi(int n,int one,int two,int three){
      
    if(n==1)
    {
      printf("move the ring from %d to %d\n",one,two);
      return;
    }
    else 
      {
        adjacentHanoi(n-1,one,two,three);
        
        printf("move the ring from %d to %d\n",one,two);
        
        adjacentHanoi(n-1,two,three,one);
      }

  }
  


  
  
  
  
  
