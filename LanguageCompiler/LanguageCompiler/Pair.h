#ifndef _PAIR_H_
#define _PAIR_H_

#include <string>
#include <vector>

namespace Default{
    struct struct_pair;

    typedef struct_pair Pair;
    typedef std::vector<Pair> Pairs;
    struct struct_pair{
        std::string key;
        std::string value;
    };
}

#endif //!_PAIR_H_