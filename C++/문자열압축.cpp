#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(string s) {
    int answer = s.length(), length = 1, count = 0, before = 1001;
    
    if(s.length() == 1) return 1;
    
    while(length != s.length()){
        string com = "";
        string zip = "";
        for(int i = 0 ; i < s.length() ; i += length){
            string all = s.substr(i, s.length());
            if(i+length >= s.length()){
                if(length == s.length() - i && !com.compare(s.substr(i, length))){
                    zip += to_string(count + 2) + com;
                }
                else if(count > 0){
                    zip += to_string(count + 1) + com + s.substr(i, s.length());}
                else zip += com + s.substr(i, s.length());
                break;
            }
            if(!com.compare(s.substr(i, length))){count++;}
            else if(count > 0){
                zip += to_string(count + 1) + com;
                count = 0;
            }
            else if(i != 0 && count == 0){zip += com;}
            com = s.substr(i, length);
        }
        if(before > zip.length()) before = zip.length();
        count = 0;
        length++;
    }
    
    return before;
}


int solution(string s) {
    int answer = s.length(), length = 1, count = 0, before = 1001;
    
    if(s.length() == 1) return 1;
    
    while(length != s.length()){
        string com = "";
        string zip = "";
        for(int i = 0 ; i < s.length() ; i += length){
            string all = s.substr(i, s.length());
            //ã�����ϴ� ������ ���̰� �� ���ڿ��� ���̸� �Ѿ�ų� ���� ���
            if(i+length >= s.length()){
                //length�� ������ ã�� ���� ���ڿ��� ���̿� ���ٸ� ���ڿ��� ������ ���Ѵ�.
                if(length == s.length() - i && !com.compare(s.substr(i, length))){
                    //���⼭ +2 �� �̹� �־��� count ���� �ѹ��� compare �ؼ� ������ �߰��ؼ� ������ +1���� �ѹ��� �߰��ߴ�.
                    zip += to_string(count + 2) + com;
                }
                //���� ã�� ����ä ������ ������ �ݺ��Ǿ��� ���� ������ �ݺ��� ������ Ƚ���� ���ڸ� �־��ְ�, ������ ���ڸ� �־��ش�.
                else if(count > 0){
                    zip += to_string(count + 1) + com + s.substr(i, s.length());}
                //�ƿ� ������ ������ �ݺ��� �ȵǰ� �������� �ݺ����� �ʾҴٸ� ������ ���ϰ� ������ ���ڿ��� �־��ش�.
                else zip += com + s.substr(i, s.length());
                //�������̾ break �Ѵ�.
                break;
            }
                //ã���� �ϴ� ���ڿ��� ������ ���ϰ� ��ġ�Ѵٸ� �ߺ� Ƚ���� ���������ش�.
            if(!com.compare(s.substr(i, length))){count++;}
            //�ƴ϶�� ������ ��ȭ�� ���̴�. ���⼭ ������ ������ �ݺ��Ǿ��ٸ� �ݺ��Ǿ��� ���ڿ� ���ڿ��� �־��ش�.
            else if(count > 0){
                zip += to_string(count + 1) + com;
                count = 0;
            }
            //���ڿ��� ã���� �ϴ� ���ϰ� ���� �ʰ� count �� ���� ��쿡 ������ ���ڸ� zip�� �־��ش�.
            else if(i != 0 && count == 0){zip += com;}
            com = s.substr(i, length);
        }
        if(before > zip.length()) before = zip.length();
        count = 0;
        length++;
    }
    
    return before;
}

//substr �Լ��� i ���� length �ε��� ������ ���ڿ��� �����Ѵ�.

