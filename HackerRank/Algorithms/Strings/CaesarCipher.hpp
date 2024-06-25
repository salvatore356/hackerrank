//
//  CaesarCipher.hpp
//  HackerRank
//
//  Created by Salvatore on 6/5/24.
//

#ifndef CaesarCipher_hpp
#define CaesarCipher_hpp

#include <stdio.h>

namespace CaesarCipher {

    string caesarCipher(string s, int k) {
        
        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i])) {
                char temp = 'a' + (((tolower(s[i]) - 'a') + k) % 26);
                if (isupper(s[i]))
                    s[i] = toupper(temp);
                else s[i] = temp;
            }
                
        }
        
        return s;
    }

    void test() {
        
        string path = "Tests/Algorithms/Strings/CaesarCipher/";
        std::ifstream input(path  +  "input05.txt");
        std::ifstream output(path + "output05.txt");

        string n_temp;
        getline(input, n_temp);

        //int n = stoi(ltrim(rtrim(n_temp)));

        string s;
        getline(input, s);

        string k_temp;
        getline(input, k_temp);

        int k = stoi(ltrim(rtrim(k_temp)));

        string result = caesarCipher(s, k);

        string out_temp;
        getline(output, out_temp);
        
        assert(result == out_temp, result + " == " + out_temp);
    }
}

#endif /* CaesarCipher_hpp */
