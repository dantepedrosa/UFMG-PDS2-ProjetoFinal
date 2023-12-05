#pragma once

#include <string>
#include <stdexcept>

/// @brief Classe base de usuários do sistema de biblioteca
class Usuario {
public:
    
    /// @brief Construtor da classe Usuário
    /// @param nome Nome de usuário (aceito apenas letras sem espaço). Max. 20 characteres
    /// @param senha senha do usuário (apenas números)
    Usuario(std::string nome, int senha);
    
private:

    /// @brief Setter do nome
    /// @details Gera exceção caso nome seja maior que 20 caracteres ou possua character diferente de letras.
    /// @param nome Nome de usuário
    void _setNome(std::string nome);

    
    std::string _nome;  ///< Nome do usuário (apenas letras)
    int _senha;         ///< Senha do usuário
};
