//
//  MarsExploration.hpp
//  HackerRank
//
//  Created by Salvatore on 7/5/24.
//

#ifndef MarsExploration_hpp
#define MarsExploration_hpp

#include <stdio.h>

namespace MarsExploration {

    int marsExploration(string s) {
        int changed = 0;
        
        for (int i = 0; i < s.size(); i+= 3) {
            changed += s[i] != 'S';
            changed += s[i+1] != 'O';
            changed += s[i+2] != 'S';
        }
        
        return changed;
    }

    void test() {
        string path = "Tests/Algorithms/Strings/MarsExploration/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string s;
        getline(input, s);

        int result = marsExploration(s);
        string out_temp;
        getline(output, out_temp);
        
        assert(result == stoi(out_temp), to_string(result) + " == " + out_temp);
        
    }
}

#endif /* MarsExploration_hpp */
