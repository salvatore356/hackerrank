//
//  TwoCharacters.hpp
//  HackerRank
//
//  Created by Salvatore on 3/5/24.
//

#ifndef TwoCharacters_hpp
#define TwoCharacters_hpp

#include <stdio.h>

namespace TwoCharacters {

    vector<char> createDict(string &s) {
        vector<char> letters;
        for (int i = 0; i < s.size(); ++i){
            if(find(letters.begin(), letters.end(), s[i]) == letters.end())
                letters.push_back(s[i]);
        }
        return letters;
    }

    vector<pair<char, char>> createPairs(string &s) {
        vector<char> letters = createDict(s);
        vector<pair<char, char>> pairs;
        
        for (int i = 0; i < letters.size(); ++i) {
                for (int j = i + 1; j < letters.size(); ++j)
                    pairs.push_back({letters[i], letters[j]});
        }
        return pairs;
    }

    void clearString(char a, char b, string &s) {
        for (int h = (int)s.length() - 1; h >= 0 ; --h)
            if (s[h] != a && s[h] != b)  s.erase(h, 1);
    }

    bool isValidString(string &s) {
        for (int k = 0; k < (s.length()-1); k++)
            if (s[k] == s[k + 1]) return false;
        return true;
    }

    int alternate(string s) {
        vector<pair<char, char>> pairs = createPairs(s);

        int maxCount = 0;
        
        for (auto &p : pairs) {
            string tmp = s;
            clearString(p.first, p.second, tmp);
            if(isValidString(tmp))
                maxCount = max(maxCount, (int)tmp.length());
        }
        
        return maxCount;
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/TwoCharacters/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string l_temp;
        getline(input, l_temp);

        //int l = stoi(ltrim(rtrim(l_temp)));

        string s;
        getline(input, s);

        int result = alternate(s);
        string out;
        getline(output, out);
        assert(result == stoi(out), to_string(result) + " == " + out);

    }
}

#endif /* TwoCharacters_hpp */
