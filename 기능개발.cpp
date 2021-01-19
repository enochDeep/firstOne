#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

//queue �� ������� �ʰ� Ǭ ��! 
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int tmp, max = 101, count = 0;
    vector<int> answer;
    
    for(int i = 0 ; i < progresses.size() ; i++){
        tmp = 100 - progresses[i];
        tmp = ceil((double)tmp / speeds[i]);
        if(i == 0){max = tmp;}
        if(max >= tmp) count++;
        else{
            max = tmp;
            answer.push_back(count);
            count = 1;
        }
        if(i == progresses.size() - 1){answer.push_back(count);}
    }
    return answer;
}

// 7 4 2 9 -> 3 1
//���������� ����� ���踦 ��Ÿ���� ���� ���� ������ �� �ڱ��� ���� 
//vector �� push ���ְ� answer.back()�� �ڽ��� ���������ϱ� ������ ++�� ����ؼ�
//�����ش�! 
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int tmp, max = 101, count = 0;
    vector<int> answer;
    
    for(int i = 0 ; i < progresses.size() ; i++){
        tmp = 100 - progresses[i];
        tmp = ceil((double)tmp / speeds[i]);
        if(answer.empty() || max < tmp) answer.push_back(1);
        else answer.back()++;
        
        if(max < tmp) max = tmp;
    }
    return answer;
}

//queue �� ����ϰ� Ǭ �� 
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int tmp, max = 101, count = 0;
    vector<int> answer;
    deque<int> q;
    
    for(int i = 0 ; i < progresses.size() ; i++){
        tmp = 100 - progresses[i];
        tmp = ceil((double)tmp / speeds[i]);
        q.push_back(tmp);
        if(i == 0) continue;
        if(q.front() >= tmp){
            q.pop_back();
            count++;
        }
        else{
            q.pop_front();
            count++;
            answer.push_back(count);
            count = 0;
        }
        if(i == progresses.size() - 1 && !q.empty()){
            count++;
            answer.push_back(count);
        }
    }
    return answer;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int tmp;
    vector<int> answer;
    deque<int> q;
    
    for(int i = 0 ; i < progresses.size() ; i++){
        tmp = 100 - progresses[i];
        tmp = ceil((double)tmp / speeds[i]);
		if(answer.empty() || q.front() < tmp){
			q.push_back(tmp);
            answer.push_back(1);
        }
        else answer.back()++;
        //���� �������� �����ϱ� ������ ���� ����Ǵ� ���̴�! 
        
        if(q.front() < tmp){
        	q.pop_front();
		}
    }
    return answer;
}
