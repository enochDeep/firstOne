#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* s) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int len = strlen(s), chStart;
    char* answer = (char*)malloc(len);
    strcpy(answer, s);
    
    printf("%d", len);
    for(int i = 0 ; i < len ; i++){
        if(answer[i] == ' ') {chStart = 0; continue;}
        if( chStart % 2 == 0) answer[i] = toupper(s[i]); 
        else answer[i] = tolower(s[i]);
        chStart++;
    }
            
    return answer;
}
