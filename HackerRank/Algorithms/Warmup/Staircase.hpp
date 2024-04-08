//
//  Staircase.hpp
//  HackerRank
//
//  Created by Salvatore on 28/3/24.
//

#ifndef Staircase_hpp
#define Staircase_hpp

#include <stdio.h>

namespace Staircase {
    void staircase(int n) {
        string step(n, ' ');
        
        for(int i = 0; i < n; ++i) {
            step[ n - (i + 1)] = '#';
            printf("%s\n", step.c_str());
            
        }
            
    }
}

#endif /* Staircase_hpp */
