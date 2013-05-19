/*
 * =====================================================================================
 *
 *       Filename:  random_line_in_file.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/18/2013 09:31:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include "header.hpp"

using namespace std;


class Solution
{
public:
    string randomLine(const char* filename)
    {
        string line("");
        FILE* input = fopen(filename, "r");
        if (input == NULL)
            return line;

        int count = 0;
        while (fgets(buff, MAX_LINE, input) != NULL)
        {
            ++count;
            if ((double) rand() / RAND_MAX <= 1.0 / count)
                line.assign(buff);
        }

        return line;
    }

private:
    static const int MAX_LINE = 1024;
    char buff[MAX_LINE];
};
