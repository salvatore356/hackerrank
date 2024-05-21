//
//  StringConstruction.hpp
//  HackerRank
//
//  Created by Salvatore on 21/5/24.
//

#ifndef StringConstruction_hpp
#define StringConstruction_hpp

#include <stdio.h>

namespace StringConstruction {

    int stringConstruction(string s) {
        set<char> letters;
        
        for (auto &c : s)
            letters.insert(c);
        
        return (int)letters.size();
    }

    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/Strings/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");
        
        string q_temp, t_out;
        getline(input, q_temp);

        int q = stoi(ltrim(rtrim(q_temp)));

        for (int q_itr = 0; q_itr < q; q_itr++) {
            string s;
            getline(input, s);

            int result = stringConstruction(s);

            getline(output, t_out);
            assert(result == stoi(t_out), to_string(result) + " == " + t_out);
        }
    }
}

#endif /* StringConstruction_hpp */
