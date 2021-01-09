#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size() < 2) return vector<int>(1,-1); 
    
	vector<int> answer = arr;
    int min =   2147483647;
    auto itr =answer.begin();
    for(int i = 0 ; i < answer.size() ; i++){
        if(min > answer[i]) {min =answer[i]; itr = answer.begin() + i;}
    }
    answer.erase(itr);
    
    return answer;
}

vector<int> MinSolution(vector<int> arr){
	auto itr = min_element(arr.begin(), arr.end());
	// min_element �Լ��� �ּҰ��� iterator�� �����ϴ� �Լ��̴�!
	// *�� �Լ� �տ� �ٿ��ָ� �ּҿ� �ִ� ���� �ҷ��´�.
	// ���⼭ *�� ����ϰ�  find �Լ��� ����� ��� 
	// vector<int>::iterator itr = find (arr.begin(), arr.end(), min); 
	// �� ����ϸ� �ȴ�! 
	// �׸��� find �Լ����� arr.begin()�� �����ָ� int pos ���� �ȴ�. 
    arr.erase(itr);
    
    return arr.empty()? vector<int>(1,-1): arr;
    //arr �� ������� vector<int>(1,-1) ���� ���ο� ���͸� �������� �� �ִ�. 
} 
