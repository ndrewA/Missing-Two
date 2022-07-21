#include <iostream>
#include <vector>
#include <math.h>

int missingOne(const std::vector<int>& vec)
{
    if(vec.empty()) return -1;
    size_t curSum = 0;
    for(const auto& num : vec)
        curSum += num;
    return (vec.size()+2)*(vec.size()+1)/2-curSum;
}

std::pair<int, int> missingTwo(const std::vector<int>& vec)
{
    if(vec.empty()) return {-1, -1};
    size_t curProd = 1;
    size_t curSum = 0;
    size_t targetProd = 1;
    for(size_t i = 0; i < vec.size(); i++)
    {
        curSum += vec[i];
        curProd *= vec[i];
        targetProd *= (i+1);
    }
    targetProd *= (vec.size()+1)*(vec.size()+2);
    size_t targetSum = (vec.size()+2)*(vec.size()+3)/2;
    int a = ((targetSum - curSum)+sqrt((curSum - targetSum)*(curSum - targetSum)-4*targetProd/curProd))/2;
    int b = targetSum - curSum - a;
    return {a, b};
}

int main()
{
    auto res = missingTwo({1, 2, 3, 4, 6, 7, 8, 10});
    std::cout << "res = " << res.first << ' ' << res.second << '\n';
    return 0;
}
