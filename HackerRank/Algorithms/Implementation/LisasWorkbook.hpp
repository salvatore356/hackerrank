//
//  LisasWorkbook.hpp
//  HackerRank
//
//  Created by Salvatore on 24/4/24.
//

#ifndef LisasWorkbook_hpp
#define LisasWorkbook_hpp

#include <stdio.h>

namespace LisasWorkbook {

    int workbook(int n, int k, vector<int> arr) {
        int special = 0, pages = 0, current;
        
        for(int i = 0; i < arr.size(); ++i) {
            current = 0;
            while(current < arr[i]){
                int temp = current;
                current = min(current + k, arr[i]);
                special += pages >= temp && pages < current;
                ++pages;
            }
        }
        return special;
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/LisasWorkbook/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string first_multiple_input_temp;
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

        int result = workbook(n, k, arr);

        string out;
        getline(output, out);
        assert(result == stoi(out), to_string(result) + " == " + out);
    }
}

#endif /* LisasWorkbook_hpp */
