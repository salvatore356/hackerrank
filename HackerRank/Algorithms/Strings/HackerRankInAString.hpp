//
//  HackerRankInAString.hpp
//  HackerRank
//
//  Created by Salvatore on 8/5/24.
//

#ifndef HackerRankInAString_hpp
#define HackerRankInAString_hpp

#include <stdio.h>

namespace HackerRankInAString {

    string hackerrankInString(string s) {
        string hackerrank = "hackerrank";
        int currentIndex = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            currentIndex += hackerrank[currentIndex] == s[i];
            if (currentIndex == hackerrank.size()) return "YES";
        }
        
        return "NO";
    }

    void test() {
        string path = "Tests/Algorithms/Strings/HackerRankInAString/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string q_temp, t_out;
        getline(input, q_temp);

        int q = stoi(ltrim(rtrim(q_temp)));

        for (int q_itr = 0; q_itr < q; q_itr++) {
            string s;
            getline(input, s);

            string result = hackerrankInString(s);
            
            getline(output, t_out);
            assert(result == t_out, result + " == " + t_out);
        }
    }
}

#endif /* HackerRankInAString_hpp */
