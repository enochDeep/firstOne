#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
bool solution(const char* s) {
    char* brString = (char *)malloc(strlen(s));
    *brString= 0;
    int insult = 0, len = strlen(s);
    
    for(int i = 0 ; i < len ; i++)
    {
        if(s[i] == '(') brString[insult++] = '(';
        else if(s[i] == ')'){
            if(insult < 1)  return false;
            else insult--;
        }
    }
    
    if(insult){
        return false;
    }
    
    return true;
}
