#pragma once

#include <string>


class Usuario {
public:
    
    /// @brief Construtor da classe Usuário
    /// @param nome nome de usuário (aceito apenas nomes sem espaço)
    /// @param senha senha do usuário (apenas números)
    /// @param tipoUsuario Tipo do usuário: Usuário comum, adm e bibliotecário 
    Usuario(std::string nome, int senha);
    
private:
    
    std::string _nome;
    int _senha;
};
