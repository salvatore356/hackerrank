//
//  QueensAttackII.hpp
//  HackerRank
//
//  Created by Salvatore on 10/6/24.
//

#ifndef QueensAttackII_hpp
#define QueensAttackII_hpp

#include <stdio.h>

namespace QueensAttackII {

    int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
        
        int L = c_q - 1, R = n - c_q, U = r_q - 1, D = n - r_q;
        int UL = min(U, L), UR = min(U, R), DL = min(D, L), DR = min(D, R);
        
        for (int i = 0; i < obstacles.size(); ++i) {
            int distV = obstacles[i][0] - r_q;
            int distH = obstacles[i][1] - c_q;
            
            if (abs(distV) == abs(distH)) {
                
                if (distV > 0) {
                    if (distH > 0) DR = min(DR, distH - 1);
                    else DL = min(DL, abs(distH) - 1);
                }else {
                    if (distH > 0) UR = min(UR, distH - 1);
                    else UL = min(UL, abs(distH) - 1);
                }
                        
            }else if (distV == 0) {
                if (distH > 0) R = min(R, distH - 1);
                else  L = min(L, abs(distH) - 1);
            } else if (distH == 0) {
                if (distV > 0) D = min(D, distV - 1);
                else  U = min(U, abs(distV) - 1);
            }
        }
        
        return (R + L) + (U + D) + (DR + UL) + (UR + DL);
    }

    void test() {
        string test_case = "20";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        string first_multiple_input_temp;
        getline(io.input, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        string second_multiple_input_temp;
        getline(io.input, second_multiple_input_temp);

        vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

        int r_q = stoi(second_multiple_input[0]);

        int c_q = stoi(second_multiple_input[1]);

        vector<vector<int>> obstacles(k);

        for (int i = 0; i < k; i++) {
            obstacles[i].resize(2);

            string obstacles_row_temp_temp;
            getline(io.input, obstacles_row_temp_temp);

            vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int obstacles_row_item = stoi(obstacles_row_temp[j]);

                obstacles[i][j] = obstacles_row_item;
            }
        }

        int result = queensAttack(n, k, r_q, c_q, obstacles);

        getline(io.output, t_out);
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);
    }
}

#endif /* QueensAttackII_hpp */
