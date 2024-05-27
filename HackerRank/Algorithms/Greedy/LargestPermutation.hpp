//
//  LargestPermutation.hpp
//  HackerRank
//
//  Created by Salvatore on 27/5/24.
//

#ifndef LargestPermutation_hpp
#define LargestPermutation_hpp

#include <stdio.h>

namespace LargestPermutation {

    vector<int> largestPermutation(int k, vector<int> arr) {
        unordered_map<int, int> pos;
        
        for (int i = 0; i < arr.size(); ++i)
            pos[arr[i]] = i;
        
        for (int i = 0; i < arr.size() && k > 0; ++i) {
            int target = arr.size() - i;
            
            if(arr[i] == target) continue;
            
            swap(arr[i], arr[pos[target]]);
            
            pos[arr[pos[target]]] = pos[target];
            pos[arr[i]] = i;
            --k;
        }
        
        return arr;
    }

    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/Greedy/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string first_multiple_input_temp, t_out;
        getline(input, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        string arr_temp_temp;
        getline(input, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        vector<int> result = largestPermutation(k, arr);
        string s_result = vector_to_string(result);
        
        getline(output, t_out);
        assert(s_result == t_out, s_result + " == " + t_out);
    }
}

#endif /* LargestPermutation_hpp */
