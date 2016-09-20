#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n, k;
    scanf("%d",&n);
    char string[n+1];
    scanf("%s",string);    
    scanf("%d",&k);
   k = k%26;
    int count = 0;           
    while( count <= n ){
                                       
            if( 65 <= string[count] &&  string[count] <= 90  ){
                if( string[count]  == 90 ){                                        
                    string[count] = 65 + k - 1;                   
                    //printf("1==>%c \n",string[count]);
                } else               
               if( ( string[count] + k ) > 90){                    
                    int temp = ( string[count] + k) - 90;
                    temp = 65 + temp - 1;                 
                    string[count] = temp;              
                    //printf("2==>%c \n",string[count]);
               }else{                                 
                   string[count] = string[count] + k; 
                    //printf("3==>%c \n",string[count]);
               }
            }
         if( 97 <= string[count] &&  string[count] <= 122  ){
               if( string[count]  == 122 ){                                                            
                    string[count] = 97 +k -1;         
                    //printf("4==>%c \n",string[count]);
                } else                
                if( ( string[count] + k ) > 122){                                                                     
                    int temp = ( string[count] + k) - 122;
                    temp = 97 + temp - 1;                      
                    //printf("5==>%d \n",temp);
                    string[count] = temp;    
                   //printf("5==>%d \n",temp);
                }else{                    
                    string[count] = string[count] + k;
                    //printf("6==>%c \n",string[count]);
                }
         }
                                  
        count++;        
    }    
   printf("%s\n",string);
    return 0;
}

