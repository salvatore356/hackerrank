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

#endif /* Utils_hpp */
