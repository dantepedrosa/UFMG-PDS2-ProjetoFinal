#include "Usuario.hpp"


Usuario::Usuario(std::string nome, int senha){
    _setNome(nome);
    _senha = senha;
}

void Usuario::_setNome(std::string nome){

    // Confere o tamanho do nome
    if(nome.length() > 20) 
        throw std::invalid_argument("Nome de usuário muito longo!");
        
    // Confere se possui apenas letras
    for(auto letra : nome){
        if(!((letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <= 'z'))) 
            throw std::invalid_argument("O nome deve possuir apenas letras.");
    }

    
}

std::string Usuario::getNome(){
    return _nome;
}
