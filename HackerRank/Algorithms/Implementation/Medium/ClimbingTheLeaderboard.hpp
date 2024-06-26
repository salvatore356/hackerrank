//
//  ClimbingTheLeaderboard.hpp
//  HackerRank
//
//  Created by Salvatore on 7/6/24.
//

#ifndef ClimbingTheLeaderboard_hpp
#define ClimbingTheLeaderboard_hpp

#include <stdio.h>

namespace ClimbingTheLeaderboard {

    vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
        vector<int> ans(player.size(), 1);
        
        vector<int> positions;
        positions.push_back(ranked.front());
        
        for (int i = 1; i < ranked.size(); ++i) {
            if (ranked[i] != ranked[i-1])
                positions.push_back(ranked[i]);
        }
        
        int lastPosition = (int)positions.size() - 1;
        
        for (int i = 0; i < player.size(); ++i) {
            //int currentPlace = 1;
            for (int j = lastPosition; j >= 0; --j) {
                
                if (positions[j] > player[i]) {
                    ans[i] = j + 2 - (positions[j] == player[i]);
                    lastPosition = j;
                    break;
                }
            }
        }
        
        return ans;
    }

    void test() {
        string test_case = "00";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        string ranked_count_temp;
        getline(io.input, ranked_count_temp);

        int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

        string ranked_temp_temp;
        getline(io.input, ranked_temp_temp);

        vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

        vector<int> ranked(ranked_count);

        for (int i = 0; i < ranked_count; i++) {
            int ranked_item = stoi(ranked_temp[i]);

            ranked[i] = ranked_item;
        }

        string player_count_temp;
        getline(io.input, player_count_temp);

        int player_count = stoi(ltrim(rtrim(player_count_temp)));

        string player_temp_temp;
        getline(io.input, player_temp_temp);

        vector<string> player_temp = split(rtrim(player_temp_temp));

        vector<int> player(player_count);

        for (int i = 0; i < player_count; i++) {
            int player_item = stoi(player_temp[i]);

            player[i] = player_item;
        }

        vector<int> result = climbingLeaderboard(ranked, player);

        for (size_t i = 0; i < result.size(); i++) {
            getline(io.output, t_out);
            assert(result[i] == stoi(t_out), to_string(result[i]) + " == " + t_out);
        }

    }
}

#endif /* ClimbingTheLeaderboard_hpp */
