#ifndef BLOCKCHAIN_INCLUDED
#define BLOCKCHAIN_INCLUDED

#include "Block.h"
#include <list>

class Blockchain {
    std::vector<Block> chain;

public:
    Blockchain();

    void addBlock(const std::string& data);

    bool synchronizeChain(const std::vector<Block>& newChain);

    const std::vector<Block>& getChain() const;

    void printChain() const;

    bool validateBlockchain() const;
    
};

#endif