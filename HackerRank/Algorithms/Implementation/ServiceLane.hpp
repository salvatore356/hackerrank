//
//  ServiceLane.hpp
//  HackerRank
//
//  Created by Salvatore on 23/4/24.
//

#ifndef ServiceLane_hpp
#define ServiceLane_hpp

#include <stdio.h>

namespace ServiceLane {

    vector<int> serviceLane(int n, vector<int> &width, vector<vector<int>> &cases) {
        vector<int> ans;
        
        for(int i = 0; i < cases.size(); ++i){
            ans.emplace_back(width[cases[i][0]]);
            for(int j = cases[i][0] + 1; j <= cases[i][1]; ++j){
                ans[i] = min(ans[i], width[j]);
            }
        }
        
        return ans;
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/ServiceLane/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string first_multiple_input_temp;
        getline(input, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int t = stoi(first_multiple_input[1]);

        string width_temp_temp;
        getline(input, width_temp_temp);

        vector<string> width_temp = split(rtrim(width_temp_temp));

        vector<int> width(n);

        for (int i = 0; i < n; i++) {
            int width_item = stoi(width_temp[i]);

            width[i] = width_item;
        }

        vector<vector<int>> cases(t);

        for (int i = 0; i < t; i++) {
            cases[i].resize(2);

            string cases_row_temp_temp;
            getline(input, cases_row_temp_temp);

            vector<string> cases_row_temp = split(rtrim(cases_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cases_row_item = stoi(cases_row_temp[j]);

                cases[i][j] = cases_row_item;
            }
        }

        vector<int> result = serviceLane(n, width, cases);

        string out;
        
        for(int i = 0; i < result[i]; ++i) {
            getline(output, out);
            
            assert(result[i] == stoi(out), to_string(result[i]) + " == " + out);
        }
        
    }
}


#endif /* ServiceLane_hpp */
