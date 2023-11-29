//TODO - Incluir colaborações
#pragma once
#include <string>

class Usuario {
public:
    // TODO - Incluir métodos de usuário
    
    /// @brief Construtor da classe Usuário
    /// @param nome nome de usuário (aceito apenas nomes sem espaço)
    /// @param senha senha do usuário (apenas números)
    /// @param tipoUsuario Tipo do usuário: Usuário comum, adm e bibliotecário 
    Usuario(const std::string &nome, const int senha, const std::string tipoUsuario);
    // TODO - Mudar implementação usuário e administração
private:
    // TODO - Incluir atributos de usuário
    const std::string nome;
    const int senha;
    const std::string tipoUsuario;
};
