#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

bool linear_search(int N, std::vector<int>& S)
{
    for (auto i : S) {
        if (i == N)
            return true; // 원소를 찾음!
    }
    return false;
}
