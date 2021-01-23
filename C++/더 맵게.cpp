#include <string>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int i;
    
    //priority_queue<int, vector<int>, greater<int> > a(scoville.begin(), scoville.end());
    //���� ���� push for ���� ������ �� �ִ�! 
    priority_queue<int, vector<int>, greater<int> > a;
    
    for(int i = 0 ; i < scoville.size() ; i++){
        a.push(scoville[i]);
    }
    
    //��� �����ؾ��ϱ� ������ �̰� �ְ��� �˰����̴�! 
    for(i = 0 ; a.top() < K; i++){
        if(a.size() > 1){
        int tmp = a.top();
        a.pop();
        a.push(tmp + a.top() * 2);
        a.pop();
        }
        else    return -1;
    }
    
    return i;
}
