#include "Block.h"



// Constructor to initialize a Block with a record and previous hash
Block::Block(const std::string& prevHash, const std::string& blockData) {
        previousHash = prevHash;
        data = blockData;
        timestamp = time(nullptr);
        currentHash = calculateHash();
}

// Calculate a simple hash for demonstration purposes
std::string Block::calculateHash() const{
        EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
        const EVP_MD* md = EVP_sha256();
        unsigned char md_value[EVP_MAX_MD_SIZE];
        unsigned int md_len;
    
        std::string toHash = previousHash + data + std::to_string(timestamp);
    
        EVP_DigestInit_ex(mdctx, md, NULL);
        EVP_DigestUpdate(mdctx, toHash.c_str(), toHash.size());
        EVP_DigestFinal_ex(mdctx, md_value, &md_len);
        EVP_MD_CTX_free(mdctx);
    
        std::stringstream ss;
        for(unsigned int i = 0; i < md_len; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)md_value[i];
        }
        return ss.str();
}

bool Block::validateIntegrity(const std::string& expectedHash) const {
        return currentHash == expectedHash;
}


