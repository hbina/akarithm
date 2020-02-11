#pragma once

#include <string>
#include <vector>
#include <map>

namespace akarithm
{

template <
    typename StringTy = std::string,
    typename TimeTy = int,
    typename CounterTy = int>
class TweetCounts
{
    static constexpr TimeTy MINUTE = 60;
    static constexpr TimeTy HOUR = 3600;
    static constexpr TimeTy DAY = 86400;

    using TripletTy =
        typename std::tuple<
            std::map<TimeTy, CounterTy>,
            std::map<TimeTy, CounterTy>,
            std::map<TimeTy, CounterTy>>;
    using PairTy =
        typename std::pair<TimeTy, TimeTy>;

    std::map<StringTy, TripletTy> map;

    static constexpr auto
    getTimePair(
        const TimeTy &time,
        const TimeTy &divisor)
        -> PairTy
    {
        return {time / divisor, time % divisor};
    }

    void
    append(
        std::map<TimeTy, CounterTy> &map_counter,
        const PairTy &time_index)
    {
        if (time_index.second == 0)
        {
            map_counter[time_index.first - 1]++;
        }
        else
        {
            map_counter[time_index.first]++;
        }
    }

public:
    constexpr TweetCounts() = default;

    void
    recordTweet(
        const StringTy &tweetName,
        const TimeTy &time)
    {
        PairTy minute_index = getTimePair(time, MINUTE);
        PairTy hour_index = getTimePair(time, HOUR);
        PairTy day_index = getTimePair(time, DAY);

        append(std::get<0>(map[tweetName]), minute_index);
        append(std::get<1>(map[tweetName]), hour_index);
        append(std::get<2>(map[tweetName]), day_index);
        return;
    }

    constexpr auto
    getTweetCountsPerFrequency(
        const StringTy &freq,
        const StringTy &tweetName,
        const TimeTy &startTime,
        const TimeTy &endTime)
        -> std::vector<TimeTy>
    {
        if (freq == "minute")
        {
            PairTy begin = getTimePair(startTime, MINUTE);
            PairTy end = getTimePair(endTime, MINUTE);
            return {};
        }
        else if (freq == "hour")
        {
            return {};
        }
        else if (freq == "day")
        {
            return {};
        }
        else
        {
            return {};
        }
    }
};

} // namespace akarithm
