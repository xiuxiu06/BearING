#include <iostream>
#include <string>
#include <string_view>
#include <cctype>
#include <algorithm>

using namespace std;

bool is_vowel(char a) {
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

bool is_consonant(char a) {
    return isalpha(a) && !is_vowel(a);
}

bool ends_with_double_consonant(string_view a) {
    int len = a.length();
    return len >= 2 && is_consonant(a[len - 1]) && a[len - 1] == a[len - 2];
}

bool ends_with_cvc(string_view a) {
    int len = a.length();
    if (len < 3) return false;
    return is_consonant(a[len - 3]) && is_vowel(a[len - 2]) && is_consonant(a[len - 1]);
}

bool contains_vowel(string_view a) {
    return any_of(a.begin(), a.end(), [](char c) { return is_vowel(c); });
}

int count_vowels_at_back(string_view a) {
    int count = 0;
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        if (is_vowel(*it)) count++;
        else break;
    }
    return count;
}

int count_consonants_at_front(string_view a) {
    int count = 0;
    for (char c : a) {
        if (is_consonant(c)) count++;
        else break;
    }
    return count;
}

bool ends_with(string_view candidate, string_view suffix) {
    if (suffix.length() > candidate.length()) return false;
    return candidate.compare(candidate.length() - suffix.length(), suffix.length(), suffix) == 0;
}

string new_ending(string candidate, int suffix_length, string_view replacement) {
    return candidate.substr(0, candidate.length() - suffix_length) + string(replacement);
}
