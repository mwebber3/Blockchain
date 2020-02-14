#include <ctime>
#include "block.h"
#include "sha256.h"

Block::Block(uint32_t indexIn, const std::string &dataIn) : privateIndex(indexIn), privateData(dataIn) {
    privateNonce = 0;
    privateTime = time(nullptr);
    publicHash = CalculateHash();
}

void Block::MineBlock(uint32_t difficulty) {
    char* cstr = new char[difficulty + 1];
    for (uint32_t i = 0; i < difficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[difficulty] = '\0';
    std::string str(cstr);

    do {
        privateNonce = (privateNonce + 1);
        publicHash = CalculateHash();
    } while (publicHash.substr(0, difficulty) != str);

    std::cout << "Block Mined: " << publicHash << std::endl;
    delete[] cstr;
}

inline std::string Block::CalculateHash() const {
    std::stringstream strStream;
    strStream << privateIndex << previousHash << privateTime << privateData << privateNonce;

    return sha256(strStream.str());
}