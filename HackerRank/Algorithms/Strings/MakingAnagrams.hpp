//
//  MakingAnagrams.hpp
//  HackerRank
//
//  Created by Salvatore on 17/5/24.
//

#ifndef MakingAnagrams_hpp
#define MakingAnagrams_hpp

#include <stdio.h>

namespace MakingAnagrams {

    int makingAnagrams(string s1, string s2) {
        unordered_map<char, int> count;
        
        for (int i = 0; i < s1.size(); ++i)
            ++count[s1[i]];
            
        for (int i = 0; i < s2.size(); ++i)
            --count[s2[i]];
        
        int deletions = 0;
        for (auto &c : count)
            deletions += abs(c.second);
            
        return deletions;
    }

    void test() {
        
        string test_case = "00";
        string path = "Tests/Algorithms/Strings/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string s1;
        getline(input, s1);

        string s2;
        getline(input, s2);

        int result = makingAnagrams(s1, s2);
        string t_out;
        getline(output, t_out);
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);
    }
}

#endif /* MakingAnagrams_hpp */
