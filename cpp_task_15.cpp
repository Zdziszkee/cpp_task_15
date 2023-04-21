#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "sha256.h"

#define MAX_NONCE 100000000000

std::string mine(int block_number, const std::string& transactions, const std::string& previous_hash, int prefix_zeros)
{
    std::cout << "Start mining:\tDificulty: " << prefix_zeros << std::endl;
    SHA256 sha256;
    std::string prefix_str(prefix_zeros, '0');
    std::string new_hash;

    for (int nonce = 0; nonce < MAX_NONCE; nonce++)
    {
        std::string text = std::to_string(block_number) + transactions + previous_hash + std::to_string(nonce);
        new_hash = sha256(text);
        if (new_hash.substr(0, prefix_zeros) == prefix_str)
        {
            std::cout << "Successfully mined bitcoins with nonce value: " << nonce << std::endl;
            return new_hash;
        }
    }

    std::cout << "Could not find correct hash after trying " << MAX_NONCE << " times" << std::endl;

    return "";
}
int main() {
    std::string transa[5] =
            {
                    "'''Dhaval->Bhavin->20\nMando->Cara->45'''",
                    "'''Sarvesh->Prem->11\nIsha->Madhuri->21'''",
                    "'''Abhishek->Rati->43\nNiraj->Dipa->87'''",
                    "'''Manan->Mitra->36\nDarsh->Vijaya->18'''",
                    "'''Amit->Pallav->39\nAadesh->Latika->13'''",
            };
    int dificulty = 2;

    std::string hash_succ = "0000000xa036944e29568d0cff17edbe038f81208fecf9a66be9a2b8321c6ec7";
    std::string hash;
    for (int i = 0; i < 5; i++)
    {
        auto time_s = std::chrono::high_resolution_clock::now();
        hash = mine(5, transa[i], hash_succ, dificulty+i);
        auto time_e = std::chrono::high_resolution_clock::now();

        std::cout << (!hash.empty() ? hash + "\n" : "");
        if (!hash.empty())
            hash_succ = hash;

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(time_e - time_s);
        std::cout << "Time: " << duration.count() << "ms" << std::endl << std::endl;
    }
}
