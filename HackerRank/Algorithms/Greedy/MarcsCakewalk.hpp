//
//  MarcsCakewalk.hpp
//  HackerRank
//
//  Created by Salvatore on 22/5/24.
//

#ifndef MarcsCakewalk_hpp
#define MarcsCakewalk_hpp

#include <stdio.h>

namespace MarcsCakewalk {


    long marcsCakewalk(vector<int> calorie) {
        long ans = 0;
        sort(calorie.begin(), calorie.end(), greater<int>());
        
        for (int i = 0; i < calorie.size(); ++i)
            ans += calorie[i] * pow(2, i);
        return ans;
    }

    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/Greedy/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string n_temp, t_out;
        getline(input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string calorie_temp_temp;
        getline(input, calorie_temp_temp);

        vector<string> calorie_temp = split(rtrim(calorie_temp_temp));

        vector<int> calorie(n);

        for (int i = 0; i < n; i++) {
            int calorie_item = stoi(calorie_temp[i]);

            calorie[i] = calorie_item;
        }

        long result = marcsCakewalk(calorie);
        
        getline(output, t_out);
        assert(result == stol(t_out), to_string(result) + " == " + t_out);
        
    }

}

#endif /* MarcsCakewalk_hpp */
