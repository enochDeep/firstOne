#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    int tmp;
    
    while(n != 0){
        n--;
        tmp = n % 3;
        
		answer = "124"[tmp] + answer;
        /*	�� �� ������ ���� �ѹ������� ��ü�ȴ�. 
        switch(tmp){
        	case 0 :
        		answer = "1" + answer;
        		break;
        	case 1 :
        		answer = "2" + answer;
        		break;
        	case 2 :
        		answer = "4" + answer;
        		break;
        	
		}
		*/
        n /= 3;
    }
    return answer;
}
