//
//  InsertionSortPart2.hpp
//  HackerRank
//
//  Created by Salvatore on 3/5/24.
//

#ifndef InsertionSortPart2_hpp
#define InsertionSortPart2_hpp

#include <stdio.h>

namespace InsertionSortPart2 {

    string createString(vector<int> &arr) {
        string ans;
        for(int i = 0; i < arr.size(); ++i) {
            ans += to_string(arr[i]);
            if (i != arr.size() - 1)
                ans += " " ;
        }
        return ans;
    }

    vector<string> insertionSort2(int n, vector<int> arr) {
        vector<string> ans;
        for (int i = 1; i < arr.size(); ++i) {
            int index = i;
            for(int j = i; j >= 0; --j) {
                if(arr[j] > arr[index]) {
                    swap(arr[index], arr[j]);
                    index = j;
                }
            }
            string s = createString(arr);
            ans.push_back(s);
        }
        return ans;
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/InsertionSortPart2/";
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

        auto result = insertionSort2(n, arr);
        
        string out;
        for(int i = 0; i < result.size(); ++i) {
            getline(output, out);
            assert(result[i] == out, result[i] + " == " + out);
        }
        
    }
}

#endif /* InsertionSortPart2_hpp */
