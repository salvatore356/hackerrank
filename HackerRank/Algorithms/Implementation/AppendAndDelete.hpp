//
//  AppendAndDelete.hpp
//  HackerRank
//
//  Created by Salvatore on 15/4/24.
//

#ifndef AppendAndDelete_hpp
#define AppendAndDelete_hpp

#include <stdio.h>

namespace AppendAndDelete {

    string appendAndDelete(string s, string t, int k) {
        if(k >= s.size() + t.size()) return "Yes";
        
        int e = 0;
        for(; e < min(s.size(), t.size()); ++e ) if(s[e] != t[e]) break;
        
        int deleteInS = (int)s.size() - e, appendInS = (int)t.size() - e;
        
        int minChangesNeeded = (deleteInS + appendInS);
        
        bool canAppendAndDelete = (k >= minChangesNeeded) &&
                                ( (k - minChangesNeeded) % 2 == 0) ;
        
        return canAppendAndDelete ? "Yes"  :  "No";
    }


    void test(){
        string path = "Tests/Algorithms/Implementation/AppendAndDelete/";
        std::ifstream input(path  +  "input13.txt");
        std::ifstream output(path + "output13.txt");
        
        string s;
        getline(input, s);

        string t;
        getline(input, t);

        string k_temp;
        getline(input, k_temp);

        int k = stoi(ltrim(rtrim(k_temp)));

        string result = appendAndDelete(s, t, k);

        string expected;
        getline(output, expected);

        assert(result == expected, result + " == " + expected);

    }
}

#endif /* AppendAndDelete_hpp */
