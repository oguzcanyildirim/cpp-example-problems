/* Write a program that computes the length of the 
longest common subsequence of three given strings. 
For example, given "epidemiologist", "refrigeration", and "supercalifragilisticexpialodocious", 
it should return 5, since the longest common subsequence is "eieio".*/
#include <string>
#include <iostream>
#include <map>

int recursiveLcs(std::string s1, std::string s2, 
std::map<std::pair<std::string, std::string>, int>& lcsMap )
{
    // if at least one of the strings is empty, there is no need to compare
    if(s1.empty() || s2.empty())
    {
        return 0;
    }
    auto currStrPair = std::make_pair(s1,s2);
    if (lcsMap[currStrPair])
    {
        return lcsMap[currStrPair];
    }
    int commonLength = 0;
    if(s1[0] == s2[0])
    {
        commonLength = 1 + recursiveLcs(s1.erase(0, 1), s2.erase(0, 1), lcsMap);
    }
    else
    {
        commonLength = std::max( 
            recursiveLcs(s1.erase(0, 1), s2, lcsMap), 
            recursiveLcs(s1, s2.erase(0, 1), lcsMap ) );
    }
    lcsMap[currStrPair] = commonLength;
    return commonLength;
}

void commonLengthFindAndPrint(const std::string& s1, const std::string& s2)
{
    std::map<std::pair<std::string, std::string>, int> lcsMap;
    std::cout << "Common Length between " << s1 << " and " << s2 <<" is: "
    << recursiveLcs(s1, s2, lcsMap) << std::endl;
}
int main()
{
    std::string firstString = "epidemiologist";
    std::string secondString = "refrigeration";
    std::string thirdString = "supercalifragilisticexpialodocious";
    
    
    ::commonLengthFindAndPrint(firstString, secondString);
    ::commonLengthFindAndPrint(secondString, thirdString);
    ::commonLengthFindAndPrint(firstString, thirdString);

    return 0;
}