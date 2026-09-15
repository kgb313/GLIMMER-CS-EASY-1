#include <stdio.h>
int main() {
    int i=0,sum=0;;
    while(i++<10){
        sum+=i;
    }
    printf("%d\n",sum);
    getchar(); // Wait for user input before closing the console window
    return 0;
}