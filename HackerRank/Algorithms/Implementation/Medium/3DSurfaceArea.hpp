//
//  3DSurfaceArea.hpp
//  HackerRank
//
//  Created by Salvatore on 18/6/24.
//

#ifndef _DSurfaceArea_hpp
#define _DSurfaceArea_hpp

#include <stdio.h>

namespace _3DSurfaceArea {

    int surfaceArea(vector<vector<int>> A) {
        int cols = (int)A.front().size();
        int rows = (int)A.size();
        
        int total = 0;
        int right, bottom, current;
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                
                current = A[r][c];
                right = 0;
                bottom = 0;
                
                if (r < rows - 1) bottom = A[r + 1][c];
                if (c < cols - 1) right = A[r][c + 1];
                
                total += abs(current - bottom) + abs(current - right) + 2;
            }
            
            total += A[r][0];
        }
        
        for(int c = 0; c < cols; ++c)
            total += A[0][c];
            
        return total;
    }

    void test() {
        string test_case = "00";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        string first_multiple_input_temp;
        getline(io.input, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int H = stoi(first_multiple_input[0]);

        int W = stoi(first_multiple_input[1]);

        vector<vector<int>> A(H);

        for (int i = 0; i < H; i++) {
            A[i].resize(W);

            string A_row_temp_temp;
            getline(io.input, A_row_temp_temp);

            vector<string> A_row_temp = split(rtrim(A_row_temp_temp));

            for (int j = 0; j < W; j++) {
                int A_row_item = stoi(A_row_temp[j]);

                A[i][j] = A_row_item;
            }
        }

        int result = surfaceArea(A);

        getline(io.output, t_out);
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);
    }
}

#endif /* _DSurfaceArea_hpp */
