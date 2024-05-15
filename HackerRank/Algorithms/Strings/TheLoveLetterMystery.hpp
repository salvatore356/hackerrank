//
//  TheLoveLetterMystery.hpp
//  HackerRank
//
//  Created by Salvatore on 15/5/24.
//

#ifndef TheLoveLetterMystery_hpp
#define TheLoveLetterMystery_hpp

#include <stdio.h>

namespace TheLoveLetterMystery {

    int theLoveLetterMystery(string s) {
        int limit = s.size() / 2;
        int changes = 0;
        
        for (int i = 0; i < limit; ++i) {
            changes += abs(s[i] - s[s.size() - ( i + 1)]);
        }
        
        return changes;
    }

    void test() {
        string path = "Tests/Algorithms/Strings/TheLoveLetterMystery/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string q_temp, t_out;;
        getline(input, q_temp);

        int q = stoi(ltrim(rtrim(q_temp)));

        for (int q_itr = 0; q_itr < q; q_itr++) {
            string s;
            getline(input, s);

            int result = theLoveLetterMystery(s);

            
            getline(output, t_out);
            assert(result == stoi(t_out), to_string(result) + " == " + t_out);
        }

    }
}

#endif /* TheLoveLetterMystery_hpp */
