#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int quadTree(int **arr, size_t rowsStart, size_t colsStart, size_t arr_rows, size_t arr_cols, int * answer){
    int all = 0;
    int i , j; 
    for(i = rowsStart ; i < arr_rows; i++){
        for( j = colsStart; j < arr_cols; j++){
            all += arr[i][j];
        }
    }
    printf("%d %d", i, j);
    
    if(all == (arr_rows * arr_cols)){
        all = 0 ;
        answer[1] += 1;
        //printf("up, answer[0] : %d, answer[1] : %d\n", answer[0], answer[1]);
    }
    else if(all == 0){
        answer[0] += 1;
        //printf("down, answer[0] : %d, answer[1] : %d\n", answer[0], answer[1]);
    }
    else {all = 0; 
        //printf("else\n");
		quadTree(arr, 0, 0, arr_rows/ 2, arr_cols / 2,answer);
		quadTree(arr, 0, arr_cols /2, arr_rows/ 2, arr_cols, answer);
		quadTree(arr, arr_rows/ 2, 0, arr_rows, arr_cols / 2, answer);
		quadTree(arr, arr_rows/ 2, arr_cols/ 2, arr_rows, arr_cols, answer);
	}
    
    return 0;
}

// arr_rows�� 2���� �迭 arr�� �� ����, arr_cols�� 2���� �迭 arr�� �� �����Դϴ�.
int* solution(int** arr, size_t arr_rows, size_t arr_cols) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0; answer[1] = 0;
    quadTree(arr, 0, 0, arr_rows, arr_cols, answer);
    
    return answer;
}

int main (void){
	int arra[4][4] = {{1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 1, 1, 1}};
	int* answer;
	
	answer = solution(arra, 4,4);
	
	return 0;
}
