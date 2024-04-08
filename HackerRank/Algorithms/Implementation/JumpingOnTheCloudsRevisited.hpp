//
//  JumpingOnTheCloudsRevisited.hpp
//  HackerRank
//
//  Created by Salvatore on 31/3/24.
//

#ifndef JumpingOnTheCloudsRevisited_hpp
#define JumpingOnTheCloudsRevisited_hpp

#include <stdio.h>

namespace JumpingOnTheCloudsRevisited {
int jumpingOnClouds(vector<int> c, int k) {
    int energy = 100;
    int current = 0;
    
    do {
        current = (current + k) % c.size();
        energy -= 1 + c[current] * 2;
        
    }while(current != 0);
    return energy;
}
}

#endif /* JumpingOnTheCloudsRevisited_hpp */
