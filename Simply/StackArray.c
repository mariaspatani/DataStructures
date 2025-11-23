//check palindrome or not
#include <stdio.h>
#include <string.h>

int main() {
    char str[50], stack[50];
    int top = -1;

    printf("Enter string: ");
    scanf("%s", str);

    for(int i=0; str[i]!='\0'; i++)
        stack[++top] = str[i];

    int flag = 1;
    for(int i=0; str[i]!='\0'; i++)
        if(str[i] != stack[top--])
            flag = 0;

    if(flag) printf("Palindrome");
    else printf("Not Palindrome");

    return 0;
}
