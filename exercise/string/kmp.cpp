#include <iostream>

using namespace std;

void getNext(int *next, const string& s) {
    int j = -1;
    next[0] = j;
    for(int i = 1; i < s.size(); i++) {
        while (j >= 0 && s[i] != s[j+1]) {
            j = next[j];
        }
        if (s[i] == s[j+1]) {
            j++;
        }
        next[i] = j;
    }
}

int main() {
    string s = "aabaaf";
    int next[6] = {0};
    getNext(next, s);
    for (int i = 0; i < 6; i++) {
        cout << next[i] << " ";
    }
}