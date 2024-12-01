#include "BlockChain.h"


    Blockchain::Blockchain() {
        // Create genesis block
        chain.push_back(Block("0", "Genesis Block"));
    }

    void Blockchain::addBlock(const std::string& data) {
        std::string previousHash = chain.back().currentHash;
        chain.push_back(Block(previousHash, data));
    }

    bool Blockchain::synchronizeChain(const std::vector<Block>& newChain) {
        // Consensus mechanism: choose the longest valid chain
        if (newChain.size() > chain.size()) {
            // Validate the new chain
            bool isValidChain = true;

            // Verify the genesis block first
            if (newChain[0].data != "Genesis Block") {
                return false;
            }

            // Check chain integrity
            for (size_t i = 1; i < newChain.size(); ++i) {
                // Check if previous hash matches
                if (newChain[i].previousHash != newChain[i-1].currentHash) {
                    isValidChain = false;
                    break;
                }

                // Validate individual block integrity
                std::string calculatedhash = newChain[i].calculateHash();
                if (calculatedhash != newChain[i].currentHash) {
                    isValidChain = false;
                    break;
                }
            }

            // If validation passes, update the chain
            if (isValidChain) {
                chain = newChain;
                return true;
            }
        }
        return false;
    }


    const std::vector<Block>& Blockchain::getChain() const {
        return chain;
    }

    void Blockchain::printChain() const {
        for (size_t i = 0; i < chain.size(); ++i) {
            std::cout << "Block " << i 
                      << " - Data: " << chain[i].data 
                      << ", Hash: " << chain[i].currentHash 
                      << std::endl;
        }
    }

    // Validate blockchain integrity
    bool Blockchain::validateBlockchain() const {                                                          
        for (size_t i = 1; i < chain.size(); ++i) {
            // Check if previous hash matches
            if (chain[i].previousHash != chain[i-1].currentHash) {
                return false;
            }
            
            // Validate individual block integrity
            if (!chain[i].validateIntegrity(chain[i].currentHash)) {
                return false;
            }
        }
        return true;
    }