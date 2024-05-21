//
//  MissingNumbers.hpp
//  HackerRank
//
//  Created by Salvatore on 21/5/24.
//

#ifndef MissingNumbers_hpp
#define MissingNumbers_hpp

#include <stdio.h>

namespace MissingNumbers {

    vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
        unordered_map<int, int> count;
        
        for (auto &n : arr) ++count[n];
        for (auto &n : brr) --count[n];
        
        vector<int> ans;
        for (auto &n : count)
            if (n.second !=0 ) ans.push_back(n.first);
        
        sort(ans.begin(), ans.end());
        return ans;
    }

    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/Search/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string n_temp, t_out;
        getline(input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(input, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        string m_temp;
        getline(input, m_temp);

        int m = stoi(ltrim(rtrim(m_temp)));

        string brr_temp_temp;
        getline(input, brr_temp_temp);

        vector<string> brr_temp = split(rtrim(brr_temp_temp));

        vector<int> brr(m);

        for (int i = 0; i < m; i++) {
            int brr_item = stoi(brr_temp[i]);

            brr[i] = brr_item;
        }

        vector<int> result = missingNumbers(arr, brr);
        string s_result = vector_to_string(result);
        getline(output, t_out);
        assert(s_result == t_out, s_result + " == " + t_out);
    }
}

#endif /* MissingNumbers_hpp */
