/* Write a program that computes the length of the 
longest common subsequence of three given strings. 
For example, given "epidemiologist", "refrigeration", and "supercalifragilisticexpialodocious", 
it should return 5, since the longest common subsequence is "eieio".*/
#include <string>
#include <iostream>
int recursiveLcs(std::string &s1, std::string &s2)
{
    // if at least one of the strings is empty, there is no need to compare
    if(s1.empty() || s2 == "")
    {
        return 0;
    }

    int commonLength = 0;
    if(s1[0] == s2[0])
    {
        commonLength = commonLength+ 1;
    }
    else
    {

    }
    
    return commonLength;
}

int main()
{
    std::string firstString = "epidemiologist";
    std::string secondString = "refrigeration";
    std::string thirdString = "supercalifragilisticexpialodocious";

    std::cout << "Common Length: " << recursiveLcs(firstString, secondString) << std::endl;

    return 0;
}