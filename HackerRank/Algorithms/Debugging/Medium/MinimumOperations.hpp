//
//  MinimumOperations.hpp
//  HackerRank
//
//  Created by Salvatore on 3/7/24.
//

#ifndef MinimumOperations_hpp
#define MinimumOperations_hpp

#include <stdio.h>

namespace MinimumOperations {

    int dp[110][1<<3];

    int min_operations(vector <int> red, vector <int> green, vector <int> blue) {

        int n = (int)red.size(), i, j;
        for (i = 0; i <= n; i++) {
            for (j = 0; j < 8; j++) {
                dp[i][j] = 1<<30;
            }
        }

        dp[0][0] = 0;
        for (i = 0; i < n; i++){
            for (j = 0; j < 8; j++){
                dp[i + 1][j | 1] = min(dp[i + 1][j | 1], dp[i][j] + green[i] + blue[i]);
                dp[i + 1][j | 2] = min(dp[i + 1][j | 2], dp[i][j] + red[i] + blue[i]);
                dp[i + 1][j | 4] = min(dp[i + 1][j | 4], dp[i][j] + red[i] + green[i]);
            }
        }
        j = 0;
        for (i = 0; i < n; i++){
            if (green[i]) j |= 1;
            if (red[i]) j |= 2;
            if (blue[i]) j |= 4;
        }

        if (dp[n][j] >= (1<<30))
            dp[n][j] = -1;

        return dp[n][j];
    }

    void test() {
        
        string test_case = "00";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        int n, r, g, b;
        io.input >> n;
        vector<int> red, blue, green;

        for(int i = 0; i < n; i++){

            io.input >> r >> g >> b;
            red.push_back(r);
            green.push_back(g);
            blue.push_back(b);
        }

        int result = min_operations(red, green, blue);
        
        getline(io.output, t_out);
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);
        
    }
}

#endif /* MinimumOperations_hpp */
