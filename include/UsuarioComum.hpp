//TODO - Incluir colaborações
#pragma once

#include <string>
#include <map>
#include <set>
using namespace std;

struct Data{
    unsigned dia;
    unsigned mes;
    unsigned ano;
};

class Usuario {
public:
    // TODO - Incluir métodos de usuário
    
    /// @brief Construtor da classe Usuário
    /// @param nome nome de usuário (aceito apenas nomes sem espaço)
    /// @param senha senha do usuário (apenas números)
    /// @param tipoUsuario Tipo do usuário: Usuário comum, adm e bibliotecário 
    Usuario(string nome, int senha);
    
    // FIXME - bool solicitarEmprestimo(this, isbn); // Tirar dúvida se usuário pode chamar bibliotecario enviando ele mesmo

private:
    
    map<unsigned long, Data> _livrosEmprestados;
    bool _comPendencia = false;
    set<string> _grusAPagar;
    
};
