//
//  XORStrings.hpp
//  HackerRank
//
//  Created by Salvatore on 5/6/24.
//

#ifndef XORStrings_hpp
#define XORStrings_hpp

#include <stdio.h>

namespace XORStrings {

    string strings_xor(string s, string t) {

        string res = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == t[i])
                res += '0';
            else
                res += '1';
        }

        return res;
    }

    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/Debugging/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string t_out;
        
        string s, t;
        input >> s >> t;
        string result = strings_xor(s, t);
        getline(output, t_out);
        assert(result == t_out, result + " == " + t_out);
    }
}

#endif /* XORStrings_hpp */
