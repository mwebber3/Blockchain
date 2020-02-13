#include <iostream>
#include <cstdint>

class Block {
    public:
        std::string previousHash;
        Block(uint32_t indexIn, const std::string &dataIn);
        std::string GetHash();
        void MineBlock(uint32_t difficulty);

    private:
        uint32_t privateIndex;
        int64_t privateNonce;
        std::string privateData;
        std::string privateHash;
        time_t privateTime;
        std::string CalculateHash() const;  // const ensures the method cannot change any of the variables in the block class
};