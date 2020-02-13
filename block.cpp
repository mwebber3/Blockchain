#include <ctime>
#include "block.h"
#include "sha256.h"

Block::Block(uint32_t indexIn, const std::string &dataIn) : privateIndex(indexIn), privateData(dataIn) {
    privateNonce = -1;
    privateTime = time(nullptr);
}

std::string Block::GetHash() {
    return privateHash;
}

void Block::MineBlock(uint32_t difficulty) {
    char cstr[difficulty + 1];
    for (uint32_t i = 0; i < difficulty; i++) {
        cstr[i] = '0';
    }
    cstr[difficulty] = '\0';
    std::string str(cstr);

    do {
        privateNonce = (privateNonce + 1);
        privateHash = CalculateHash();
    } while (privateHash.substr(0, difficulty) != str);

    std::cout << "Block Mined: " << privateHash << std::endl;
}