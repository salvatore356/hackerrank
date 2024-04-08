//
//  TheHurdleRace.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef TheHurdleRace_hpp
#define TheHurdleRace_hpp

#include <stdio.h>

namespace TheHurdleRace {

int hurdleRace(int k, vector<int> height) {
    int maxHeight = 0;
    
    for(int i = 0; i < height.size(); ++i)
        maxHeight = max(maxHeight, height[i]);
        
    if(k >= maxHeight) return 0;
    
    return maxHeight - k;
    
}
}

#endif /* TheHurdleRace_hpp */
