#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
// skill_trees_len�� �迭 skill_trees�� �����Դϴ�.
int solution(const char* skill, const char* skill_trees[], size_t skill_trees_len) {
    int answer = 0, before = 0, j, len = strlen(skill);
    bool out = false;
    bool* exist =(bool *)malloc(sizeof(bool) * len);
    memset( exist, 0, len*sizeof(bool));

    for(int i = 0; i < skill_trees_len; i++){
        before = 0, out = 0;
        memset( exist, 0, len*sizeof(bool));
        for(int k = 0 ; k < len ; k++){
            for(j = 0; j < strlen(skill_trees[i]) ; j++)
            {
                if(skill[k] == skill_trees[i][j]){
                    if(before > j) { out = 1; break;}
                    if(k != 0 && exist[k - 1] == false){out = 1; break; }
                    exist[k] = 1;
                    before = j;
                }
            }
            if(out) break;
            if(k == len - 1 && j == strlen(skill_trees[i])) answer++;
        }
    }
    
        
    return answer;
    
}
