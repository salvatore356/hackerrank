//
//  CorrectnessAndTheLoopInvariant.hpp
//  HackerRank
//
//  Created by Salvatore on 6/5/24.
//

#ifndef CorrectnessAndTheLoopInvariant_hpp
#define CorrectnessAndTheLoopInvariant_hpp

#include <stdio.h>

namespace CorrectnessAndTheLoopInvariant {

    string insertionSort(int N, int arr[]) {
        int i,j;
        int value;
        for(i=1;i<N;i++)
        {
            value=arr[i];
            j=i-1;
            while(j>=0 && value<arr[j])
            {
                arr[j+1]=arr[j];
                j=j-1;
            }
            arr[j+1]=value;
        }
        string ans;
        for(j=0;j<N;j++)
        {
            ans += to_string(arr[j]) + " ";
        }
        
        return trim(ans);
    }
    void test() {
        
        string path = "Tests/Algorithms/Sorting/CorrectnessAndTheLoopInvariant/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");
                
        string N_temp;
        getline(input, N_temp);
        
        int N = stoi(N_temp);
        
        string arr_temp;
        getline(input, arr_temp);

        vector<string> temp = split(rtrim(arr_temp));
        
        int arr[N], i;
        for(i = 0; i < N; i++) {
            arr[i] = stoi(temp[i]);
        }
        
        string result = insertionSort(N, arr);
        
        
        getline(output, arr_temp);
        assert(result == arr_temp, result + " == " + arr_temp);
        
    }
}
#endif /* CorrectnessAndTheLoopInvariant_hpp */
