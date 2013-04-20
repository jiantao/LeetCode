/*
 * =====================================================================================
 *
 *       Filename:  insert_interval.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/17/2013 11:37:34 PM
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


// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution 
{
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
    {
        vector<Interval> result;
        vector<Interval>::iterator iter;
        vector<Interval>::iterator prevIter;
        vector<Interval>::iterator tailIter;
        Interval merged(newInterval.start, newInterval.end);

        iter = lower_bound(intervals.begin(), intervals.end(), newInterval, CompareInterval());
        prevIter = iter;

        if (iter != intervals.begin())
        {
            prevIter = iter - 1;
            if (prevIter->end >= newInterval.start)
            {
                merged.start = prevIter->start;
                merged.end = prevIter->end > merged.end ? prevIter->end : merged.end;
            }
            else
                prevIter = iter;
        }

        iter = upper_bound(intervals.begin(), intervals.end(), newInterval, CompareIntervalEnd());
        tailIter = iter;

        if (iter != intervals.end())
        {
            if (tailIter->start <= newInterval.end)
            {
                merged.end = tailIter->end;
                merged.start = tailIter->start < merged.start ? tailIter->start : merged.start;
                ++tailIter;
            }
        }


        result.assign(intervals.begin(), prevIter);
        result.push_back(merged);
        result.insert(result.end(), tailIter, intervals.end());

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

        template<typename T1, typename T2>
        bool operator()(const T1& interval1, const T2& interval2) const
        {
            return asStart(interval1) < asStart(interval2);
        }
    };

    struct CompareIntervalEnd
    {
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
            return asEnd(interval1) < asEnd(interval2);
        }
    };
};
