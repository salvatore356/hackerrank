//
//  LargestPalindromeProduct.hpp
//  HackerRank
//
//  Created by Salvatore on 14/5/24.
//

#ifndef LargestPalindromeProduct_hpp
#define LargestPalindromeProduct_hpp

#include <stdio.h>

namespace  LargestPalindromeProduct {

    bool isPalindrome (long n) {
        string str = to_string(n);
      
        for (int i = 0; i < str.size() / 2; ++i)
            if(str[i] != str[str.size() - (i + 1)]) return false;
      
        return true;
    }

    bool isValid(long n) {
        
        for (int i = 100; i < 1000; ++i)
            for (int j = 100; j < 1000; ++j)
                if ( i * j == n) return false;
            
            
        return true;
        
    }

    long largestPalindromeProduct (int n) {
        
        for (int i = n - 1; i >= 1; --i) {
            if (isPalindrome(i) && !isValid(i)) return i;
        }
        
        return -1;
    }

    void test()
    {
        
        string path = "Tests/ProjectEuler+/LargestPalindromeProduct/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");
        
        string t_temp;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string n_temp;
            getline(input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));
            
            long result = largestPalindromeProduct (n);
            
            string t_out;
            getline(output, t_out);
            assert(result == stol(t_out), to_string(result) + " == " + t_out);
        }

    }
}

#endif /* LargestPalindromeProduct_hpp */
