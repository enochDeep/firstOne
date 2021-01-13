#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> binary(vector<int> decimal, vector<int> comp, int n){
    vector<int> ans;
    vector<string> toString;
    string tmp;
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            if(decimal[i] % 2 == 1) ans.push_back(1);
            else ans.push_back(0);
            decimal[i] /= 2;
        }
        
        for(int j = 0 ; j < n ; j++){
            if(comp[i] % 2 == 1) ans[j] |= 1;
            comp[i] /= 2;
        }
        
        for(int j = 0 ; j < n ; j++){
            if(ans[n - j - 1]) tmp += '#';
            else tmp += ' ';
        }
        toString.push_back(tmp);
        ans.clear();
        tmp.clear();
    }
    
    return toString;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    answer = binary(arr1, arr2, n);
    return answer;
}

vector<string> OtherSoulution(int n, vector<int> arr1, vector<int> arr2){
	vector<string> answer;
	
	for(int i = 0 ; i < n ; i++){
		arr1[i] = arr1[i]|arr2[i];
		string tmp = "";
		for(int j = 0 ; j < n ; j++){
			if(arr1[i] % 2 == 0) tmp = ' ' + tmp;
			// �̷��� �ϸ� ���ڿ��� �տ� ���� �Է��� �� �ִ�! 
			else tmp = '#' + tmp;
			arr1[i] /= 2;
		}
		answer.push_back(tmp);
	}
    return answer;
}

int main (void){
	int a = 3, b =5;
	a = a | b;
	
	//�̿� ���� ��Ʈ�� OR ��Ʈ ������ �ϸ�, �ڵ����� �����Ϸ��� 011, 101 �� �ٲ㼭 or �� ���ְ�
	//111�� ��ȯ�Ѵ����� 7�� ���� ����. 
	
	cout << a << endl;
	
	a = 3;
	b = 5;
	a = a& b;
	cout << a << endl;
	
	//�̿� ���� ��Ʈ�� AND �����ص� ������ �������� ���ϰ� ����ȴ�. 
	return 0;
} 
