/*
 * =====================================================================================
 *
 *       Filename:  merge_intervals.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2013 02:35:53 PM
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


//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution 
{
public:
    vector<Interval> merge(vector<Interval> &intervals) 
    {
        result.clear();
        int size = intervals.size();
        sort(intervals.begin(), intervals.end(), CompareInterval());

        int curr = 0;
        Interval merged;

        while (curr < size)
        {
            merged.start = intervals[curr].start;
            merged.end = intervals[curr].end;

            int iter = curr + 1;
            while (iter < size && intervals[iter].start <= merged.end)
            {
                merged.end = merged.end > intervals[iter].end ? merged.end : intervals[iter].end;
                ++iter;
            }

            result.push_back(merged);
            curr = iter;
        }

        return result;
    }

private:

    struct CompareInterval
    {
        int asStart(const Interval& interval) const
        {
            return interval.start;
        }

        int asStart(int start) const
        {
            return start;
        }

        int asEnd(const Interval& interval) const
        {
            return interval.end;
        }

        int asEnd(int end) const
        {
            return end;
        }

        template<typename T1, typename T2>
        bool operator()(const T1& interval1, const T2& interval2) const
        {
            return (asStart(interval1) < asStart(interval2));
        }
    };

private:

    vector<Interval> result;
};
