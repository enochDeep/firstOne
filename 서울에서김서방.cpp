#include <string>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int i;
    
    for(i = 0 ; i < seoul.size(); i++) if(seoul[i] == "Kim") break;
    
    string answer = "�輭���� " + to_string(i) + "�� �ִ�";
    
    return answer;
}
