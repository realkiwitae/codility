#include <string>

using namespace std;

int solution(string &S) {
    int count = 0;

    for(char c : S){
        if(c == '(')count++;
        else{
            if(--count<0)return 0;
        }
    }
    return count == 0;
}