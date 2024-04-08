//
//  CountApplesAndOranges.hpp
//  HackerRank
//
//  Created by Salvatore on 29/3/24.
//

#ifndef CountApplesAndOranges_hpp
#define CountApplesAndOranges_hpp

#include <stdio.h>

namespace CountApplesAndOranges {

int countFruits(int s, int t, int tree, vector<int> &fruits) {
    int fruitsCounter = 0;
    
    for(int i = 0; i < (int)fruits.size(); ++i) {
        int dist = tree + fruits[i];
        fruitsCounter += dist >= s && dist <= t;
    }
    return fruitsCounter;
}

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    printf(
        "%d\n%d\n",
        countFruits(s, t, a, apples),
        countFruits(s, t, b, oranges)
    );
}
}

#endif /* CountApplesAndOranges_hpp */
