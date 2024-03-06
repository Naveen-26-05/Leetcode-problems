#include <iostream>
#include <string>
using namespace std;

int minimumLength(string s) {
    int i = 0, j = s.size() - 1;
    char hist = '-';
    while (i < j) {                                     // O(n)
        if ( hist == s[j]) {
            if (hist == s[i]) {
                hist = s[i];
                s[i] = '-';
                i++;
            }
            if (hist == s[j]) {
                hist = s[j];
                s[j] = '-';
                j--;
            }
            continue;
        }
        if (s[i] == s[j]) {
            hist = s[i];
            s[i] = '-';
            s[j] = '-';
            j--;
            i++;
        } else {
            break;
        }
    }
    if (i == j) {
        if (hist == s[i] || hist == s[j]) {
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

