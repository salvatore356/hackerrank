//
//  MisèreNim.hpp
//  HackerRank
//
//  Created by Salvatore on 3/6/24.
//

#ifndef Mise_reNim_hpp
#define Mise_reNim_hpp

#include <stdio.h>

namespace MisèreNim {

    string misereNim(vector<int> s) {
        int total = 0;
        int bit = 0;
        for (int &n : s) {
            bit ^= n;
            total += n;
        }
            
        if (total == s.size())
            return s.size() % 2 == 0 ? "First" : "Second";
        return bit ? "First" : "Second";
    }

    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/GameTheory/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string t_out;

        string t_temp;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string n_temp;
            getline(input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));

            string s_temp_temp;
            getline(input, s_temp_temp);

            vector<string> s_temp = split(rtrim(s_temp_temp));

            vector<int> s(n);

            for (int i = 0; i < n; i++) {
                int s_item = stoi(s_temp[i]);

                s[i] = s_item;
            }

            string result = misereNim(s);

            getline(output, t_out);
            assert(result == t_out, result + " == " + t_out);
        }
    }
}

#endif /* Mise_reNim_hpp */
