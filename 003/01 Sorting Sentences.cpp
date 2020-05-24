// PROBLEM: https://www.hackerearth.com/challenges/college/codetracks-3/algorithm/c1ed7d99348d4137be0e843ea8866dc3/
// SOLUTION: Sagar

#include <bits/stdc++.h>
using namespace std;

string sortWords(string text) {
    text[0] = tolower(text[0]);
    text.pop_back();

    stringstream ss(text), rs;
    string word;
    map<int, string> m;
    while (ss >> word) 
        m[word.size()] += word + " ";
    for (const auto& pair: m) 
        rs << pair.second;
    string result = rs.str();
    
    result.pop_back();
    result += ".";
    result[0] = toupper(result[0]);
    return result;
}
    
int main() {
    string text;
    getline(cin, text);
    string result = sortWords(text);
    cout << result << endl;
}