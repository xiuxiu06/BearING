# include <string>

/*
 * is_vowel
 *
 * Determine whether _maybe_vowel_ is a vowel. Note: 'y' is *not* a vowel.
 *
 * input: maybe_vowel: The character to check for "vowelness".
 * output: true, if _maybe_vowel_ is a vowel; false, otherwise.
 */
bool is_vowel(char maybe_vowel)
{
    if (maybe_vowel == 'a' || maybe_vowel == 'e' || maybe_vowel == 'i' || maybe_vowel == 'o' || maybe_vowel == 'u') {
        return true;
    }
    return false;
}

/*
 * is_consonant
 *
 * Determine whether _maybe_consonant_ is a consonant. Note: 'y' is a consonant.
 *
 * input: maybe_consonant: The character to check for "consonantness".
 * output: true, if _maybe_consonant_ is a consonant; false, otherwise.
 */
bool is_consonant(char maybe_consonant)
{
    if (!(is_vowel(maybe_consonant))) {
        return true;
    }
    return false;
}

/*
 * ends_with_double_consonant
 *
 * Determine whether _ends_with_double_consonants_ ends with the same two letters
 * and those letters are both consonants. If _ends_with_double_consonants_ has fewer
 * than two letters, the result is false.
 *
 * input: ends_with_double_consonants: The string to check for a double-consontant ending.
 * output: true, if the string ends in the same two letters *and*
 *         those letters are both consontants; false, otherwise.
 *         false, if the string is shorter than 2 characters long.
 */
bool ends_with_double_consonant(std::string ends_with_double_consonants)
{
    if (ends_with_double_consonants.length() >= 2 &&
        is_consonant(ends_with_double_consonants[ends_with_double_consonants.length() - 1]) &&
        is_consonant(ends_with_double_consonants[ends_with_double_consonants.length() - 2]) &&
        (ends_with_double_consonants[ends_with_double_consonants.length() - 1] == ends_with_double_consonants[ends_with_double_consonants.length() - 2]))
    {
        return true;
    }
    return false;
}

/*
 * ends_with_cvc
 *
 * Determine whether _ends_with_cvc_ ends with the combination of
 * a consonant, a vowel and a consonant. If _ends_with_cvc_ is shorter
 * than three characters, the function returns false.
 *
 * input: ends_with_cvc: The string to test for a consonant, vowel,
 *        consonant ending.
 * output: true, if _ends_with_cvc_ ends in a combination of a consonant,
 *         vowel and consonant. false, otherwise. If _ends_with_cvc_ is
 *         shorter than three characters, ends_with_cvc will return
 *         false.
 */
bool ends_with_cvc(std::string ends_with_cvc)
{
    if (ends_with_cvc.length() >= 3 &&
        is_consonant(ends_with_cvc[ends_with_cvc.length() - 1]) &&
        is_vowel(ends_with_cvc[ends_with_cvc.length() - 2]) &&
        is_consonant(ends_with_cvc[ends_with_cvc.length() - 3]))
    {
        return true;
    }
    return false;
}

/*
 * contains_vowel
 *
 * Determine whether _contains_vowel_ contains a vowel. Note, this function
 * uses is_vowel to determine whether a character is a vowel.
 *
 * input: contains_vowel: The string to test for containing a vowel.
 * output: true, if _contains_vowel_ contains a vowel; false, otherwise. Note:
 *         this function uses is_vowel to determine whether a
 *         character is a vowel.
 */
bool contains_vowel(std::string contains_vowel)
{
    for (char b : contains_vowel)
    {
        if (is_vowel(b)) {
            return true;
        }
    }
    return false;
}

/*
 * count_consonants_at_front
 *
 * Count the number of consecutive consonants at the
 * start of _count_consonants_at_front_.
 *
 * input: count_consonants_at_front: The string from which to count the number of
 *        consecutive consonants at the front.
 * output: the number of consecutive consonants at
 *         the front of _count_consonants_at_front_. Note: Uses is_consonant to
 *         determine whether a character is a consonant.
 */
int count_consonants_at_front(std::string count_consonants_at_front)
{
    int count = 0;
    for (char c : count_consonants_at_front)
    {
        if (is_consonant(c))
        {
            count++;
        }
        else {
            break;
        }
    }
    return count;
}

/*
 * count_vowels_at_back
 *
 * Count the number of consecutive vowels at the
 * end of _count_vowels_at_back_.
 *
 * input: count_vowels_at_back: The string from which to count the number of
 *        consecutive vowels at the end.
 * output: the number of consecutive consonants at
 *         the end of _count_vowels_at_back_. Note: Uses is_vowel to
 *         determine whether a character is a consonant.
 */
int count_vowels_at_back(std::string count_vowels_at_back)
{
    int count = 0;
    for (int i = count_vowels_at_back.length() - 1; i >= 0; --i)
    {
        if (is_vowel(count_vowels_at_back[i]))
        {
            count++;
        }
        else {
            break;
        }
    }
    return count;
}

/*
 * ends_with
 *
 * Determine whether _candidate_ ends with _suffix_.
 *
 * input: candidate: The string for which to check the ending.
 *        suffix: The string to test against the ending of _candidate_.
 * output: true if _candidate_ ends with _suffix_; false, otherwise.
 */
bool ends_with(std::string candidate, std::string suffix)
{
    if (candidate.empty() && suffix.empty()) {
        return true;
    }
    if (candidate.empty()) {
        return false;
    }
    if (suffix.length() > candidate.length()) {
        return false;
    }
    std::string candidate_suffix = candidate.substr(candidate.length() - suffix.length());
    return candidate_suffix == suffix;
}

/*
 * new_ending
 *
 * new_ending will create a new string whose contents are the
 * same as _candidate_ except that the last _suffixlength_
 * characters are replaced with the contents of _replacement_.
 *
 * input: candidate: The string of which to modify the ending.
 *        suffixlength: The number of characters to remove from _candidate_.
 *        replacement: The string with which to replace the
 *        last _suffixlength_ characters of _candidate_.
 * output: _candidate_ with the last _suffixlength_ characters
 *         replaced with the contents of _replacement_.
 */
std::string new_ending(std::string candidate, int suffixlength, std::string replacement)
{
    return candidate.substr(0, candidate.length() - suffixlength) + replacement;
}
