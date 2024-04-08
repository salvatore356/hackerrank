//
//  MigratoryBirds.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef MigratoryBirds_hpp
#define MigratoryBirds_hpp

#include <stdio.h>

namespace MigratoryBirds {

    int migratoryBirds(vector<int> arr) {
        unordered_map<int, int> counter;
        int maxBird = INT32_MAX;
        for(int i = 0; i < arr.size(); ++i){
            ++counter[arr[i]];
            
            if(counter[arr[i]] > counter[maxBird] )
                maxBird = arr[i];
            else if(counter[arr[i]] == counter[maxBird])
                maxBird = min(maxBird, arr[i]);
            
        }
            
        return maxBird;
    }
}

#endif /* MigratoryBirds_hpp */
