//
//  NonDivisibleSubset.hpp
//  HackerRank
//
//  Created by Salvatore on 7/6/24.
//

#ifndef NonDivisibleSubset_hpp
#define NonDivisibleSubset_hpp

#include <stdio.h>

namespace NonDivisibleSubset {

    int nonDivisibleSubset(int k, vector<int> s) {
        vector<int> reminders(k);
        
        for (int j = 0; j < s.size(); ++j){
            ++reminders[s[j] % k];
        }
            
        int maxSubset = reminders.front() != 0;
        
        for(int i = 1; i <= floor(k/2.0); ++i) {
            if (i != k - i)
                maxSubset += max(reminders[i], reminders[k - i]);
            else ++maxSubset;
        }
        
        return maxSubset;
        
    }

    void test() {
        string test_case = "00";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        string first_multiple_input_temp;
        getline(io.input, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        string s_temp_temp;
        getline(io.input, s_temp_temp);

        vector<string> s_temp = split(rtrim(s_temp_temp));

        vector<int> s(n);

        for (int i = 0; i < n; i++) {
            int s_item = stoi(s_temp[i]);

            s[i] = s_item;
        }

        int result = nonDivisibleSubset(k, s);
        
        getline(io.output, t_out);
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);
    }
}

#endif /* NonDivisibleSubset_hpp */
