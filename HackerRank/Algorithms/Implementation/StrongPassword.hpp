//
//  StrongPassword.hpp
//  HackerRank
//
//  Created by Salvatore on 2/5/24.
//

#ifndef StrongPassword_hpp
#define StrongPassword_hpp

#include <stdio.h>

namespace StrongPassword {
    bool isSpecialCharacter(char c) {
        std::string specialChars = "!@#$%^&*()-+";
        return specialChars.find(c) != std::string::npos;
    }

    int minimumNumber(int n, string password) {
        vector<bool> conditions(4);
        
        // Return the minimum number of characters to make the password strong
        for(auto &letter : password) {
            if (islower(letter)) conditions[0] = true;
            if (isupper(letter)) conditions[1] = true;
            if (isdigit(letter)) conditions[2] = true;
            if(isSpecialCharacter(letter))  conditions[3] = true;
        }
        
        int met = 0;
        for(auto condition: conditions)
            met += condition;
        
        return max(4 - met, 6 - (int)password.size());
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/StrongPassword/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string n_temp;
        getline(input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string password;
        getline(input, password);

        int result = minimumNumber(n, password);
        
        string out;
        getline(output, out);
        assert(result == stoi(out), to_string(result) + " == " + out);
        
    }
}

#endif /* StrongPassword_hpp */
