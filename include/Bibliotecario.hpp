//TODO - Incluir colaborações
#pragma once
#include <string>
#include "BancoDeDados.hpp"

class Bibliotecario {
public:
// TODO - Incluir métodos de usuário
    void receberAlertaLivroAtrasado(BancoDeDados &banco, Locacao& locacao);
    void alterarEstadoLivro(BancoDeDados &banco, std::string &_nomeLivro, std::string &novoEstado);
    void mostrarLivrosAtrasados(BancoDeDados& banco) const;
    void mostrarUsuariosComLivrosAtrasados(BancoDeDados& banco) const;
private:
// TODO - Incluir atributos de usuário
    BancoDeDados &banco;
};
