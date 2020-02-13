#include "blockchain.h"

// constructor 
Blockchain::Blockchain() {
    chain.emplace_back(Block(0, "Genesis Block"));
    difficulty = 6;
}

// adding a block to the blockchain 
void Blockchain::AddBlock(Block newBlock) {
    newBlock.previousHash = GetLastBlock().GetHash();
    newBlock.MineBlock(difficulty);
    chain.push_back(newBlock);
}