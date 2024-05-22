//
//  SherlockAndArray.hpp
//  HackerRank
//
//  Created by Salvatore on 22/5/24.
//

#ifndef SherlockAndArray_hpp
#define SherlockAndArray_hpp

#include <stdio.h>

namespace SherlockAndArray {

    string balancedSums(vector<int> arr) {
        
        if (arr.size() < 2) return "YES";
        
        int left = 0, right = 0;
        
        for (int i = 0; i < arr.size(); ++i)
            right += arr[i];
        
        for (int i = 0; i < arr.size() - 1; ++i) {
            
            if (left == (right - arr[i]))
                return "YES";
            
            right -= arr[i];
            left += arr[i];
        }
        
        return "NO";
    }

    void test() {
        string test_case = "06";
        string path = "Tests/Algorithms/Search/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string T_temp, t_out;
        getline(input, T_temp);

        int T = stoi(ltrim(rtrim(T_temp)));

        for (int T_itr = 0; T_itr < T; T_itr++) {
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

            string result = balancedSums(arr);
            getline(output, t_out);
            assert(result == t_out, result + " == " + t_out);
        }
    }
}

#endif /* SherlockAndArray_hpp */
