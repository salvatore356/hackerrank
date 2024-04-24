//
//  FlatlandSpaceStations.hpp
//  HackerRank
//
//  Created by Salvatore on 24/4/24.
//

#ifndef FlatlandSpaceStations_hpp
#define FlatlandSpaceStations_hpp

#include <stdio.h>

namespace FlatlandSpaceStations {
    
    int flatlandSpaceStations(int n, vector<int> c) {
        if(n == c.size()) return 0;

        int maxDist = 0;
        for(int i = 0 ; i < n; ++i){
            int minDist = n;
            for(int &station : c){
                minDist = min(minDist, abs(i - station));
            }
            maxDist = max(maxDist, minDist);
        }
            
        return maxDist;

    }

    void test() {
        string path = "Tests/Algorithms/Implementation/FlatlandSpaceStations/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string nm_temp;
        getline(input, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        string c_temp_temp;
        getline(input, c_temp_temp);

        vector<string> c_temp = split_string(c_temp_temp);

        vector<int> c(m);

        for (int i = 0; i < m; i++) {
            int c_item = stoi(c_temp[i]);

            c[i] = c_item;
        }

        int result = flatlandSpaceStations(n, c);

        string out;
        getline(output, out);
        assert(result == stoi(out), to_string(result) + " == " + out);

    }
}

#endif /* FlatlandSpaceStations_hpp */
