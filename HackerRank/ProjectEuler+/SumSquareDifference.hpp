//
//  SumSquareDifference.hpp
//  HackerRank
//
//  Created by Salvatore on 6/5/24.
//

#ifndef SumSquareDifference_hpp
#define SumSquareDifference_hpp

#include <stdio.h>

namespace SumSquareDifference {

    long sumSquareDifference (int n) {
        long sumNN = 0;
        long sumN = 0;
        
        for (int i = 1; i <= n; ++i) {
            sumNN += i * i;
            sumN += i;
        }
        return abs(sumNN - (sumN*sumN));
    }

    void test() {
        
        string path = "Tests/ProjectEuler+/SumSquareDifference/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");
        
        string t_temp, t_out;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string n_temp;
            getline(input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));
            long result = sumSquareDifference (n);
            
            getline(output, t_out);
            assert(result == stol(t_out), to_string(result) + " == " + t_out);
        }
    }
}

#endif /* SumSquareDifference_hpp */
