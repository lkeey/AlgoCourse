#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generate(string s, vector<char> &stack, int openRound, int openSquare, int N) {
    if ((int)s.size() == N) {
        if (stack.empty()) cout << s << "\n";
        return;
    }
    if (openRound < N / 2) {
        stack.push_back('(');
        generate(s + "(", stack, openRound + 1, openSquare, N);
        stack.pop_back();
    }
    if (openSquare < N / 2) {
        stack.push_back('[');
        generate(s + "[", stack, openRound, openSquare + 1, N);
        stack.pop_back();
    }
    if (!stack.empty()) {
        char last = stack.back();
        stack.pop_back();
        generate(s + (last == '(' ? ")" : "]"), stack, openRound, openSquare, N);
        stack.push_back(last);
    }
}

int main() {
    int N;
    cin >> N;
    vector<char> stack;
    generate("", stack, 0, 0, N);
    return 0;
}
