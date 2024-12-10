#include <iostream>
#include <string>
#include <vector>

std::string plaintext;
std::string ciphertext;
std::string key;

//enum class letters {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};

/*void user_interface(int argc, char** argv){
    for (int i = 0; i < argc; i++){

        std::string input = argv[i];

        while ( input != "E" && input != "D"){
            if (input == "E"){}
            if (input == "D"){}
        }
    }
}*/

bool validity(const std::string &plaintext, std::string &ciphertext, std::string &key){ // makes sure keys are valid
    if (plaintext.length() % key.length() == 0 || ciphertext.length() % key.length() == 0){
        return true;
    }
    else {
        std::cout << "Invalid key length." << std::endl;
        return false;
    }
}

// std::string key_change(std::string key){
    
// }

std::string encrypt(std::string &plaintext, std::string &ciphertext, std::string &key){

    
    std::vector <std::vector <std::string>> cryptor((plaintext.length() / key.length())+1, std::vector<std::string> (key.length(), "_"));
    cryptor.resize(key.length());

    for (int i = 0; i < key.length(); i++){
        cryptor[0][i] = key[i];
    }

    int counter = 0;                                             // needs optimization to be more efficient!!!!!!!!!!!!!!!!!!
    for (int i = 1; i < cryptor.size()+1; i++){
        for (int j = 0; j < cryptor[i].size(); j++){
                cryptor[i][j] = plaintext[counter];
                counter++;
        }
    }

    


    return ciphertext;
}

//std::string decrypt(std::string ciphertext, std::string key){}

int main(/*int argc, char** argv*/){

    char input;
    std::cout << "welcome! are you encrypting (E) or decrypting (D)?" << std::endl; // to run do ./tpc enterArgc
    std::cin >> input;

    if (input == 'E'){
        std::cout << "Please enter the plain text:" << std::endl;
        std::cin >> plaintext;
        std::cout << "Now please enter the key:" << std::endl;
        std::cin >> key;

        encrypt(plaintext, ciphertext, key);
        std::cout << ciphertext << std::endl;

    }
    /*else if (input == 'D'){
        std::cout << "Please enter the cipher text:" << std::endl;
        std::cin >> ciphertext;
        std::cout << "Now please enter the key:" << std::endl;
        std::cin >> key;

        decrypt(plaintext, ciphertext, key)

    }*/
    return 0;
}