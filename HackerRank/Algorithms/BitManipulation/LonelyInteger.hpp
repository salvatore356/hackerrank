//
//  LonelyInteger.hpp
//  HackerRank
//
//  Created by Salvatore on 29/5/24.
//

#ifndef LonelyInteger_hpp
#define LonelyInteger_hpp

#include <stdio.h>

namespace LonelyInteger {

    int lonelyinteger(vector<int> a) {
        int unique = 0;
        for (auto &n : a)
            unique ^= n;
        return unique;
    }

    void test() {
        string test_case = "01";
        string path = "Tests/Algorithms/BitManipulation/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string t_out;

        string n_temp;
        getline(input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string a_temp_temp;
        getline(input, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        int result = lonelyinteger(a);

        getline(output, t_out);
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);
    }
}

#endif /* LonelyInteger_hpp */
