#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ��� ����� ���� ��Ʈ �����ڸ� ����ؼ� ����� ��...! 
int solution(vector<int> numbers, int target) {
    int answer = 0, all = 0, before = 0;
    int size = 1 << numbers.size();
    
    for(int i = 0 ; i < numbers.size() ; i++){
        before += numbers[i];
    }
    
    for(int i = 0 ; i < size ; i++){
        all = before;
        for(int j = 0 ; j < numbers.size(); j++){
            if(i & (1 << j)){
                all -= numbers[j] * 2;
            }
        }
        if(all == target) answer++;
    }
    
    return answer;
}

// ����� �ڵ� DFS �� ����ؼ� ���� ������  �� 
void dfs(vector<int>& numbers, int target, int& answer, int count, int all){
    if(count == numbers.size() - 1){
        if(all + numbers[count] == target) answer++;
        if(all - numbers[count] == target) answer++;
        
        return;
    }
    
    dfs(numbers, target, answer, count + 1, all + numbers[count]);
    dfs(numbers, target, answer, count + 1, all - numbers[count]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, answer, 0, 0);
    return answer;
}

// ��Ʈ ������ �� ��! 
int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = 1 << numbers.size();

    for(int i = 1 ; i < size ; i++){
        int temp = 0;
        for(int j = 0 ; j < numbers.size() ; j++)
        {  
            if(i &(1 << j)){
                temp -= numbers[j];
            }
            else temp += numbers[j];
        }
        if(temp == target) answer++;
    }
    return answer;
}



