#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int solution(string s) {
    int answer = 0, count = 0;
    vector <int> array;
    
    for(int i = 1 ; i < s.size(); i++){
        string tmp = "";
        int n;
        if(isdigit(s[i-1])){
            if(i > 1 && isdigit(s[i-2])) n = (s[i-2] - '0') * 10 + s[i-1] - '0';
            else n = s[i-1] - '0';
        }
        
        if(s[i] == 'S'){ 
            array.push_back(n); 
            count++;}
        else if(s[i] == 'D'){ 
            array.push_back(pow(n,2));
            count++;}
        else if(s[i] == 'T'){ 
            array.push_back(pow(n, 3)); 
            count++;}
        else if(s[i] == '*'){
            if(i == 2) array[count - 1] += array[count - 1];
            else{
                array[count - 1] += array[count - 1];
                array[count - 2] += array[count - 2];
            }
        }
        else if(s[i] == '#'){
            array[count - 1] *= -1;
        }
    }
    
    for(int i = 0 ; i < count ; i++){
        answer += array[i];
    }
    return answer;
}

//��Ʈ�� ��Ʈ������ ���ڿ� ��Ʈ���ϱ� ���� 
// �̰��� ����ؼ� ���ڿ��� ��Ʈ���� �� �ִ�. 
void Practice(void) { 
 	int num;
 	char ch;
	stringstream stream1;

	string string1 = "25abss 55 asdbsd";	  
	stream1.str(string1);

	//��Ʈ�� ��Ʈ������ �ϸ� int ������ �ϸ� 2�ڸ��� 3�ڸ���, �� ���־�� ���´�.
	stream1 >> num;
	cout << "num: " << num << endl;  // displays numbers, one per line
	
	//���ڿ��� get �ϸ� 1���� ���ڿ����� ���´�.  
	ch = stream1.get();
	cout << "char : " << ch << endl;
	ch = stream1.get();
	cout << "char : " << ch << endl;
	ch = stream1.get();
	cout << "char : " << ch << endl;
	ch = stream1.get();
	cout << "char : " << ch << endl;
	ch = stream1.get();
	cout << "char : " << ch << endl;
	ch = stream1.get();
	cout << "char : " << ch << endl;
	ch = stream1.get();
	cout << "char : " << ch << endl;
	
	//unget �� �ϸ� get �ϱ� �������� ���ư���. 
	stream1.unget();
	stream1.unget(); 
	stream1 >> num;
	cout << "num: " << num << endl;

} 
