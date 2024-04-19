//
//  BeautifulTriplets.hpp
//  HackerRank
//
//  Created by Salvatore on 19/4/24.
//

#ifndef BeautifulTriplets_hpp
#define BeautifulTriplets_hpp

#include <stdio.h>

namespace BeautifulTriplets {

    int beautifulTriplets(int d, vector<int> arr) {
        if(arr.size() < 3) return 0;
        int beautiful = 0;
        
        for(int i = 0; i < arr.size() - 2; ++i){
            for(int j = i + 1; j < arr.size() - 1; ++j){
                if(arr[j] - arr[i] != d) continue;
                for(int k = j + 1; k < arr.size(); ++k)
                    beautiful += arr[k] - arr[j] == d;
            }
        }
        return beautiful;
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/BeautifulTriplets/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string first_multiple_input_temp;
        getline(input, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int d = stoi(first_multiple_input[1]);

        string arr_temp_temp;
        getline(input, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = beautifulTriplets(d, arr);

        string out1;
        getline(output, out1);
        
        assert(result == stoi(out1), to_string(result) + " == " + out1);

    }
}

#endif /* BeautifulTriplets_hpp */
