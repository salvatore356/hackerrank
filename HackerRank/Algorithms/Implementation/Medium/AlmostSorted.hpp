//
//  AlmostSorted.hpp
//  HackerRank
//
//  Created by Salvatore on 15/7/24.
//

#ifndef AlmostSorted_hpp
#define AlmostSorted_hpp

#include <stdio.h>

namespace AlmostSorted {

    string almostSorted(vector<int> arr) {
        auto sorted = arr;
        sort(sorted.begin(), sorted.end());
        vector<int> unordered;
        
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == sorted[i]) continue;
            unordered.push_back(i + 1);
        }
        
        if (unordered.empty()) return "yes";
        
        int left = unordered.front() - 1;
        int right = unordered.back() - 1;
        
        // Attempt to swap
        std::swap(arr[left], arr[right]);
        if (arr == sorted) {
            return "yes swap " + to_string(left + 1) + " " +to_string(right + 1);
        }
        
        // Restore the original array
        std::swap(arr[left], arr[right]);
        
        // Attempt to reverse
        std::reverse(arr.begin() + left, arr.begin() + right + 1);
        if (arr == sorted) {
            return "yes reverse " + to_string(left + 1) + " " +to_string(right + 1);
        }
        
        // If neither swap nor reverse works
        return "no";
    }

    void test() {
        
        string test_case = "00";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;
        
        string n_temp;
        getline(io.input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(io.input, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        string result = almostSorted(arr);
        getline(io.output, t_out);
        
        string temp0 = t_out;
        getline(io.output, t_out);
        string temp1 = t_out;
        
        string expected = temp0 +" " + temp1;
        assert(result == expected, result + " == " + expected);
        
    }
}

#endif /* AlmostSorted_hpp */
