#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
	// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
	int* answer = (int*)malloc(numbers_len * sizeof(int));
	int compare, sum, tmp, isOut = 0, min = 100, minpos;
	int resultIn = 0;

	for (int i = 0; i < numbers_len; i++) {
		for (int j = i + 1; j < numbers_len; j++) {
			if (numbers[i] > numbers[j]) {
				tmp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = tmp;
			}

		}
	}

	for (int i = 0; i < numbers_len; i++) {
		compare = numbers[i];
		for (int j = i + 1; j < numbers_len; j++) {
			sum = numbers[j] + compare;
			for (int k = 0; k <= resultIn; k++) {
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

	return answer;
}