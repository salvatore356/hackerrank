//
//  InsertionSortPart1.hpp
//  HackerRank
//
//  Created by Salvatore on 2/5/24.
//

#ifndef InsertionSortPart1_hpp
#define InsertionSortPart1_hpp

#include <stdio.h>

namespace InsertionSortPart1 {

    string arrayToString(vector<int> &arr) {
        string value = "";
        for(int i = 0; i < arr.size(); ++i)
            value += to_string(arr[i]) + " ";
        return trim(value);
    }

    vector<string> insertionSort1(int n, vector<int> arr) {
        vector<string> ans;
        
        int key = arr.back();
        
        for(int i = (int)arr.size() - 1; i >= 0; --i) {
            if(key < arr[i - 1])
                arr[i] = arr[i-1];
            else{
                arr[i] = key;
                ans.push_back(arrayToString(arr));
                break;
            }
            ans.push_back(arrayToString(arr));
        }
        return ans;
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/InsertionSortPart1/";
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

        auto result = insertionSort1(n, arr);

        string out;
        
        for(int i = 0; i < result.size(); ++i) {
            getline(output, out);
            assert(result[i] == out, result[i] + " == " + out);
        }
        
    }
}

#endif /* InsertionSortPart1_hpp */
