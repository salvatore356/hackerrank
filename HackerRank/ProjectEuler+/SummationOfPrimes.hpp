//
//  SummationOfPrimes.hpp
//  HackerRank
//
//  Created by Salvatore on 17/5/24.
//

#ifndef SummationOfPrimes_hpp
#define SummationOfPrimes_hpp

#include <stdio.h>

namespace SummationOfPrimes {

    vector<long> createPrimes() {
        vector<long> ans(1000001);

        for (int n = 2; n < ans.size(); ++n) {
            bool isPrime = true;
            for (int j = 2; j * j <= n; ++j) {
                if (n % j == 0)  {
                    isPrime = false;
                    break;
                }
            }
            ans[n] = ans[n-1] + n * isPrime;
            
        }
        return ans;
    }

    long summationOfPrimes (int n, vector<long> &primes) {
        return primes[n];
    }


    void test() {
        
        string test_case = "00";
        string path = "Tests/ProjectEuler+/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");
        
        string t_temp, t_out;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));
        vector<long> primes = createPrimes() ;
        
        for (int t_itr = 0; t_itr < t; t_itr++) {
            string n_temp;
            getline(input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));
            long result = summationOfPrimes(n, primes);
            
            getline(output, t_out);
            assert(result == stol(t_out), to_string(result) + " == " + t_out);
        }
    }
}

#endif /* SummationOfPrimes_hpp */
