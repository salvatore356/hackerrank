//
//  ACMICPCTeam.hpp
//  HackerRank
//
//  Created by Salvatore on 17/4/24.
//

#ifndef ACMICPCTeam_hpp
#define ACMICPCTeam_hpp

#include <stdio.h>

namespace ACMICPCTeam {

    int totalTopics(string s1, string s2){
        int total = 0;
        for(int i = 0; i < s1.size(); ++i)
            total += s1[i] == '1' || s2[i] == '1';
        return total;
    }

    vector<int> acmTeam(vector<string> topic) {
        unordered_map<int, int> num_topics;
        int maxTopics = 0;
        
        for(int i = 0; i < topic.size() - 1; ++i)
            for(int j = i + 1; j < topic.size(); ++j){
                int temp = totalTopics(topic[i], topic[j]);
                ++num_topics[temp];
                maxTopics = max(maxTopics, temp);
            }
                        
            return { maxTopics, num_topics[maxTopics]};
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/ACMICPCTeam/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string first_multiple_input_temp;
        getline(input, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<string> topic(n);

        for (int i = 0; i < n; i++) {
            string topic_item;
            getline(input, topic_item);

            topic[i] = topic_item;
        }

        vector<int> result = acmTeam(topic);

        string out1, out2;
        getline(output, out1);
        getline(output, out2);

        printf("\n");
        assert(result[0] == stoi(out1), to_string(result[0]) + " == " + out1);
        assert(result[1] == stoi(out2), to_string(result[1]) + " == " + out2);
    }
}

#endif /* ACMICPCTeam_hpp */
