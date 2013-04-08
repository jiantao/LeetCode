/*
 * =====================================================================================
 *
 *       Filename:  restore_ip.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/05/2013 09:49:14 PM
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
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string> ipStrs;
        int strLen = s.length();
        if (strLen > 16 || strLen < 4)
            return ipStrs;

        points.clear();

        vector<Point> start;
        start.push_back(Point(-1, 0));
        points.push_back(start);

        while (points.size() > 0)
        {
            const Point& lastPoint = points.front().back();
            if (lastPoint.i == 3)
            {
                cleanUpPoints(s);
                break;
            }

            int currStart = lastPoint.pos + 1;
            int currLevel = lastPoint.i + 1;
            
            if (currStart >= strLen - 1)
            {
                points.pop_front();
                continue;
            }

            vector<Point>& frontPoints = points.front();
            if (currLevel == 1)
                frontPoints.clear();

            for (int i = 0; i != 3; ++i)
            {
                int currEnd = currStart + i;
                if (currEnd >= strLen - 1)
                    break;

                if (isValidPoint(s, currStart, currEnd))
                {
                    frontPoints.push_back(Point(currEnd, currLevel));
                    points.push_back(frontPoints);
                    frontPoints.pop_back();
                }
            }

            points.pop_front();
        }

        convertPointsToStr(ipStrs, s);

        return ipStrs;
    }

private:

    bool isValidPoint(const string& str, int start, int end)
    {
        if (end - start > 2)
            return false;

        if (end - start < 0)
            return false;

        if (end - start > 0 && str[start] == '0')
            return false;

        if (end - start == 2)
        {
            string sub = str.substr(start, 3);
            if (atoi(sub.c_str()) > 255)
                return false;
        }

        return true;
    }

    void cleanUpPoints(const string& s)
    {
        list<vector<Point> >::iterator iter = points.begin();
        while (iter != points.end())
        {
            const Point& lastPoint = (*iter).back();
            if (!isValidPoint(s, lastPoint.pos + 1, s.length() - 1))
                iter = points.erase(iter);
            else
                ++iter;
        }
    }

    void convertPointsToStr(vector<string>& ipStrs, const string& str)
    {
        list<vector<Point> >::iterator iter;
        for (iter = points.begin(); iter != points.end(); ++iter)
        {
            int start = 0;
            int size = iter->size();
            string temp;
            for (int i = 0; i != size; ++i)
            {
                int currEnd = (*iter)[i].pos;
                int currLen = currEnd - start + 1;
                temp += str.substr(start, currLen) + ".";
                start =  currEnd + 1;
            }

            temp += str.substr(start, str.length() - start);
            ipStrs.push_back(temp);
        }
    }

private:
    struct Point
    {
        int8_t pos;
        int8_t i;

        Point(int8_t pos, int8_t i) : pos(pos), i(i) {};
    };

    list<vector<Point> > points;
};

class Solution2
{
public:

    vector<string> restoreIpAddresses(string s) 
    {
        results.clear();
        pos[0] = -1;
        dfs(s, 1);

        return results;
    }

private:

    void dfs(const string& str, int level)
    {
        if (level == 4 && isValid(str, level, pos[level-1]+1, str.length()-1))
        {
            string temp;
            for (int i = 1; i != 4; ++i)
                temp += str.substr(pos[i - 1] + 1, pos[i] - pos[i-1]) + ".";

            temp += str.substr(pos[3] + 1,  str.length() - pos[3]);
            results.push_back(temp);
            return;
        }

        int currStart = pos[level - 1] + 1;
        for (int i = 0; i < 3; ++i)
        {
            int currEnd = currStart + i;
            if (isValid(str, level, currStart, currEnd))
            {
                pos[level] = currEnd;
                dfs(str, level + 1);
            }
        }
    }

    bool isValid(const string& str, int level, int start, int end)
    {
        int restLen = str.length() - start;
        int currLen = end - start + 1;

        if (restLen < 5 - level || restLen > (5 - level) * 3)
            return false;

        if (currLen > 1 && str[start] == '0')
            return false;

        if (currLen == 3)
        {
            string sub = str.substr(start, 3);
            if (atoi(sub.c_str()) > 255)
                return false;
        }

        return true;
    }
    
private:

    vector<string> results;
    int pos[4];
};

int main(int argc, char *argv[])
{
    string test("25525511135");
    Solution2 solution;

    vector<string> results = solution.restoreIpAddresses(test);

    for (unsigned int i = 0; i != results.size(); ++i)
        cout << results[i] << "\n";

    return 0;
}
