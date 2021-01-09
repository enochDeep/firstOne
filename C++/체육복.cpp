#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int len = lost.size(), reLen = reserve.size();
    set<int> all;
    vector<bool>count(30,0);
    
    for(int i = 0 ; i < len ; i++){
        all.insert(lost[i]);
    }
    
    for(int i = 0 ; i < reLen ; i++){
        if(all.end() != all.find(reserve[i])){
            auto itr = all.find(reserve[i]);
            all.erase(itr);
            count[i] = true;
        }
    }
    
    for(int i = 0 ; i < reLen ; i++){
        //�ڱ� ������ ��ȣ������� ü������ ������
        if(count[i]) continue;
        if(all.end() != all.find(reserve[i] - 1)){
            auto itr = all.find(reserve[i] - 1);
            all.erase(itr);
            printf("2��°\n");
        }
        //�ڱ� ������ ������� ü������ ������
        else if(all.end() != all.find(reserve[i] + 1)){
            auto itr = all.find(reserve[i] + 1);
            all.erase(itr);
            printf("3��°\n");
        }
    }
    n = n - all.size();
    
    return n;
}
