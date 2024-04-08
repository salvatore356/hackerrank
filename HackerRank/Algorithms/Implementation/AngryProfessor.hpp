//
//  AngryProfessor.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef AngryProfessor_hpp
#define AngryProfessor_hpp

#include <stdio.h>

namespace AngryProfessor {
    string angryProfessor(int k, vector<int> a) {
        int onTime = 0;
        
        for(int i = 0; i < a.size(); ++i)
            onTime += a[i] <= 0;
            
        return onTime < k ? "YES" : "NO";
    }
}

#endif /* AngryProfessor_hpp */
