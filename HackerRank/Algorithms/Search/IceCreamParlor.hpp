//
//  IceCreamParlor.hpp
//  HackerRank
//
//  Created by Salvatore on 21/5/24.
//

#ifndef IceCreamParlor_hpp
#define IceCreamParlor_hpp

#include <stdio.h>

namespace IceCreamParlor {

    vector<int> icecreamParlor(int m, vector<int> arr) {
        vector<int> ans(2);
        unordered_map<int, int> indexes;
        
        for (int i = 0; i < arr.size(); ++i) {
            int temp = m - arr[i];
            
            if (indexes[temp] != 0) {
                return {indexes[temp], i +1};
            }
            
            indexes[arr[i]] = i + 1;
        }
        
        
        return ans;
    }

    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/Search/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string t_temp, t_out;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string m_temp;
            getline(input, m_temp);

            int m = stoi(ltrim(rtrim(m_temp)));

            string n_temp;
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

            vector<int> result = icecreamParlor(m, arr);
            string s_result = vector_to_string(result);
            getline(output, t_out);
            assert(s_result == t_out, s_result + " == " + t_out);
        }

    }
}

#endif /* IceCreamParlor_hpp */
