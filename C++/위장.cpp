#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    
    for(int i = 0 ; i < clothes.size() ; i++){
        //m �� �ش� �ε����� �ִ� ���� �ʱ�ȭ �Ǿ��ִ�?
		// �׷��� += ���� �� �Է��� �����ϴ�. 
		m[clothes[i][1]] += 1;
    }
    
    //face 2�� head 2�� �ϰ�� face 2 + �ƹ��͵� �Ⱦ��� ����� ��(1) = 3
	//head ���� 2 + �ƹ��͵� �Ⱦ��� ����� ��(1) = 3
	//�� ����� ���� face(3) * head(3) = 9 ���̴�. ���⼭ ����ó���� ���δ� ������ �������� ��������
	//-1 �� ���ش�. 
    for(auto it = m.begin() ; it != m.end() ; it++){
        answer *= it->second + 1;
    }
    
    return answer - 1;
}
