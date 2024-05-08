//
//  Pangrams.hpp
//  HackerRank
//
//  Created by Salvatore on 8/5/24.
//

#ifndef Pangrams_hpp
#define Pangrams_hpp

#include <stdio.h>

namespace Pangrams {

    string pangrams(string s) {
        vector<bool> letters(26);
        
        for (int i = 0; i < s.size(); ++i)
            if (isalpha(s[i]))
                letters[tolower(s[i]) - 'a'] = true;
            
        for (auto c : letters)
            if(!c) return "not pangram";
        
        return "pangram";
    }

    void test() {
        string path = "Tests/Algorithms/Strings/Pangrams/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string s;
        getline(input, s);

        string result = pangrams(s);

        string t_out;
        
        getline(output, t_out);
        assert(result == t_out, result + " == " + t_out);
    }
}

#endif /* Pangrams_hpp */
