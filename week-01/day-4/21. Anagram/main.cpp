#include <iostream>
#include <string>

void swap (int &a, int &b) {
    int s = a;
    a = b;
    b = s;
}

void bubble (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap (arr[j], arr[j + 1]);
            }
        }
    }
}

bool anagram (std::string a, std::string b) {
    int aa[a.length()];
    int bb[b.length()];
    bool f = false;
    int tr = 0;

    if (a.length() != b.length()) {
        f = false;                                  //If they are not the same length, they cannot be anagrams
    } else {
        for (int i = 0; i < a.length(); i++) {
            aa[i] = a[i];
        }
        bubble(aa, sizeof(aa) / sizeof(int));

        for (int i = 0; i < b.length(); i++) {
            bb[i] = b[i];
        }
        bubble(bb, sizeof(bb) / sizeof(int));
    }
    for (int i = 0; i < a.length(); i++) {
        std::cout << aa[i] << "\t";
    }
    std::cout<< std::endl;

    for (int i = 0; i < b.length(); i++) {
        std::cout << bb[i] << "\t";
    }
    std::cout << std::endl;

    for (int i = 0; i < a.length(); i++) {
        if (aa[i] == bb[i]) {
               tr += 1;
        }
        if (tr == a.length()) {
            f = true;
        }
    }
    return f;
}




int main(int argc, char* args[]) {
    // Create a function named anagram following your current language's style guide.
    // It should take two strings and return a boolean value
    // depending on whether its an anagram or not.

    std::string a = "abba";
    std::string b = "bbaa";

    if (anagram(a, b) == true) {
        std::cout << "They are anagrams!\n";
    } else {
        std::cout << "They are NOT anagrams\n";
    }
    return 0;
}