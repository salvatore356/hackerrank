//
//  FindTheMedian.hpp
//  HackerRank
//
//  Created by Salvatore on 16/5/24.
//

#ifndef FindTheMedian_hpp
#define FindTheMedian_hpp

#include <stdio.h>

namespace FindTheMedian {

    int findMedian(vector<int> arr) {
        sort(arr.begin(), arr.end());
        
        return arr[arr.size() / 2];
    }

    void test() {
        
        string path = "Tests/Algorithms/Sorting/FindTheMedian/";
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

        int result = findMedian(arr);
        string t_out;
        getline(output, t_out);
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);
    }
}

#endif /* FindTheMedian_hpp */
