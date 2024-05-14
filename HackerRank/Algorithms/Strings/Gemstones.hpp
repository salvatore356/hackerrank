//
//  Gemstones.hpp
//  HackerRank
//
//  Created by Salvatore on 14/5/24.
//

#ifndef Gemstones_hpp
#define Gemstones_hpp

#include <stdio.h>

namespace Gemstones {

    int gemstones(vector<string> arr) {
        unordered_map<char, set<int>> occurences;
        
        for (int i = 0; i < arr.size(); ++i) {
            for (int k = 0; k < arr[i].size(); ++k) {
                occurences[arr[i][k]].insert(i);
            }
        }
        
        int ans = 0;
        for (auto &keys : occurences)
            ans += keys.second.size() == arr.size();
        return ans;
    }

    void test() {
        string path = "Tests/Algorithms/Strings/Gemstones/";
        std::ifstream input(path  +  "input27.txt");
        std::ifstream output(path + "output27.txt");

        string n_temp;
        getline(input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> arr(n);

        for (int i = 0; i < n; i++) {
            string arr_item;
            getline(input, arr_item);

            arr[i] = arr_item;
        }

        int result = gemstones(arr);

        string t_out;
        getline(output, t_out);
        
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);
    }
}

#endif /* Gemstones_hpp */
