#ifndef LIBBITCOIN_CONSTANTS_H
#define LIBBITCOIN_CONSTANTS_H

#include <cstdint>

#include <bitcoin/util/big_number.hpp>

namespace libbitcoin {

constexpr uint64_t block_reward = 50;

constexpr uint32_t magic_value = 0xd9b4bef9;

constexpr uint64_t max_money_recursive(uint64_t current)
{
    return (current > 0) ? 
        current + max_money_recursive(current >> 1) : 0;
}

constexpr uint64_t coin_price(uint64_t value=1)
{
    return value * 100000000;
}

constexpr uint64_t max_money()
{
    return 210000 * max_money_recursive(coin_price(block_reward));
}

const hash_digest null_hash{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

big_number max_target();

} // libbitcoin

#endif

