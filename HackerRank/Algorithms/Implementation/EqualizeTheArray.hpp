//
//  EqualizeTheArray.hpp
//  HackerRank
//
//  Created by Salvatore on 8/4/24.
//

#ifndef EqualizeTheArray_hpp
#define EqualizeTheArray_hpp

#include <stdio.h>
#include <unordered_map>

namespace EqualizeTheArray {

    int equalizeArray(vector<int> arr) {
        unordered_map<int, int> counter;
        int maxCount = 0;
        
        for(int i = 0; i < arr.size(); ++i) {
            int index = arr[i];
            ++counter[index] ;
            
            maxCount = max(maxCount,  counter[index] );
        }
        
        return arr.size() - maxCount;
    }

    void test() {
        
        std::ifstream input("Tests/Algorithms/Implementation/EqualizeTheArray/input00.txt");
        std::ifstream output("Tests/Algorithms/Implementation/EqualizeTheArray/output00.txt");

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

        int result = equalizeArray(arr);

        string expected_output;
        getline(output, expected_output);
        assert(result == stoi(expected_output), to_string(result) + " == " + expected_output);
        
        

    }
}

#endif /* EqualizeTheArray_hpp */
