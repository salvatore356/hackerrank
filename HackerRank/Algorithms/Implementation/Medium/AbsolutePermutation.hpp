//
//  AbsolutePermutation.hpp
//  HackerRank
//
//  Created by Salvatore on 19/6/24.
//

#ifndef AbsolutePermutation_hpp
#define AbsolutePermutation_hpp

#include <stdio.h>

namespace AbsolutePermutation {

    vector<int> absolutePermutation(int n, int k) {
        vector<int> ans(n);
        unordered_map<int, int> uniq;
        
        int index;
        for (int i = 1; i <= n; ++i) {
            
            index = i - k;
            if (index <= 0 || uniq[index] != 0){
                index = i + k;
            }
            if (index > n) return {-1};
            
            ans[i - 1] = index;
            uniq[index] = i;
        }
        
        return ans;
    }

    void test() {
        string test_case = "00";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        string t_temp;
        getline(io.input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string first_multiple_input_temp;
            getline(io.input, first_multiple_input_temp);

            vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

            int n = stoi(first_multiple_input[0]);

            int k = stoi(first_multiple_input[1]);

            vector<int> result = absolutePermutation(n, k);
            string s_result = vector_to_string(result);
            
            getline(io.output, t_out);
            assert(s_result == t_out, s_result + " == " + t_out);
        }
    }
}

#endif /* AbsolutePermutation_hpp */
