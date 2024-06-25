//
//  BeautifulBinaryString.hpp
//  HackerRank
//
//  Created by Salvatore on 14/5/24.
//

#ifndef BeautifulBinaryString_hpp
#define BeautifulBinaryString_hpp

#include <stdio.h>

namespace BeautifulBinaryString {

    int beautifulBinaryString(string b) {
        string c = "010";
        int current = 0;
        int changes = 0;
        for (int i = 0; i < b.size(); ++i){
            if (b[i] != c[current]) current = 0;
            current += b[i] == c[current];
            
            if (current == 3) {
                ++changes;
                current = 0;
            }
        }
        return changes;
    }

    void test() {
        string path = "Tests/Algorithms/Strings/BeautifulBinaryString/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string n_temp;
        getline(input, n_temp);

        //int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(input, b);

        int result = beautifulBinaryString(b);

        string t_out;
        getline(output, t_out);
        
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);
    }
}

#endif /* BeautifulBinaryString_hpp */
