//
//  CamelCase.hpp
//  HackerRank
//
//  Created by Salvatore on 1/5/24.
//

#ifndef CamelCase_hpp
#define CamelCase_hpp

#include <stdio.h>

namespace CamelCase {

    int camelcase(string s) {
        int words = s.size() > 0;
        for(int i = 0; i < s.size(); ++i)
            words += isupper(s[i]) != 0;
        return words;
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/CamelCase/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string s;
        getline(input, s);

        int result = camelcase(s);
        
        string out;
        getline(output, out);
        assert(result == stoi(out), to_string(result) + " == " + out);
        
    }
}

#endif /* CamelCase_hpp */
