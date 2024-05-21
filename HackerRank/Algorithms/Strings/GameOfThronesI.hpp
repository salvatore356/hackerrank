//
//  GameOfThronesI.hpp
//  HackerRank
//
//  Created by Salvatore on 20/5/24.
//

#ifndef GameOfThronesI_hpp
#define GameOfThronesI_hpp

#include <stdio.h>

namespace GameOfThronesI {

    string gameOfThrones(string s) {
        unordered_map<char, int> count;
        
        for (char &c : s) ++count[c];
        
        int noPairs = 0;
        
        for (auto &c : count) {
            noPairs += c.second % 2 != 0;
            if (noPairs > 1) return "NO";
        }
        
        return "YES";
    }

    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/Strings/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string s;
        getline(input, s);

        string result = gameOfThrones(s);
        string t_out;
        getline(output, t_out);
        assert(result == t_out, result + " == " + t_out);
    }
}

#endif /* GameOfThronesI_hpp */
