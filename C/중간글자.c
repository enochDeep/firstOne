#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* s) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int len = strlen(s);
    char* answer;
    if((len % 2) == 0){
        int center = len / 2;
        answer = (char*)malloc(3);
        answer[0] = s[center - 1];
        answer[1] = s[center];
        answer[2] = '\0';
    }
    else{
        double centerD = (double) len / 2.0;
        int center = floor(centerD);
        answer = (char*)malloc(2);
        answer[0] = s[center];
        answer[1] = '\0';
    }
    
    return answer;
}
