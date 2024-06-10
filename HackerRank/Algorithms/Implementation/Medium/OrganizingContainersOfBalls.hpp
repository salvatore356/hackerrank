//
//  OrganizingContainersOfBalls.hpp
//  HackerRank
//
//  Created by Salvatore on 11/6/24.
//

#ifndef OrganizingContainersOfBalls_hpp
#define OrganizingContainersOfBalls_hpp

#include <stdio.h>

namespace OrganizingContainersOfBalls {

    string organizingContainers(vector<vector<int>> container) {
        vector<int> count(container.size());
        vector<int> type(container.size());
        
        int index = 0;
        for (int i = 0; i < container.size(); ++i) {
            for (int j = 0; j < container[i].size(); ++j) {
                count[i] += container[i][j];
                type[j] += container[i][j];
            }
        }
        sort(count.begin(), count.end());
        sort(type.begin(), type.end());
        
        return type == count ? "Possible" : "Impossible";
    }

    void test() {
        string test_case = "00";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        string q_temp;
        getline(io.input, q_temp);

        int q = stoi(ltrim(rtrim(q_temp)));

        for (int q_itr = 0; q_itr < q; q_itr++) {
            string n_temp;
            getline(io.input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));

            vector<vector<int>> container(n);

            for (int i = 0; i < n; i++) {
                container[i].resize(n);

                string container_row_temp_temp;
                getline(io.input, container_row_temp_temp);

                vector<string> container_row_temp = split(rtrim(container_row_temp_temp));

                for (int j = 0; j < n; j++) {
                    int container_row_item = stoi(container_row_temp[j]);

                    container[i][j] = container_row_item;
                }
            }

            string result = organizingContainers(container);

            getline(io.output, t_out);
            assert(result == t_out, result + " == " + t_out);
        }

    }
}

#endif /* OrganizingContainersOfBalls_hpp */
