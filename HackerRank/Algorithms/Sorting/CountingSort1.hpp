//
//  CountingSort1.hpp
//  HackerRank
//
//  Created by Salvatore on 13/5/24.
//

#ifndef CountingSort1_hpp
#define CountingSort1_hpp

#include <stdio.h>

namespace CountingSort1 {

    vector<int> countingSort(vector<int> arr) {
        vector<int> counted(100);
        
        for (int i = 0; i < arr.size(); ++i)
            ++counted[arr[i]];
        
        return counted;
    }

    void test() {
        string path = "Tests/Algorithms/Sorting/CountingSort1/";
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

        vector<int> result = countingSort(arr);
        string s_result = vector_to_string(result);
        
        string t_out;
        getline(output, t_out);
        
        assert(s_result == t_out, s_result + " == " + t_out);
    }
}

#endif /* CountingSort1_hpp */
