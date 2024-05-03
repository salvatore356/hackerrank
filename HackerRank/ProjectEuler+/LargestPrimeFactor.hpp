//
//  LargestPrimeFactor.hpp
//  HackerRank
//
//  Created by Salvatore on 3/5/24.
//

#ifndef LargestPrimeFactor_hpp
#define LargestPrimeFactor_hpp

#include <stdio.h>

namespace LargestPrimeFactor {

    long largestPrimeFactor (long n) {
        long i = 2;
        for (; i * i < n ; ++i) {
            
            while (n % i == 0) n /= i;
            if (n == 1) break;
        }
        
        return n % i == 0 ? i : n;
    }


    void test() {
        string path = "Tests/ProjectEuler+/LargestPrimeFactor/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");
        
        string t_temp;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));
        string out;
        for (int t_itr = 0; t_itr < t; t_itr++) {
            string n_temp;
            getline(input, n_temp);

            long n = stol(ltrim(rtrim(n_temp)));
            long result = largestPrimeFactor (n);
            getline(output, out);
            assert(result == stol(out), to_string(result) + " == " + out);
        }
    }
}

#endif /* LargestPrimeFactor_hpp */
