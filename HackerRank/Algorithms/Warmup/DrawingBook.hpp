//
//  DrawingBook.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef DrawingBook_hpp
#define DrawingBook_hpp

#include <stdio.h>

namespace DrawingBook {

    int pageCount(int n, int p) {
        int pagesFromFront = floor(p / 2.0);
        int pagesFromBack = floor(( ((n % 2 == 0) ? n + 1 : n) - p) / 2.0);
        
        return min(pagesFromBack, pagesFromFront);
    }
}

#endif /* DrawingBook_hpp */
