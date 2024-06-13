//
//  LargestProductInASeries.hpp
//  HackerRank
//
//  Created by Salvatore on 8/5/24.
//

#ifndef LargestProductInASeries_hpp
#define LargestProductInASeries_hpp

#include <stdio.h>

namespace LargestProductInASeries {

    long largestProductInASerie (string n, int k) {
        long ans = 0;
        vector<int> nums(n.size());
        
        for (int i = 0; i < n.size(); ++i) nums[i] = n[i] - '0';
        
        for (int i = 0; i < n.size() - k; ++i) {
            long temp = 1;
            for(int j = i; j < i + k; ++j)
                temp *= nums[j];
            
            ans = max(ans, temp);
        }
        
        return ans;
    }

    void test() {
        string path = "Tests/ProjectEuler+/LargestProductInASeries/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");
        
        string t_temp;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string first_multiple_input_temp;
            getline(input, first_multiple_input_temp);

            vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

            //int n = stoi(first_multiple_input[0]);

            int k = stoi(first_multiple_input[1]);

            string num;
            getline(input, num);
            
            long result = largestProductInASerie (num, k);
            
            string t_out;
            getline(output, t_out);
            assert(result == stol(t_out), to_string(result) + " == " + t_out);
        }
        
        
    }
}

#endif /* LargestProductInASeries_hpp */
