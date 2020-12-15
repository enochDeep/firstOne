#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len�� �迭 numbers�� �����Դϴ�.
int* solution(int numbers[], size_t numbers_len) {
	// return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
	int* answer = (int*)malloc(numbers_len * numbers_len * sizeof(int));
	int compare, sum, tmp, isOut = 0;
	int resultIn = 0;

	for (int i = 0; i < numbers_len; i++) {
		compare = numbers[i];
		for (int j = i + 1; j < numbers_len; j++) {
			sum = numbers[j] + compare;
			for (int k = 0; k < resultIn; k++) {
				if (answer[k] == sum) {
					isOut = 1;
					break;
				}
			}

			if (isOut == 0) {
				answer[resultIn] = sum;
				resultIn++;
			}
			isOut = 0;

		}

	}

	for (int i = 0; i < resultIn; i++) {
		for (int j = i + 1; j < resultIn; j++) {
			if (answer[i] > answer[j]) {
				tmp = answer[i];
				answer[i] = answer[j];
				answer[j] = tmp;
			}

		}
	}

	return answer;
}