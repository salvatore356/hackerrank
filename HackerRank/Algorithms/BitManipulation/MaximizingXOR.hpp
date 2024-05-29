//
//  MaximizingXOR.hpp
//  HackerRank
//
//  Created by Salvatore on 29/5/24.
//

#ifndef MaximizingXOR_hpp
#define MaximizingXOR_hpp

#include <stdio.h>

namespace MaximizingXOR {

    int maximizingXor(int l, int r) {
        int ans = INT_MIN;
        for (int i = l; i <= r; ++i) {
            for (int j = l; j <= r; ++j) {
                ans = max(ans, i^j);
            }
        }
        return ans;
    }

    void test() {
        string test_case = "11";
        string path = "Tests/Algorithms/BitManipulation/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string t_out;

        string l_temp;
        getline(input, l_temp);

        int l = stoi(ltrim(rtrim(l_temp)));

        string r_temp;
        getline(input, r_temp);

        int r = stoi(ltrim(rtrim(r_temp)));

        int result = maximizingXor(l, r);
        
        getline(output, t_out);
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);
    }
}

#endif /* MaximizingXOR_hpp */
