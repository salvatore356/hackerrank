//
//  ExtraLongFactorials.hpp
//  HackerRank
//
//  Created by Salvatore on 7/6/24.
//

#ifndef ExtraLongFactorials_hpp
#define ExtraLongFactorials_hpp

#include <stdio.h>

namespace ExtraLongFactorials {

    void mult(string &num, int m) {
        int rest = 0;
        for (int j = (int)num.size() - 1; j >= 0; --j) {
            int temp = ((num[j] - '0') * m) + rest;
            num[j] = '0' + (temp % 10);
            rest = temp / 10;
        }
        if(rest > 0) num = to_string(rest) + num;
    }

    string extraLongFactorials(int n) {
        string ans = to_string(1);
        
        for (int i = 2; i <= n; ++i) {
            mult(ans, i);
        }
        return ans;
    }

    void test(){
        string test_case = "00";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;
        
        string n_temp;
        getline(io.input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string result = extraLongFactorials(n);
        
        getline(io.output, t_out);
        assert(result == t_out, result + " == " + t_out);
    }
}

#endif /* ExtraLongFactorials_hpp */
