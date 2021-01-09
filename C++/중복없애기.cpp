#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
	//����ũ �Լ��� ���۰� ������ �ߺ����� �����ϰ� �����Ⱚ�� ù�ּҸ� ��ȯ�Ѵ�.
	//algorithm ������Ͽ� ���ԵǾ� �ִ� �Լ��̴�.

    return arr;
}

vector<int> mySolution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    //int len = arr.size(); �̷��� ���ְ� for ���� len �� �־��ִ°� �� �����ɸ���. 
    
    for(int i = 0 ; i < arr.size()-1 ; i++)
        if(arr[i] != arr[i+1]) answer.push_back(arr[i+1]);

    return answer;
}
