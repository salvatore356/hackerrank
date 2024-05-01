//
//  SuperReducedString.hpp
//  HackerRank
//
//  Created by Salvatore on 1/5/24.
//

#ifndef SuperReducedString_hpp
#define SuperReducedString_hpp

#include <stdio.h>

namespace SuperReducedString {

    string superReducedString(string s) {
        int index = 0;
        while(index < s.size()) {
            if(s[index] == s[index + 1]){
                s.erase(index + 1, 1);
                s.erase(index, 1);
                index = max(0, index - 1);
            } else ++index;
        }
        return s == "" ? "Empty String" : s;
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/SuperReducedString/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string s;
        getline(input, s);

        string result = superReducedString(s);

        string out;
        getline(output, out);
        assert(result == out, result + " == " + out);
    }
}

#endif /* SuperReducedString_hpp */
