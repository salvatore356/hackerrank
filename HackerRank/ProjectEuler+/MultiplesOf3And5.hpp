//
//  MultiplesOf3And5.hpp
//  HackerRank
//
//  Created by Salvatore on 1/5/24.
//

#ifndef MultiplesOf3And5_hpp
#define MultiplesOf3And5_hpp

#include <stdio.h>

namespace MultiplesOf3And5 {

    long sumToN (int val, int n) {
        long C = n / val;
        long A = val * C;
        long B =  C + 1;
        return ( A * B ) / 2;
    }

    long findMultiples(int n){
        return sumToN(3, n - 1) + sumToN(5, n - 1) - sumToN(15, n - 1);
    }

    void test() {
        string path = "Tests/ProjectEuler+/MultiplesOf3And5/";
        std::ifstream input(path  +  "input05.txt");
        std::ifstream output(path + "output05.txt");
        
        string t_temp;
        string out;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string n_temp;
            getline(input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));
            long result = findMultiples(n);
            
            getline(output, out);
            assert(result == stol(out), to_string(result) + " == " + out);
        }
    }
}

#endif /* MultiplesOf3And5_hpp */
