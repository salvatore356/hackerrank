//
//  Anagram.hpp
//  HackerRank
//
//  Created by Salvatore on 17/5/24.
//

#ifndef Anagram_hpp
#define Anagram_hpp

#include <stdio.h>

namespace Anagram {

    int anagram(string s) {
        
        if (s.size() % 2 != 0) return -1;
        int mid = (int)s.size() / 2;
        int changes = 0;
        
        unordered_map<char, int> count;
        for (int i = 0; i < mid; ++i)
            ++count[s[i]];
        
        for (int i = mid; i < s.size(); ++i)
            --count[s[i]];
            
        for ( auto &c : count)
            if( c.second > 0) changes += c.second;
        
        return changes;
    }

    void test() {
        string path = "Tests/Algorithms/Strings/Anagram/";
        std::ifstream input(path  +  "input15.txt");
        std::ifstream output(path + "output15.txt");

        string q_temp, t_out;
        getline(input, q_temp);

        int q = stoi(ltrim(rtrim(q_temp)));

        for (int q_itr = 0; q_itr < q; q_itr++) {
            string s;
            getline(input, s);

            int result = anagram(s);

            getline(output, t_out);
            assert(result == stoi(t_out), to_string(result) + " == " + t_out);
        }

    }
}

#endif /* Anagram_hpp */
