//
//  TheGridSearch.hpp
//  HackerRank
//
//  Created by Salvatore on 17/6/24.
//

#ifndef TheGridSearch_hpp
#define TheGridSearch_hpp

#include <stdio.h>

namespace TheGridSearch {

    
    bool compare(vector<string> &src, vector<string> &dst, int r, int c) {
        
        int width = dst.front().size();
        int height = dst.size();
        
        for (int i = 0;  i < height; ++i) {
            int rr = r + i;
            
            if (rr >= src.size()) return false;
            
            for (int j = 0; j < width; ++j) {
                int cc = c + j;
                
                if (cc > src[i].size()) break;
                
                if(src[rr][cc] != dst[i][j]) return false;
            }
        }
        
        return true;
    }

    string gridSearch(vector<string> G, vector<string> P) {
        
        for (int r = 0; r < G.size(); ++r) {
            for (int c = 0; c < G[r].size(); ++c) {
                if (compare(G, P, r, c))
                    return "YES";
            }
        }
        
        return "NO";
    }

    void test() {
        string test_case = "05";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        string t_temp;
        getline(io.input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string first_multiple_input_temp;
            getline(io.input, first_multiple_input_temp);

            vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

            int R = stoi(first_multiple_input[0]);

            int C = stoi(first_multiple_input[1]);

            vector<string> G(R);

            for (int i = 0; i < R; i++) {
                string G_item;
                getline(io.input, G_item);

                G[i] = G_item;
            }

            string second_multiple_input_temp;
            getline(io.input, second_multiple_input_temp);

            vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

            int r = stoi(second_multiple_input[0]);

            int c = stoi(second_multiple_input[1]);

            vector<string> P(r);

            for (int i = 0; i < r; i++) {
                string P_item;
                getline(io.input, P_item);

                P[i] = P_item;
            }

            string result = gridSearch(G, P);
            getline(io.output, t_out);
            assert(result == t_out, result + " == " + t_out);
        }

    }
}

#endif /* TheGridSearch_hpp */
