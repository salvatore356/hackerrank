//
//  ViralAdvertising.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef ViralAdvertising_hpp
#define ViralAdvertising_hpp

#include <stdio.h>

namespace ViralAdvertising {

    int viralAdvertising(int n) {
        int liked = 2, totalLikes = 2;
        int shared = 5;
        
        for(int i = 1; i < n; ++i){
            shared = liked * 3;
            liked = floor(shared / 2);
            totalLikes += liked;
        }
        
        return totalLikes;
    }
}

#endif /* ViralAdvertising_hpp */
