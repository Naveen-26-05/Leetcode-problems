#include <iostream>
#include <string>
using namespace std;

int minimumLength(string s) {
    int i = 0, j = s.size() - 1;
    char prev_pref = '-';
    char prev_suf = '-';
    
    while (i < j) {                                     // O(n)
        if (prev_pref == s[i] || prev_suf == s[j]) {
            if (prev_pref == s[i]) {
                prev_pref = s[i];
                s[i] = '-';
                i++;
            }
            if (prev_suf == s[j]) {
                prev_suf = s[j];
                s[j] = '-';
                j--;
            }
            continue;
        }
        if (s[i] == s[j]) {
            prev_pref = s[i];
            prev_suf = s[j];
            s[i] = '-';
            s[j] = '-';
            j--;
            i++;
        } else {
            break;
        }
    }
    if (i == j) {
        if (prev_pref == s[i] || prev_suf == s[j]) {
            return 0;
        }
    }
    return j - i + 1;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    int minLength = minimumLength(input);
    cout << "Minimum length of the modified string: " << minLength << endl;

    return 0;
}

