#pragma once

#include <vector>
#include <map>

namespace akarithm
{

template <typename ValueTy>
std::vector<std::vector<ValueTy>> groupThePeople(const std::vector<ValueTy> &groupSizes)
{
    std::map<ValueTy, std::size_t> mapper;
    std::vector<std::vector<ValueTy>> result;

    for (std::size_t id = 0; id < groupSizes.size(); id++)
    {
        ValueTy x = static_cast<ValueTy>(groupSizes[id]);
        if (mapper.find(x) == mapper.end())
        {
            mapper[x] = result.size();
            result.emplace_back();
        }
        result[static_cast<ValueTy>(mapper[x])].emplace_back(static_cast<ValueTy>(id));
        if (result[mapper[x]].size() == static_cast<std::size_t>(x))
        {
            mapper.erase(x);
        }
    }
    return result;
}

} // namespace akarithm
