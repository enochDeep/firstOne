#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* number, int k) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int len = strlen(number), input;
    char* answer = (char*)malloc(len -k + 1);
    int maxi = -1;
    char max = 0;
    //printf("%d", max);
    for(int j = 0 ; j < len - k ; j++){
        //printf("%d ---\n", j+1);
        max = 0; 
        for(int i = maxi + 1; i <= k + j; i++){
            //printf("i : %d\n", i);
            if(max < number[i]){
                max = number[i];
                maxi = i;
            }
        }
        answer[j] = max;
        //printf("answer[%d] : %c, all : %d, max : %c, maxi : %d\n", j, answer[j], all, max, maxi);   
    }
    answer[len - k ] = '\0';
    
    return answer;
}
