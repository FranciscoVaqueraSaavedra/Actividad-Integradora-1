//
// Created by Franc on 20/05/2025.
//

#ifndef PALINDROME_H
#define PALINDROME_H

#include <string>
#include <utility>

std::pair<int, int> expand_center(const std::string &text, int left, int right) {
    int n = text.size();
    while (left >= 0 && right < n && text[left] == text[right]) {
        --left;
        ++right;
    }
    return {left + 1, right - left - 1};
}

std::pair<int, int> longest_palindrome(const std::string &text) {
    int n = text.size();
    if (n == 0) return {1, 1};
    int start = 0, max_len = 1;
    for (int i = 0; i < n; ++i) {
        auto [s1, l1] = expand_center(text, i, i);
        auto [s2, l2] = expand_center(text, i, i + 1);
        if (l1 > max_len) { start = s1; max_len = l1; }
        if (l2 > max_len) { start = s2; max_len = l2; }
    }
    return {start, max_len};
}

#endif
