#ifndef USER_INCLUDED
#define USER_INCLUDED

#pragma once

#include <future>
#include "BlockChain.h"
#include "Record.h"

class Record; // Forward declaration of Record

class User : public std::enable_shared_from_this<User>{
protected:
    std::string id;
    std::string name;
    std::unique_ptr<Blockchain> personalBlockchain;
    std::vector<std::shared_ptr<User>> peers;

public:
    User(const std::string& userId, const std::string& userName);
    virtual void addPeer(std::shared_ptr<User> peer);
    virtual void receiveUpdate(const std::vector<Block>& incomingChain); // synchronize blockchain updates
    virtual void broadcastRecord(const Record& record) = 0;
    const std::string& getId() const;
    const std::string& getName() const;
    void printBlockchain() const;
    bool validateBlockchain() const;
};

#endif