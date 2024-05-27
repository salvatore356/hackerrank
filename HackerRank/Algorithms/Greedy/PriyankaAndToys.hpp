//
//  PriyankaAndToys.hpp
//  HackerRank
//
//  Created by Salvatore on 27/5/24.
//

#ifndef PriyankaAndToys_hpp
#define PriyankaAndToys_hpp

#include <stdio.h>

namespace PriyankaAndToys {

    int toys(vector<int> w) {
        sort(w.begin(), w.end());
        
        int containers = 1;
        int startIndex = 0;
        
        for (int i = 1; i < w.size(); ++i) {
            if (!(w[i] <= w[startIndex] + 4)) {
                startIndex = i;
                ++containers;
            }
        }
        
        return containers;
    }

    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/Greedy/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string n_temp, t_out;
        getline(input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string w_temp_temp;
        getline(input, w_temp_temp);

        vector<string> w_temp = split(rtrim(w_temp_temp));

        vector<int> w(n);

        for (int i = 0; i < n; i++) {
            int w_item = stoi(w_temp[i]);

            w[i] = w_item;
        }

        int result = toys(w);
        
        getline(output, t_out);
        assert(result == stol(t_out), to_string(result) + " == " + t_out);
        
    }
}

#endif /* PriyankaAndToys_hpp */
