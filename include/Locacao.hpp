//TODO - Incluir colaborações
#pragma once
#include <iostream>
#include "BancoDeDados.hpp"
#include "Usuario.hpp"
#include "Alugar.hpp"

class Locacao {
public:
// TODO - Incluir métodos de usuário
    Locacao(const Usuario &usuario, std::string &_nomeLivro, BancoDeDados &banco);

    Usuario& obterUsuario() const;
    std::string& obterNomeLivro() const;

    void alterarEstadoLivro(std::string &_isDisponivel);
    bool proibirUsuarioComLivroAtrasado();

private:
// TODO - Incluir atributos de usuário
    const Usuario &usuario;
    std::string &_nomeLivro;
    BancoDeDados& banco;
};
