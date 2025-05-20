
/* This source file must have a .cpp extension so that all C++ compilers
   recognize the extension without flags.  Borland does not know .cxx for
   example.  */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//hola fra
using namespace std;

string  read_file_content(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        exit(1);
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return content;
}

pair<bool, size_t> contains_pattern(const string &text, const string &pattern) {
    size_t pos = text.find(pattern);
    return (pos != string::npos) ? make_pair(true, pos + 1) : make_pair(false, static_cast<size_t>(0));

}


pair<int, int> expand_center(const string &text, int left, int right) {
    int n = text.size();
    while (left >= 0 && right < n && text[left] == text[right]) {
        --left;
        ++right;
    }
    return {left + 1, right - left - 1}; // start index, length
}

pair<int, int> longest_palindrome(const string &text) {
    int n = text.size();
    if (n == 0) return {1, 1};

    int start = 0, max_len = 1;

    for (int i = 0; i < n; ++i) {
        auto [s1, l1] = expand_center(text, i, i);       // Odd-length palindrome
        auto [s2, l2] = expand_center(text, i, i + 1);   // Even-length palindrome

        if (l1 > max_len) {
            start = s1;
            max_len = l1;
        }
        if (l2 > max_len) {
            start = s2;
            max_len = l2;
        }
    }

    return {start + 1, start + max_len};
}



pair<int, int> longest_common_substring(const string &text1, const string &text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLen = 0, endIdx = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIdx = i;
                }
            }
        }
    }
    return {endIdx - maxLen + 1, endIdx};
}

int main() {
    // Leer archivos
    string transmission1 =  read_file_content("C:/Users/Franc/CLionProjects/Actividad Integradora 1/transmission1.txt");
    string transmission2 =  read_file_content("C:/Users/Franc/CLionProjects/Actividad Integradora 1/transmission2.txt");
    vector<string> mcodes = {
         read_file_content("C:/Users/Franc/CLionProjects/Actividad Integradora 1/mcode1.txt"),
         read_file_content("C:/Users/Franc/CLionProjects/Actividad Integradora 1/mcode2.txt"),
         read_file_content("C:/Users/Franc/CLionProjects/Actividad Integradora 1/mcode3.txt")
    };

    cout << "Parte 1:" << endl;
    for (int i = 0; i < 3; i++) {
        auto result1 = contains_pattern(transmission1, mcodes[i]);

        if (result1.first)
            cout << "true " << result1.second << endl;
        else
            cout << "false" << endl;
    }

    for (int i = 0; i < 3; i++) {
        auto result2 = contains_pattern(transmission2, mcodes[i]);

        if (result2.first)
            cout << "true " << result2.second << endl;
        else
            cout << "false" << endl;
    }


    auto palindrome1 = longest_palindrome(transmission1);
    auto palindrome2 = longest_palindrome(transmission2);
    cout << "Parte 2:" << endl;
    cout << palindrome1.first << " " << palindrome1.second << " "
         << transmission1.substr(palindrome1.first - 1, (palindrome1.second - palindrome1.first + 1)) << endl;
    cout << palindrome2.first << " " << palindrome2.second << " "
         << transmission2.substr(palindrome2.first - 1, (palindrome2.second - palindrome2.first + 1)) << endl;


    auto commonSubstring = longest_common_substring(transmission1, transmission2);
    cout << "Parte 3:" << endl;
    cout << commonSubstring.first << " " << commonSubstring.second << " "
         << transmission1.substr(commonSubstring.first - 1, (commonSubstring.second - commonSubstring.first + 1)) << endl;


    return 0;
}
