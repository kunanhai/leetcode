#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* string reverseStr(string s, int k) {
    for (int i = 0, j = k - 1; i < s.size(); i += 2*k, j += 2*k) {
        int left = i;
        int right = j;
        if (right > s.size() -1) {
            right = s.size() - 1;
        }
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    return s;
} */

string removeExtraSpace(string s) {
    //  移除开头多余空格
    int start_idx = 0;
/*     while (s[start_idx] == ' ') {
       start_idx++;
    } */

    int slowIndex = start_idx;
    int fastIndex = start_idx;

    while(s[fastIndex] == ' ') {
        fastIndex++;
    }
    for (; fastIndex < s.size(); fastIndex++) {
        if(fastIndex - 1 > 0 && s[fastIndex] ==' ' && s[fastIndex] == s[fastIndex -1]){
            continue;
        }

        s[slowIndex++] = s[fastIndex];
    }

    if (s[slowIndex - 1] == ' ') {
        s.resize(start_idx + slowIndex -1);
    } else {
        s.resize(start_idx + slowIndex);
    }

    return s;
}

string ljreverseWords(string s) {
    //移除所有多余空格
    cout << "before removeExtraSpace: " << s << "len: " << s.size() << endl;
    s = removeExtraSpace(s);
    cout << "after removeExtraSpace: " << s << "len: " << s.size() << endl;
    //反转字符串
    reverse(s.begin(), s.end());
    cout << "after reverse: " << s << "len: " << s.size() << endl;
    //反转字符串
    //再反转
    int start = 0;
    for (int i = 0; i < s.size(); i++) {
        int j = i;
        while ( j < s.size() && s[j] != ' ') {
            j++;
        }
        reverse(s.begin() + i, s.begin() + j);

        i = j;
    }

    cout << s << " " << s.size() << endl;
    return s;
}

string reverseLeftWords(string s, int n) {
    string s1 = s.substr(0, n);
    string s2 = s.substr(n, s.size());
    return s2 + s1;
}
int main() {
    string s = "lijie";
    string res = reverseLeftWords(s, 2);
    cout << res << endl;
}