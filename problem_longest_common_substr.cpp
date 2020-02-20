/* Write a program that computes the length of the 
longest common subsequence of three given strings. 
For example, given "epidemiologist", "refrigeration", and "supercalifragilisticexpialodocious", 
it should return 5, since the longest common subsequence is "eieio".*/
#include <string>
#include <iostream>
int recursiveLcs(std::string s1, std::string s2)
{
    // if at least one of the strings is empty, there is no need to compare
    if(s1.empty() || s2.empty())
    {
        return 0;
    }

    int commonLength = 0;
    if(s1[0] == s2[0])
    {
        commonLength = 1 + recursiveLcs(s1.erase(0, 1), s2.erase(0, 1));
    }
    else
    {
        commonLength = std::max( 
            recursiveLcs(s1.erase(0, 1), s2), 
            recursiveLcs(s1, s2.erase(0, 1)) );
    }
    
    return commonLength;
}

void commonLengthFindAndPrint(const std::string& s1, const std::string& s2)
{
    std::cout << "Common Length between " << s1 << " and " << s2 <<" is: "
    << recursiveLcs(s1, s2) << std::endl;
}
int main()
{
    std::string firstString = "epidemiologist";
    std::string secondString = "refrigeration";
    std::string thirdString = "supercalifragilisticexpialodocious";

    std::cout << "Common Length: " << recursiveLcs(firstString, secondString) << std::endl;
    ::commonLengthFindAndPrint(firstString, secondString);
    ::commonLengthFindAndPrint(secondString, thirdString);
    ::commonLengthFindAndPrint(firstString, thirdString);

    std::cout << "Common Length with an empty string: " 
    << recursiveLcs(firstString, "") << std::endl;

    return 0;
}