//TODO - Incluir colaborações
#pragma once

#include <string>
#include <set>
using namespace std;

class Usuario {
public:
    // TODO - Incluir métodos de usuário
    
    /// @brief Construtor da classe Usuário
    /// @param nome nome de usuário (aceito apenas nomes sem espaço)
    /// @param senha senha do usuário (apenas números)
    /// @param tipoUsuario Tipo do usuário: Usuário comum, adm e bibliotecário 
    Usuario(string nome, int senha, string tipoUsuario);
    
    

    // TODO - Mudar implementação usuário e administração
private:
    // TODO - Incluir atributos de usuário
    
    /// @brief Nome do usuário
    string _nome;
    int _senha;
    string _tipoUsuario;
};
