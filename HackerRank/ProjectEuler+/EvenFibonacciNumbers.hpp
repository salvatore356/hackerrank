//
//  EvenFibonacciNumbers.hpp
//  HackerRank
//
//  Created by Salvatore on 2/5/24.
//

#ifndef EvenFibonacciNumbers_hpp
#define EvenFibonacciNumbers_hpp

#include <stdio.h>

namespace EvenFibonacciNumbers {

    long fibonacciLimit (long n) {
        long sum  = 0;
        long currentFib = 1, lastFib = 1;
        long temp;

        while(currentFib < n) {
            if(currentFib % 2 == 0) sum += currentFib;
            temp = currentFib;
            currentFib += lastFib;
            lastFib = temp;
            
        }
        return sum;
    }

    void test() {
        
        string path = "Tests/ProjectEuler+/EvenFibonacciNumbers/";
        std::ifstream input(path  +  "input04.txt");
        std::ifstream output(path + "output04.txt");
        
        string t_temp;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        string out;
        for (int t_itr = 0; t_itr < t; t_itr++) {
            string n_temp;
            getline(input, n_temp);

            long n = stol(ltrim(rtrim(n_temp)));
            long result = fibonacciLimit (n);
            
            getline(output, out);
            assert(result == stol(out), to_string(result) + " == " + out);
        }

        
        
        
    }
}

#endif /* EvenFibonacciNumbers_hpp */
