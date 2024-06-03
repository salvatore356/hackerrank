//
//  IntroductionToNimGame.hpp
//  HackerRank
//
//  Created by Salvatore on 3/6/24.
//

#ifndef IntroductionToNimGame_hpp
#define IntroductionToNimGame_hpp

#include <stdio.h>

namespace IntroductionToNimGame {

    string nimGame(vector<int> pile) {
        int total = 0;
        
        for (auto &n : pile) total ^= n;
        
        return total == 0 ? "Second" : "First";
    }

    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/GameTheory/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string t_out;

        string g_temp;
        getline(input, g_temp);

        int g = stoi(ltrim(rtrim(g_temp)));

        for (int g_itr = 0; g_itr < g; g_itr++) {
            string n_temp;
            getline(input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));

            string pile_temp_temp;
            getline(input, pile_temp_temp);

            vector<string> pile_temp = split(rtrim(pile_temp_temp));

            vector<int> pile(n);

            for (int i = 0; i < n; i++) {
                int pile_item = stoi(pile_temp[i]);

                pile[i] = pile_item;
            }

            string result = nimGame(pile);

            getline(output, t_out);
            assert(result == t_out, result + " == " + t_out);
        }
    }
}

#endif /* IntroductionToNimGame_hpp */
