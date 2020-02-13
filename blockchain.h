#include <cstdint>
#include <vector>
#include "block.h"

class Blockchain {
    public:
        Blockchain();
        void AddBlock(Block newBlock);
        
    private:
        uint32_t difficulty;
        std::vector<Block> chain;

        Block GetLastBlock() const;
};