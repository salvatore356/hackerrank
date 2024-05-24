//
//  SherlockAndTheBeast.hpp
//  HackerRank
//
//  Created by Salvatore on 24/5/24.
//

#ifndef SherlockAndTheBeast_hpp
#define SherlockAndTheBeast_hpp

#include <stdio.h>

namespace SherlockAndTheBeast {

    string init(int n) {
        string ans = "";
        for(int i = 0; i < n; ++i) ans.append("5");
        return ans;
    }

    string decentNumber(int n) {
        string ans = init(n);
        int threes = 0;
        int lastIndex = n;
       
        while (lastIndex > 0 && (lastIndex % 3 != 0 || threes % 5 != 0)) {
            ans[--lastIndex] = '3';
            ++threes;
        }
        return lastIndex % 3 == 0 && threes % 5 == 0 ? ans : "-1";
    }

    void test() {
        string test_case = "14";
        string path = "Tests/Algorithms/Greedy/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string t_temp, t_out;
        
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string n_temp;
            getline(input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));

            string result = decentNumber(n);
            getline(output, t_out);
            assert(result == t_out, result + " == " + t_out);
        }
    }
}

#endif /* SherlockAndTheBeast_hpp */
