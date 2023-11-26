//TODO - Incluir colaborações
#pragma once
#include <string>
#include <iostream>

class Alugar {
public:
// TODO - Incluir métodos de usuário
    std::string obterEstadoLivro(Livro& livro) const;
    bool alugarLivro(Locacao &locacao, BancoDeDados &banco, Livro &livro, const Usuario &usuario);
    bool devolverLivro(Locacao &locacao, BancoDeDados &banco, Livro &livro, const Usuario &usuario);
    bool receberNotificacaoAlocacao(bool sucesso) const;
private:
// TODO - Incluir atributos de usuário

};
