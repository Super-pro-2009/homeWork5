#include <stdio.h>
#include <string.h>

int isLetter(char c){
    return (c>='A' && c<='Z') || (c>='a' && c<='z');
}

int main(int argc, char** argv)
{
    char str[] = "This is mississ Murple, she is busy.";
    char sub[] = "is";
    int sub_counter = 0;

    for(int i = 0; i < strlen(str); i++) {
        int found = 1;
        
        if(i>0 && isLetter(str[i-1])){
            found=0;
        }
        
        if(found){
            for(int x = 0; x < strlen(sub); x++) {            
                if(str[i+x] != sub[x]){
                    found = 0;
                    break;
                }    
            }
        }
        
        int afterIdx = i+strlen(sub);
        if(( afterIdx < strlen(str)) && isLetter(str[afterIdx])){
            found = 0;
        }
        
        if(found){
            sub_counter++;
        }
    }

    printf("Word '%s' is present %d times\n", sub, sub_counter);
    return 0;
}
