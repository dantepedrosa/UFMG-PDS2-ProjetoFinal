//TODO - Incluir colaborações
#pragma once

#include <string>
#include <set>
using namespace std;

class Usuario {
public:
    
    /// @brief Construtor da classe Usuário
    /// @param nome nome de usuário (aceito apenas nomes sem espaço)
    /// @param senha senha do usuário (apenas números)
    /// @param tipoUsuario Tipo do usuário: Usuário comum, adm e bibliotecário 
    Usuario(string nome, int senha, string tipoUsuario);
    
private:
    
    string _nome;
    int _senha;
};
