//
//  SmallestMultiple.hpp
//  HackerRank
//
//  Created by Salvatore on 15/5/24.
//

#ifndef SmallestMultiple_hpp
#define SmallestMultiple_hpp

#include <stdio.h>

namespace SmallestMultiple {

    long smallestMultiple (int n) {
        
        vector <int> mult(n);
        for (int i = 0; i < n; ++i)
            mult[i] = i + 1;
        
        long ans = 1;
        for (int i = 1; i < mult.size(); ++i) {
            for (int j = i + 1; j < mult.size(); ++j) {
                if (mult[j] % mult[i] == 0)
                    mult[j] /= mult[i];
            }
            ans *= mult[i];
        }
        
        
        return ans;
    }

    void test() {
        string path = "Tests/ProjectEuler+/SmallestMultiple/";
        std::ifstream input(path  +  "input04.txt");
        std::ifstream output(path + "output04.txt");
        
        string t_temp, t_out;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string n_temp;
            getline(input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));
            long result = smallestMultiple (n);
            
            getline(output, t_out);
            assert(result == stol(t_out), to_string(result) + " == " + t_out);
        }
    }
}

#endif /* SmallestMultiple_hpp */
