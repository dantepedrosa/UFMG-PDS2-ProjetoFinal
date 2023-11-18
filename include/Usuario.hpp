//TODO - Incluir colaborações
#pragma once
#include <string>

class Usuario {
public:
// TODO - Incluir métodos de usuário
Usuario(const std::string &nome, const std::string senha, const std::string tipoUsuario);

private:
// TODO - Incluir atributos de usuário
const std::string nome;
const std::string senha;
const std::string tipoUsuario;
};
