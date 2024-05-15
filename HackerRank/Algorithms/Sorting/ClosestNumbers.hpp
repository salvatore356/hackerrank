//
//  ClosestNumbers.hpp
//  HackerRank
//
//  Created by Salvatore on 15/5/24.
//

#ifndef ClosestNumbers_hpp
#define ClosestNumbers_hpp

#include <stdio.h>

namespace ClosestNumbers {

    vector<int> closestNumbers(vector<int> arr) {
        unordered_map<int, vector<int>> diffs;
        int minDiff = INT32_MAX;
        
        sort(arr.begin(), arr.end());
        
        for (int i = 1; i < arr.size(); ++i) {
            int temp = arr[i] - arr[i - 1];
            
            minDiff = min(minDiff, temp);
            if (minDiff == temp) {
                diffs[minDiff].push_back(arr[i - 1]);
                diffs[minDiff].push_back(arr[i]);
            }
        }
        
        return diffs[minDiff];
    }

    void test() {
        string path = "Tests/Algorithms/Sorting/ClosestNumbers/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

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

        vector<int> result = closestNumbers(arr);

        string s_result = vector_to_string(result);
        string t_out;
        getline(output, t_out);
        assert(s_result == t_out, s_result + " == " + t_out);
    }
}

#endif /* ClosestNumbers_hpp */
