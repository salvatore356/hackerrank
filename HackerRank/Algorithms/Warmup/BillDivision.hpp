//
//  BillDivision.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef BillDivision_hpp
#define BillDivision_hpp

#include <stdio.h>

namespace BillDivision {

void bonAppetit(vector<int> bill, int k, int b) {
    int totalBill = 0;
    
    for(int i = 0; i < bill.size(); ++i){
        totalBill += bill[i];
    }
    
    int amountAnna = (totalBill - bill[k]) / 2;
    int diff = b - amountAnna;
    
    if(diff == 0) printf("Bon Appetit\n");
    else printf("%d\n", diff);
    
}
}

#endif /* BillDivision_hpp */
