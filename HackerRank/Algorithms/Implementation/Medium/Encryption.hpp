//
//  Encryption.hpp
//  HackerRank
//
//  Created by Salvatore on 12/6/24.
//

#ifndef Encryption_hpp
#define Encryption_hpp

#include <stdio.h>

namespace Encryption {

    string encryption(string s) {
        s.erase(remove(s.begin(), s.end(), '-'), s.end());
        int rows = ceil(sqrt(s.size()));
        
        vector<string> words(rows);
        
        for (int i = 0; i < s.size(); ++i) {
            words[i % rows].push_back(s[i]);
        }
        
        string ans = words.front();
        for (int i = 1; i < words.size(); ++i)
            ans += " " + words[i];
        
        return ans;
    }

    void test() {
        string test_case = "00";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        string s;
        getline(io.input, s);

        string result = encryption(s);

        getline(io.output, t_out);
        assert(result == t_out, result + " == " + t_out);
    }
}

#endif /* Encryption_hpp */
