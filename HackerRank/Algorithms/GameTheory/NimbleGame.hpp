//
//  NimbleGame.hpp
//  HackerRank
//
//  Created by Salvatore on 4/6/24.
//

#ifndef NimbleGame_hpp
#define NimbleGame_hpp

#include <stdio.h>

namespace NimbleGame {

    string nimbleGame(vector<int> s) {
        int total = 0;
        
        for(int i=0; i < s.size(); ++i){
            if(s[i] % 2)
                total ^= i;
        }
        return total ? "First": "Second";
    }

    void test() {
        string test_case = "03";
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

            string result = nimbleGame(s);

            getline(output, t_out);
            assert(result == t_out, result + " == " + t_out);
        }
    }
}

#endif /* NimbleGame_hpp */
