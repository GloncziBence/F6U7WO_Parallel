#include <stdio.h>
#include <string.h>

int main() {
   char str[8];
   char str2[8] = {[0 ... 7] = '0'};
   int i;
   int stringLength = 0;

   printf("Enter a string: ");
   scanf("%s", str);
   stringLength = strlen(str);

   if(stringLength<8){
    printf("Individual characters: ");
        for(i = 0; i < stringLength; i++){
                str2[7-i]=str[(stringLength-1)-i];
        }

        for(i = 0; i < 8; i++){
            printf("%c ", str2[i]);
        }

    }else{
    printf("The string is too long");
    }

   return 0;
}
