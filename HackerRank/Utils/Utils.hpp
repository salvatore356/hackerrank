//
//  Utils.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>
#include <vector>
#include <fstream> // For file input/output


using namespace std;

inline string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !isspace(c); })
    );

    return s;
}

inline string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !isspace(c); }).base(),
        s.end()
    );

    return s;
}

inline string trim(const string &str) {
    
    return rtrim(ltrim(str));
}

inline vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

void assert(bool condition, const std::string& message = "") {
    if (!condition) {
        cerr << "Assertion failed: " << message << endl;
        exit(EXIT_FAILURE);
    }else {
        cout << "Assertion passed: " << message << endl;
    }
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

template <typename T>
string vector_to_string(vector<T> &arr){
    string ans = "";
    
    for (int i = 0; i < arr.size(); ++i) {
        ans += to_string(arr[i]) + " ";
    }
    
    return trim(ans);
}

#endif /* Utils_hpp */
