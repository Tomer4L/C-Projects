#include <stdio.h>
  void func2(int a,int b){
    int c;
    c=a+b;
    printf("%d",c);   
  }
  
  
    void func1(int x,int y){
    func2(x+1,y-1);
  }
  
  
  int main(){
    
    func1(268,6247);
    
    return 0;
  }
  
  

  
  

