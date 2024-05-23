//
//  MaximumPerimeterTriangle.hpp
//  HackerRank
//
//  Created by Salvatore on 23/5/24.
//

#ifndef MaximumPerimeterTriangle_hpp
#define MaximumPerimeterTriangle_hpp

#include <stdio.h>

namespace MaximumPerimeterTriangle {

    vector<int> maximumPerimeterTriangle(vector<int> sticks) {
        sort(sticks.begin(), sticks.end());
        
        vector<int> ans = {-1};
        int maxValue = INT_MIN;
        
        for (int a = 0; a < sticks.size() - 2; ++a) {
            for (int b = a + 1; b < sticks.size() - 1; ++b) {
                
                for (int c = b + 1; c < sticks.size(); ++c) {
                    if (
                        sticks[a] + sticks[b] > sticks[c] &&
                        sticks[b] + sticks[c] > sticks[a] &&
                        sticks[a] + sticks[c] > sticks[b] &&
                        sticks[a] + sticks[b] + sticks[c] > maxValue
                    ) {
                        maxValue = sticks[a] + sticks[b] + sticks[c];
                        ans = {sticks[a], sticks[b], sticks[c]};
                    }
                }
            }
        }
        
        return ans;
    }

    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/Greedy/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string n_temp, t_out;
        
        getline(input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string sticks_temp_temp;
        getline(input, sticks_temp_temp);

        vector<string> sticks_temp = split(rtrim(sticks_temp_temp));

        vector<int> sticks(n);

        for (int i = 0; i < n; i++) {
            int sticks_item = stoi(sticks_temp[i]);

            sticks[i] = sticks_item;
        }

        vector<int> result = maximumPerimeterTriangle(sticks);

        string s_result = vector_to_string(result);
        
        getline(output, t_out);
        assert(s_result == t_out, s_result + " == " + t_out);
    }
}

#endif /* MaximumPerimeterTriangle_hpp */
