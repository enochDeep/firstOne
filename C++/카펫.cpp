#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int all = brown + yellow, i;
    
    for(i = 1 ; true ; i++){
        if(!(yellow % i) && (i +2) * (yellow / i + 2) == all)   break;
    }
    
    // �� ������ answer.push_back() �̷��� ������ �ϴ� ���� �ƴ϶� �ٸ� ������ �ٲ��� �� �ִ�. 
    return vector<int>{yellow / i + 2, i+2};
}
