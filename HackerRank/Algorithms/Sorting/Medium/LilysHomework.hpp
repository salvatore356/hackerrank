//
//  LilysHomework.hpp
//  HackerRank
//
//  Created by Salvatore on 17/7/24.
//

#ifndef LilysHomework_hpp
#define LilysHomework_hpp

#include <stdio.h>

namespace LilysHomework {

    int count(vector<int> arr, bool asc) {
        int count = 0;
        
        vector<int> sorted(arr);
        
        if (asc) sort(sorted.begin(), sorted.end());
        else sort(sorted.begin(), sorted.end(), greater<int>());
        
        for (int i = 0; i < arr.size(); ++i) {
            if (sorted[i] == arr[i]) continue;
            
            auto index = std::find(arr.begin() + i, arr.end(), sorted[i]);
            swap(arr[i], arr[index - arr.begin()]);
            ++count;
            
        }
        
        return count;
    }

    int lilysHomework(vector<int> arr) {
        return min(count(arr, true), count(arr, false));
    }

    void test() {
        string test_case = "01";
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
        printf("count: %d\n", n);
        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = lilysHomework(arr);

        getline(io.output, t_out);
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);

    }
}

#endif /* LilysHomework_hpp */
