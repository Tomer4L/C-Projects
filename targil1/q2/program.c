#include <stdio.h>
#include "headers.h"

  int main(){  
    char ch;
    int totalChars=0;
    int totalWords=0;
    int totalLines=0;
    int totalLetters=0;
    int totalDigits=0;
    int totalWhitespaces=0;
    
    int inWord=0;
    
    printf("Enter until Ctrl+D\n");
        
    while((ch=getchar())!=EOF){
      totalChars++;
    
      if(checkIfChar(ch)) totalLetters++;
   
      if(checkIfNumber(ch)) totalDigits++;
       
      if(checkIfwhitespace(ch))
      {      
        totalWhitespaces++;      
        if(ch=='\n') totalLines++;           
        inWord=0;
      }
      
      else if(inWord==0){
        totalWords++;
        inWord=1;
      }        
    }
    printf("Total characters: %d\n",totalChars);
    printf("Total words: %d\n",totalWords);
    printf("Total lines: %d\n",totalLines);
    printf("Total letters: %d\n",totalLetters);
    printf("Total digits: %d\n",totalDigits);
    printf("Total whitespaces: %d\n",totalWhitespaces);   
    
    
    return 0;
  }
  
  
  //check if c is char
  int checkIfChar(char c){    
    return ((c>=65 && c<=90)||(c>=97 && c<=122));      
  }
  
  
  //check if c is whitespace: enter/space/tab
  int checkIfwhitespace(char c){
    return(c==' ' || c=='\t' || c=='\n'); 
  
  }
  
  
  //check if c is a Number
  int checkIfNumber(char c){
    return(c>='0' && c<='9');
  }

  
  
  
  
  
  
  
  
  
  
  
  
