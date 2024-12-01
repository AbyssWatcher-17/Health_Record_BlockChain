cmake_minimum_required(VERSION 3.10)
project(Health_Record_Blockchain)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Create a list of all source files
set(SOURCES   
    main.cpp
    Base/Block.cpp
    Base/BlockChain.cpp
    Record.cpp
    Base/User.cpp
    Users/Doctor.cpp
    Users/Patient.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Base
    ${CMAKE_CURRENT_SOURCE_DIR}/Users
)

# Link OpenSSL libraries ,to calculateHash()
target_link_libraries(${PROJECT_NAME} 
    OpenSSL::SSL 
    OpenSSL::Crypto
)