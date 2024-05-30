//
//  SumVsXOR.hpp
//  HackerRank
//
//  Created by Salvatore on 30/5/24.
//

#ifndef SumVsXOR_hpp
#define SumVsXOR_hpp

#include <stdio.h>

namespace SumVsXOR {

    long sumXor(long n) {
        long ans = 1;
        
        while (n) {
            if (n%2 == 0) ans *= 2;
            n /= 2;
        }
        return ans;
    }

    void test()
    {
        string test_case = "11";
        string path = "Tests/Algorithms/BitManipulation/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string t_out;

        string n_temp;
        getline(input, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        long result = sumXor(n);
        
        getline(output, t_out);
        assert(result == stol(t_out), to_string(result) + " == " + t_out);
    }
}

#endif /* SumVsXOR_hpp */
