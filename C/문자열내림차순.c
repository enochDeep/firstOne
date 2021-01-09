#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* s) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���
    int len = strlen(s);
    char* answer = (char*)malloc(len);
    strcpy(answer, s);
    char tmp;
    
    for(int i = 0 ; i < len ; i++){
        for(int j = i+1 ; j < len ; j++){
            if(answer[i] < answer[j]){
                tmp = answer[i];
                answer[i] = answer[j];
                answer[j] = tmp;
            }
        }
    }

    return answer;
}
