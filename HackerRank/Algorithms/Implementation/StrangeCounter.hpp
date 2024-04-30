//
//  StrangeCounter.hpp
//  HackerRank
//
//  Created by Salvatore on 30/4/24.
//

#ifndef StrangeCounter_hpp
#define StrangeCounter_hpp

#include <stdio.h>

namespace StrangeCounter {

    long strangeCounter(long t) {
        long initialTimer = 3, currentIndex = 3;
        
        while(currentIndex < t) {
            initialTimer *= 2;
            currentIndex += initialTimer;
        }
        
        return currentIndex - t + 1;;
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/StrangeCounter/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string t_temp;
        getline(cin, t_temp);

        long t = stol(ltrim(rtrim(t_temp)));

        long result = strangeCounter(t);

        string out;
        getline(output, out);
        assert(result == stol(out), to_string(result) + " == " + out);



    }
}

#endif /* StrangeCounter_hpp */
