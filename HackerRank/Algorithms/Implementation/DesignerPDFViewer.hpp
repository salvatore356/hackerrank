//
//  DesignerPDFViewer.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef DesignerPDFViewer_hpp
#define DesignerPDFViewer_hpp

#include <stdio.h>

namespace DesignerPDFViewer {

    int designerPdfViewer(vector<int> h, string word) {
        int maxHeight = 0;
        
        for(int i = 0; i < word.size(); ++i)
            maxHeight = max(maxHeight, h[word[i] - 'a']);
        
        return maxHeight * word.size();
    }
}

#endif /* DesignerPDFViewer_hpp */
