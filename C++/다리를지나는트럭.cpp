#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1; // 1�ʺ��� ���� ���� ������ ������ �����ذ�. 
	int all = 0, tmp;
    vector<int> count;
    stack <int> s, pass;
    queue <int> q;
    
    for(int i = 0 ; i < truck_weights.size(); i++){
        s.push(truck_weights[i]);
    }
    
    while(pass.size() != truck_weights.size()){
        if(!s.empty() && all + s.top() <= weight){
            tmp = s.top();
            s.pop();
            q.push(tmp);
            all += tmp;
            count.push_back(0);
        }
        for(int j = 0 ; j < count.size() ; j++){
            count[j]++;
            if(count[j] == bridge_length){
                tmp = q.front();
                q.pop();
                pass.push(tmp);
                all -= tmp;
            }
        }
        answer++;
    }
        
    
    return answer;
}

int otherSolution (int bridge_length, int weight, vector<int> truck_weights) {
	//length ��ŭ �����ְ� ���� �ð��� ������ ���� pair�� �־��ָ� ������ �ð��� ������ �ȴ�.
	//�׷��� ���� �ð��� ���������ָ鼭 front().second �� ���� ���غ��� �װ��� �ٸ��� ��������
	//�� �� �ִ�!
	int answer = 0, i = 0, on = 0, time = 1;
	queue <pair<int, int>> q;
	
	while(1){
		//�̹� �ٸ��� �ö� �ִ� �Ͱ� ���� ���� ������ ���� �ٸ��� �ߵ� �� �ִ� �ͺ��� �۰ų� ������,
		//push ���ش�.
		if(weight >= truck_weights[i] + on){
			q.push(make_pair(truck_weights[i], time + bridge_length));
			on += truck_weights[i];
			i++; 
		}
		
		//������ Ʈ���� push ���� ���� ���� ���� �ð��� q�� �ι�° �μ��� �����ֱ� ������ answer ��
		//�־��ְ� break ��Ų��. 
		if(i >= truck_weights.size()){
			answer = q.back().second;
			break;
		}
		//�ð��� 1�ʾ� ���������ְ� ���������� ���� ť�� ���� �տ� �ִ� ���� �ι�° ���� �� �ٸ��� ��
		//�ǳ� �ð��� �Ǹ� �ٸ����� �ö��ִ� ���Կ��� ���ְ� pop ���ش�. 
		else {
			time++;
			if(time == q.front().second){
				on -= q.front().first;
				q.pop();
			}
		}
		
	}
	
	return answer;
}
