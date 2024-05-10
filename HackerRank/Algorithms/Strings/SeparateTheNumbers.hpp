//
//  SeparateTheNumbers.hpp
//  HackerRank
//
//  Created by Salvatore on 10/5/24.
//

#ifndef SeparateTheNumbers_hpp
#define SeparateTheNumbers_hpp

#include <stdio.h>

namespace SeparateTheNumbers {


    string separateNumbers(string s) {
        
        int len = floor(s.length()/2.0);
        
        for(int i = 1; i <= len ; ++i) {
            
            string a = s.substr(0, i);
            long q = stol(a);
            int w = 1;
            
            while (a.length()< s.length()) {
                a += to_string(q + w);
                ++w;
            }
            
            if (a == s) return "YES " + to_string(q);
                
            
        }
        
        return "NO";
    }

    void test() {
        
        string path = "Tests/Algorithms/Strings/SeparateTheNumbers/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");
        
        string q_temp;
        getline(input, q_temp);

        int q = stoi(ltrim(rtrim(q_temp)));

        for (int q_itr = 0; q_itr < q; q_itr++) {
            string s;
            getline(input, s);

            string result = separateNumbers(s);
            
            string t_out;
            getline(output, t_out);
            
            assert(result == t_out, result + " == " + t_out);
        }

    }

}

#endif /* SeparateTheNumbers_hpp */
