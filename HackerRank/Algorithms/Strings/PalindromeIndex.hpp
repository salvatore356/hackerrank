//
//  PalindromeIndex.hpp
//  HackerRank
//
//  Created by Salvatore on 16/5/24.
//

#ifndef PalindromeIndex_hpp
#define PalindromeIndex_hpp

#include <stdio.h>

namespace PalindromeIndex {

    int palindromeIndex(string s) {
        int head = 0, tail = (int) s.size() - 1;
        
        while (head < tail) {
            if (s[head] == s[tail]) {
                ++head; --tail;
            }else if (s[head + 1] == s[tail] && s[head + 2] == s[tail - 1]){
                return head;
            }else if (s[head] == s[tail - 1]) {
                return tail;
            }
        }
        
        return -1;
        
    }

    void test() {
        
        string path = "Tests/Algorithms/Strings/PalindromeIndex/";
        std::ifstream input(path  +  "input11.txt");
        std::ifstream output(path + "output11.txt");

        string q_temp, t_out;
        getline(input, q_temp);

        int q = stoi(ltrim(rtrim(q_temp)));

        for (int q_itr = 0; q_itr < q; q_itr++) {
            string s;
            getline(input, s);

            int result = palindromeIndex(s);

            getline(output, t_out);
            assert(result == stoi(t_out), to_string(result) + " == " + t_out);
        }

    }
}

#endif /* PalindromeIndex_hpp */
