#include <iostream>
#include <string>

using namespace std;

void getNext(int* next, const string& s) {
    int j = -1;
    next[0] = -1;
    for(int i = 1; i < s.size(); i++) {
        while(j >= 0 && s[i] != s[j+1]) {
            j = next[j]; // 向前回溯
        }
        if (s[i] == s[j+1]) {  // 找到相同的前后缀
            j++; 
        }
        next[i] = j; // 将j(前缀的长度) 赋值给next[i]
    }
}
int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
        return 0;
    }
    int next[needle.size()];
    getNext(next, needle);
    int j = -1;
    for(int i = 0; i < haystack.size(); i++) {
        while(j >= 0 && haystack[i] != needle[j+1]) {
            j = next[j];
        }
        if(haystack[i] == needle[j+1]) {
            j++;
        }
        if (j == (needle.size() -1)) {
            return (i-needle.size() + 1);
        }
    }
    return -1;
}
int main(){
    string haystack {"abbabbababaaababaaa"};
    string needle {"ababaaababaa"};
    int res = strStr(haystack, needle);
    cout << res << endl;

}