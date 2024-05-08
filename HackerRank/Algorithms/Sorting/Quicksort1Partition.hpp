//
//  Quicksort1Partition.hpp
//  HackerRank
//
//  Created by Salvatore on 8/5/24.
//

#ifndef Quicksort1Partition_hpp
#define Quicksort1Partition_hpp

#include <stdio.h>

namespace Quicksort1Partition {

    vector<int> quickSort(vector<int> arr) {
        int index = 0;
        
        for (int i = 1; i < arr.size(); ++i) {
            
            if (arr[i] < arr[index]) {
                int temp = arr[i];
                arr.erase(arr.begin() + i);
                arr.insert(arr.begin() + index, temp);
                ++index;
            }
        }
        
        return arr;
    }

    void test() {
        string path = "Tests/Algorithms/Sorting/Quicksort1Partition/";
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

        vector<int> result = quickSort(arr);
        string t_out;
        for (size_t i = 0; i < result.size(); i++) {
            getline(output, t_out);
            assert(result[i] == stoi(t_out), to_string(result[i]) + " == " + t_out);
        }
    }
}

#endif /* Quicksort1Partition_hpp */
