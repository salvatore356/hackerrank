//
//  FunnyString.hpp
//  HackerRank
//
//  Created by Salvatore on 10/5/24.
//

#ifndef FunnyString_hpp
#define FunnyString_hpp

#include <stdio.h>

namespace FunnyString {

    string funnyString(string s) {
        
        int limit = (int) s.size() - 1;
        
        for(int i = 0; i < limit; ++i) {
            
            if (abs(s[i] - s[i+1]) != abs(s[limit - i] - s[limit - (i + 1) ]))
                return "Not Funny";
            
        }
        
        return "Funny";
    }

    void test() {
        
        string path = "Tests/Algorithms/Strings/SeparateTheNumbers/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string q_temp;
        getline(input, q_temp);

        int q = stoi(ltrim(rtrim(q_temp)));

        for (int q_itr = 0; q_itr < q; q_itr++) {
            string s;
            getline(input, s);

            string result = funnyString(s);
            
            string t_out;
            getline(output, t_out);
            
            assert(result == t_out, result + " == " + t_out);
        }
    }
}

#endif /* FunnyString_hpp */
