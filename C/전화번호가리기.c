#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* phone_number) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int len = strlen(phone_number);
    char* answer = (char*)malloc(len);
    strcpy(answer, phone_number);
    
    for(int i = 0 ; i < len ; i++){
        if(i < 4) continue;
        else answer[len -1 - i] = '*';
    }
    return answer;
}
