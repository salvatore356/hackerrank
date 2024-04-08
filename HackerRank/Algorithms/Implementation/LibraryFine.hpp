//
//  LibraryFine.hpp
//  HackerRank
//
//  Created by Salvatore on 3/4/24.
//

#ifndef LibraryFine_hpp
#define LibraryFine_hpp

#include <stdio.h>

namespace LibraryFine {

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    if(y1  != y2) return  (y1 < y2) ? 0 : 10000;
    if(m1 != m2) return  (m1 < m2) ? 0 : (m1 - m2) * 500;
    if( d1 > d2) return (d1 - d2) * 15;
    return 0;
}

int test() {
    
    std::ifstream input("Tests/Algorithms/Implementation/LibraryFine/input00.txt");
    std::ifstream output("Tests/Algorithms/Implementation/LibraryFine/output00.txt");
    
    string first_multiple_input_temp;
    getline(input, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int d1 = stoi(first_multiple_input[0]);

    int m1 = stoi(first_multiple_input[1]);

    int y1 = stoi(first_multiple_input[2]);

    string second_multiple_input_temp;
    getline(input, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int d2 = stoi(second_multiple_input[0]);

    int m2 = stoi(second_multiple_input[1]);

    int y2 = stoi(second_multiple_input[2]);

    int result = libraryFine(d1, m1, y1, d2, m2, y2);

    string expected_output;
    getline(output, expected_output);
    assert(result == stoi(expected_output), to_string(result) + " == " + expected_output);

    return 0;
}
}

#endif /* LibraryFine_hpp */
