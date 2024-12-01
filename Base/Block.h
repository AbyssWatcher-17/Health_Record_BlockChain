#ifndef BLOCK_INCLUDED
#define BLOCK_INCLUDED

#include <vector>
#include <functional>
#include <mutex>
#include <sstream>
#include <iomanip>
#include <utility> // For std::move
#include <iostream>
#include <openssl/sha.h>
#include <openssl/evp.h>

class  Block {
public:
    std::string previousHash;
    std::string data;  
    std::string currentHash;
    time_t timestamp;


    Block(const std::string& prevHash, const std::string& blockData);
    std::string calculateHash() const;
    bool validateIntegrity(const std::string& expectedHash) const;
  
};

#endif