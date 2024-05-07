//
//  RunningTimeOfAlgorithms.hpp
//  HackerRank
//
//  Created by Salvatore on 7/5/24.
//

#ifndef RunningTimeOfAlgorithms_hpp
#define RunningTimeOfAlgorithms_hpp

#include <stdio.h>

namespace RunningTimeOfAlgorithms {

    int runningTime(vector<int> arr) {
        int shifted = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            int index = i;
            for (int j = i ; j >= 0; --j) {
                if (arr[j] > arr[index]) {
                    ++shifted;
                    swap(arr[j], arr[index]);
                    index = j;
                }
            }
        }
        
        return shifted;
    }

    void test() {
        string path = "Tests/Algorithms/Sorting/RunningTimeOfAlgorithms/";
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

        int result = runningTime(arr);
        
        string out_temp;
        getline(output, out_temp);
        assert(result == stoi(out_temp), to_string(result) + " == " + out_temp);
    }
}

#endif /* RunningTimeOfAlgorithms_hpp */
