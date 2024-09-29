#include <stdio.h>
#include <stdbool.h>

bool checkValid(char *s){
    char stack[100];
    int count = 0;
    
    for(int i = 0; s[i] != '\0'; ++i){
        char curr = s[i];
        
        if(curr == '(' || curr == '{' || curr == '['){
            stack[count++] = curr;
        } else if(curr == ')' || curr == '}' || curr == ']'){
            if(count == 0){
                return false;
            }
            char topChar = stack[--count];
            
            if((curr == ')' && topChar != '(') || 
               (curr == ']' && topChar != '[') || 
               (curr == '}' && topChar != '{')) {
                return false;
            } 
        }
    }
    return count == 0;
}

void main(){
    char testCases[][10] = {
        "()",
        "(]",
        "()[]{}",
        "([]",
        "([)]"
    };

    for (int i = 0; i < 5; i++) {
        printf("Test case %d: %s => %s\n", i + 1, testCases[i], checkValid(testCases[i]) ? "true" : "false");
    }
}