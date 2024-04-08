//
//  NumberLineJumps.hpp
//  HackerRank
//
//  Created by Salvatore on 29/3/24.
//

#ifndef NumberLineJumps_hpp
#define NumberLineJumps_hpp

#include <stdio.h>

namespace NumberLineJumps {
    string kangaroo(int x1, int v1, int x2, int v2) {
        if(
            ( x1 >= x2 && v1 >= v2) ||
            ( x2 >= x1 && v2 >= v1)
        ) return "NO";
        
        if( (x1 - x2) % (v2 - v1) == 0 )
            return "YES";
        
        return "NO";
    }
}

#endif /* NumberLineJumps_hpp */
