#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

//pair�� ����Ѱͺ��� 70~90�� ���� ���� 
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<bool> check(N+1, 0);
    vector<float> fail(N+1, 0), failure(N+1, 0);
    int size = stages.size();
    
    for(int i = 0 ; i < stages.size() ; i++) fail[stages[i] - 1]++;
    
    for(int i = 0 ; i < N ; i++){
        if(i == 0){
            failure.insert(failure.begin() + i, fail[i] / size);
            continue;
        }
        else failure.insert(failure.begin() + i, fail[i] / (size - fail[i - 1]));
        size -= fail[i - 1];
    }
    double max = 0;
    int maxi = 0;
    for(int i = 0 ; i < N ; i++){
        for(int i = 0 ; i < N ; i++){
            if(max < failure[i] && !check[i]){ max = failure[i]; maxi = i; 
                                             }
        }
        
        if(max == 0){
            for(int j = 0 ; j < N ; j++){
                if(!check[j]) {answer.push_back(j+1); check[j] = 1;}
            }
            break;
        }
        answer.push_back(maxi+1);
        check[maxi] = 1;
        max = 0;
    }
    
    return answer;
}

//�ݴ�� ���´�! a ���� ���� ���� b���� a�� ���� ���´�.
bool compare (pair<double, int> &a, pair<double, int> &b){	//pair �� �ΰ� �̻��� �μ��� ���� ���� ������ �� �ִ�! 
	//������ �������� ���� ù��° ��ü�� �ι�° ��ü�� ���� ���ϱ� �����̴�. 
    if(a.first == b.first) return a.second < b.second; // ���� ������ ���� ���� ��ũ�� �ٲ��! (��������)
    // float ���� ������ ��쿡 �ε��� ���� ���ϰ� ���� ���� ũ�� �ٲ��ش�. (���������̾ ū���� ��!) 
    return a.first > b.first;
    // ���� ������ ���� ���� �� ũ�� �ٲ��ش�. (��������)
}

vector<int> OtherSolution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> count(N+1,0);
    vector<pair<double,int>> fail;
    //�ΰ� �̻��� �μ��� ����� ������ �ִ� ������ �迭�� ����! 
    double size = stages.size();
    
    for(int i = 0 ; i < size; i++) count[stages[i] - 1]++;
    
    for(int i = 0 ; i < N ; i++){
        if(size != 0)
            fail.push_back(make_pair(count[i]/ size, i+1));
        else fail.push_back(make_pair(0, i+1));
        size -= count[i];
    }
    
    sort(fail.begin(), fail.end(), compare);
    
    for(auto it = fail.begin() ; it != fail.end() ; it++){
        answer.push_back(it->second);
        //iterator �� ������ �����̱� ������ it->second �� �������ش�.
		//compare �Լ��� ���� ���� ������ �������� �� �迭�� �����ִ� ��ü�� �����ϴ� ���̱� ������ a.first �� ������ش�. 
    }
    
    return answer;
}
