#include "User.h"

    User::User(const std::string& userId, const std::string& userName) 
        : id(userId), name(userName) {
        personalBlockchain = std::make_unique<Blockchain>();
    }

    void User::addPeer(std::shared_ptr<User> peer) {
        peers.push_back(peer);
    }

    void User::receiveUpdate(const std::vector<Block>& incomingChain) {
        std::cout << name << " is receiving blockchain update" << std::endl;
        
        // Attempt to synchronize the chain
        personalBlockchain->synchronizeChain(incomingChain);
    }

    const std::string& User::getId() const { 
        return id; 
    }

    const std::string& User::getName() const { 
        return name; 
    }

    void User::printBlockchain() const {
        std::cout << name << "'s Blockchain:" << std::endl;
        personalBlockchain->printChain();
    }

    bool User::validateBlockchain() const {
        return personalBlockchain->validateBlockchain();
    }