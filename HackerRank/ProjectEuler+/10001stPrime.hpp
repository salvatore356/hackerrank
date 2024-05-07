//
//  10001stPrime.hpp
//  HackerRank
//
//  Created by Salvatore on 7/5/24.
//

#ifndef _0001stPrime_hpp
#define _0001stPrime_hpp

#include <stdio.h>

namespace _10001stPrime {

    void addPrime (int n, vector<long> &primes) {
        //printf("%d is prime? ", n);
        
        for (int i = 0; i < primes.size(); ++i) {
            if (n % primes[i] == 0) return;
            if (primes[i] * primes[i] > n) break;
        }
        
        primes.push_back(n);
        return;
    }

    long nPrime(int n, vector<long> &primes) {
        
        if( n <= primes.size()) return primes[n - 1];
        
        int current = primes.back() + 1;
        while( primes.size() < n ) {
            addPrime (current, primes);
            ++current;
        }
        return primes[n - 1];
    }


    void test() {
        
        string path = "Tests/ProjectEuler+/10001stPrime/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");
        
        string t_temp;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));
        
        vector<long> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string n_temp;
            getline(input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));
            long result = nPrime(n, primes);
            
            string t_out;
            getline(output, t_out);
            assert(result == stol(t_out), to_string(result) + " == " + t_out);
        }
    }
}

#endif /* _0001stPrime_hpp */
