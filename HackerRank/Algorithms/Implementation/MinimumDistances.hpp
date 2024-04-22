//
//  MinimumDistances.hpp
//  HackerRank
//
//  Created by Salvatore on 22/4/24.
//

#ifndef MinimumDistances_hpp
#define MinimumDistances_hpp

#include <stdio.h>

namespace MinimumDistances {

    int minimumDistances(vector<int> a) {
        unordered_map<int, int> lastPosition;
        int minimum = INT32_MAX;
        
        for(int i = 0; i < a.size(); ++i){
            if(lastPosition.find(a[i]) != lastPosition.end()){
                int dist = i - lastPosition[a[i]];
                minimum = min(dist, minimum);
            }
            lastPosition[a[i]] = i;
        }
        
        return minimum == INT32_MAX ? -1 : minimum;
    }

    void test(){
        string path = "Tests/Algorithms/Implementation/MinimumDistances/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string n_temp;
        getline(input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string a_temp_temp;
        getline(input, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        int result = minimumDistances(a);

        string out1;
        getline(output, out1);
        
        assert(result == stoi(out1), to_string(result) + " == " + out1);
        

    }
}

#endif /* MinimumDistances_hpp */
