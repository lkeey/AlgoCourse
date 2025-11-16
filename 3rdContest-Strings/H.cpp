#include <iostream>
#include <vector>
#include <string> 
#include <sstream>
#include <numeric> 

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    size_t start = 0, end;
    while ((end = s.find(delimiter, start)) != string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(s.substr(start)); // last token
    return tokens;
}

int getDec(char s) {
    int n = 0;
    if (s == 'I') {
        n = 1;
    } else if (s == 'V') {
        n = 5;
    } else if (s == 'X') {
        n = 10;
    } else if (s == 'L') {
        n = 50;
    } else if (s == 'C') {
        n = 100;
    } else if (s == 'D') {
        n = 500;
    } else if (s == 'M') {
        n = 1000;
    }

    return n;
}

int num(string s) {
    int result = 0;

    for (int i=0; i<s.length(); i++) {
        int cur = getDec(s[i]);

        if (i + 1 < s.size() && cur < getDec(s[i + 1]))
            result -= cur;
        else
            result += cur;
    }

    return result;
}

string toRoman(int num) {
    pair<int, string> roman[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"}, {1, "I"}
    };

    string res;
    for (int i = 0; i < 13; i++) {
        int val = roman[i].first;
        string sym = roman[i].second;
        while (num >= val) {
            res += sym;
            num -= val;
    }
}
    return res;
}

int main() {

    string s;
    int n1, n2;
    
    cin >> s;

    vector<string> parts = split(s, '/');

    n1 = num(parts[0]);
    n2 = num(parts[1]);

    int whole = n1 / n2;
    int rem = n1 % n2;

    if (rem == 0) {
        cout << toRoman(whole); 
    } else {
        int g = gcd(rem, n2);
        rem /= g;
        n2 /= g;

        if (whole > 0)
            cout << toRoman(whole) << " ";

        cout << toRoman(rem) << "/" << toRoman(n2);
    }

    return 0;
}
