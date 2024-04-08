//
//  CatsAndAMouse.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef CatsAndAMouse_hpp
#define CatsAndAMouse_hpp

#include <stdio.h>

namespace CatsAndAMouse {
    string catAndMouse(int x, int y, int z) {
        
        int distA = abs(x - z);
        int distB = abs(y - z);
        
        string ans = "Mouse C";

        if(distA < distB) ans ="Cat A";
        else if( distB < distA) ans = "Cat B";
        return ans;

    }
}

#endif /* CatsAndAMouse_hpp */
