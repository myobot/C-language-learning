#include <time.h>   
#include <stdio.h> 
#include <windows.h>  
int main() {  
     time_t first, second;  
     first=time(NULL);  
     Sleep(2000);  
     second=time(NULL);  
     printf("The difference is: %d seconds",(int)difftime(second,first));  
     return 0;   
}   