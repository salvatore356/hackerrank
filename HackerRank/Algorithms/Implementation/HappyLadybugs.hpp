//
//  HappyLadybugs.hpp
//  HackerRank
//
//  Created by Salvatore on 25/4/24.
//

#ifndef HappyLadybugs_hpp
#define HappyLadybugs_hpp

#include <stdio.h>

namespace HappyLadybugs {

    string happyLadybugs(string b) {
        
        vector<int> letters(27);
        bool canMove = false, sorted = true;
        for(int i = 0; i < b.size(); ++i) {
            if(b[i] == '_') {
                canMove = true;
                continue;
            }
            
            if(i > 0 && i < b.size() - 1){
                sorted = sorted && (b[i + 1] == b[i] || b[i - 1] == b[i]);
            }
            
            ++letters[b[i] - 'A'];
        }
        if(!canMove && !sorted) return "NO";
        
        for(int i = 0; i < letters.size(); ++i)
            if(letters[i] == 1) return "NO";
        
        return "YES";
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/HappyLadybugs/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string g_temp;
        getline(input, g_temp);

        int g = stoi(ltrim(rtrim(g_temp)));

        for (int g_itr = 0; g_itr < g; g_itr++) {
            string n_temp;
            getline(input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));

            string b;
            getline(input, b);

            string result = happyLadybugs(b);

            string out;
            getline(output, out);
            assert(result == out, result + " == " + out);
        }

    }
}

#endif /* HappyLadybugs_hpp */
