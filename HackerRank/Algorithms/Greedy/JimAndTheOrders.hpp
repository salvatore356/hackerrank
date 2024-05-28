//
//  JimAndTheOrders.hpp
//  HackerRank
//
//  Created by Salvatore on 28/5/24.
//

#ifndef JimAndTheOrders_hpp
#define JimAndTheOrders_hpp

#include <stdio.h>

namespace JimAndTheOrders {

    vector<int> jimOrders(vector<vector<int>> orders) {
        vector<pair<int,int>> prepTime(orders.size());
        vector<int> ans(orders.size());
        
        for (int i = 0; i < orders.size(); ++i) {
            prepTime[i].first = orders[i][0] + orders[i][1];
            prepTime[i].second = i + 1;
        }
        
        sort(prepTime.begin(), prepTime.end());
        
        for (int i = 0; i < prepTime.size(); ++i)
            ans[i] = prepTime[i].second;
        
        return ans;
    }

    void test() {
        
        string test_case = "07";
        string path = "Tests/Algorithms/Greedy/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string t_out;

        string n_temp;
        getline(input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> orders(n);

        for (int i = 0; i < n; i++) {
            orders[i].resize(2);

            string orders_row_temp_temp;
            getline(input, orders_row_temp_temp);

            vector<string> orders_row_temp = split(rtrim(orders_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int orders_row_item = stoi(orders_row_temp[j]);

                orders[i][j] = orders_row_item;
            }
        }

        vector<int> result = jimOrders(orders);

        string s_result = vector_to_string(result);
        getline(output, t_out);
        assert(s_result == t_out, s_result + " == " + t_out);
        
    }
}

#endif /* JimAndTheOrders_hpp */
