//
//  FormingAMagicSquare.hpp
//  HackerRank
//
//  Created by Salvatore on 6/6/24.
//

#ifndef FormingAMagicSquare_hpp
#define FormingAMagicSquare_hpp

#include <stdio.h>

namespace FormingAMagicSquare {

    const vector<vector<int>> magicSquare = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    };

    int compare(vector<vector<int>> &s, bool reflectH, bool reflectV, bool invert) {
        int diff = 0;
        for (int r = 0; r < s.size(); ++r) {
            for (int c = 0; c < s[r].size(); ++c) {

                int rr = r, cc = c;
                if (invert)  rr = c, cc = r;

                if(reflectH) cc = 2 - cc;
                if(reflectV) rr = 2 - rr;
                
                diff += abs(s[r][c] - magicSquare[rr][cc]);
            }
        }
        return diff;
    }



    int formingMagicSquare(vector<vector<int>> s) {
        
        int minDiff = INT32_MAX;
        //helpers variables to transform the magic square
        //H: Horizontal, V: Vertical, I: Invert
        vector<bool> H = {false, true}, V = {false, true}, I = {false, true};
        
        
        for (bool h: H)
            for (bool v: V)
                for (bool i: I)
                    minDiff = min(minDiff, compare(s, h, v, i));
        
        return minDiff;
    }


    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/Implementation/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");
        
        string t_out;

        vector<vector<int>> s(3);

        for (int i = 0; i < 3; i++) {
            s[i].resize(3);

            string s_row_temp_temp;
            getline(input, s_row_temp_temp);

            vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

            for (int j = 0; j < 3; j++) {
                int s_row_item = stoi(s_row_temp[j]);

                s[i][j] = s_row_item;
            }
        }

        int result = formingMagicSquare(s);
        getline(output, t_out);
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);
    }
}

#endif /* FormingAMagicSquare_hpp */
