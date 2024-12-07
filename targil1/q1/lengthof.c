
  //give the length of num
  int lengthOf(int num){
    int count=0;
    while(num!=0){
      num/=10;
      count++; 
    }
    return count;  
  }
