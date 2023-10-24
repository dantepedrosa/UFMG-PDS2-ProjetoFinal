# Cartões CRC - Sistema de Bibliotecas

## Classes e responsabilidades

- SistemaDeBusca
  - acervo
  - buscaLivro()
  
- Acervo
  - livrosDisponíveis
  - livros
  - incluirLivro
  - excluirLivro
  - editarLivro
    
- Administração
  - incluirLivro(Livro)
  - excluirLivro(id_livro)
  - Livro buscaLivro(id_livro)
  - Consultar GRU
  - 
  - notificaUsuario(Usuário, Livro)
    
- Usuário
  - nome
  - e-mail
  - senha
  - reservaLivro()
  - consultaEmprestimo()
  - 
- Livro
  - id_livro
  - status (disponível/alugado)
  - nome
  - genero
  - autor
  - ano
  - setNome
  - setGenero
  - setAutor
  - setAno
