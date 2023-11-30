#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

int solution(string &S){
    stack<char> stack;
    unordered_map<char,char> book{{'{','}'},{'[',']'},{'(',')'}};

    for(char c : S){

        if(book.find(c) == book.end()){
            // closing brackets
            if(stack.empty())return 0;
            if(stack.top() != c) return 0;
            stack.pop();
            continue;
        }
        stack.push(book[c]);
    }
    return stack.empty();

}