# 🎶 Frigio Music 🎶

Bem-vindo ao **Frigio Music**, um sistema de terminal inspirado no Letterboxd, mas voltado para organizar seus álbuns musicais favoritos! <br>
Obs: Esse projeto foi criado para a atividade final da matéria de Linguagem de programação |. 

No Frigio você pode: 

✅ Criar seu perfil  
✅ Escolher um Avatar  
✅ Adicionar e avaliar álbuns musicais  
✅ Adicionar uma Watchlist de álbuns que você irá ouvir depois  
✅ Remover álbuns (Avaliados e Watchlist)  
✅ Alterar as cores do seu perfil e Menu.  

---

## 📂 Estrutura do Projeto

```plaintext
FrigioMusic/
├── Executar/               
│   ├── Album.cpp
│   ├── AlbunsOuvidos.cpp
│   ├── Animacao.cpp
│   ├── Autor.cpp
│   ├── Banner.cpp
│   ├── Cores.cpp
│   ├── Estrela.cpp
│   ├── Favoritos.cpp
│   ├── FilaDeInteresse.cpp
│   ├── Menu.cpp
│   ├── Perfil.cpp
│   ├── Plataforma.cpp
│   ├── ProjetoFrigio.cpp    # Arquivo principal com main()
│   ├── Resenha.cpp 
│   └── ServicosPerfil.cpp
│
├── src/                    # Arquivos de cabeçalho (.h)
│   ├── Album.h
│   ├── AlbunsOuvidos.h
│   ├── Animacao.h
│   ├── Autor.h
│   ├── Banner.h
│   ├── Cores.h
│   ├── Estrela.h
│   ├── ExibirCapas.h
│   ├── Favoritos.h
│   ├── FilaDeInteresse.h
│   ├── Menu.h
│   ├── Perfil.h
│   ├── Plataforma.h
│   ├── Resenha.h
│   └── ServicosPerfil.h
│
├── build/                  # Objetos compilados (.o)
│   ├── Album.o
│   └── ...
│
├── Makefile                # Script de compilação 
└── FrigioMusic             # Executável final gerado
```
---

## 🛠️ Tecnologias Utilizadas

- **C++**  
- Manipulação de arquivos `.txt`  
- ANSI Escape Codes para cores no terminal  
- Vetores e Structs  

Compatível com sistemas **Linux**, **MacOS**, ou **Windows com suporte a ANSI Escape Codes**.

---

## 🚀 Como Executar

1. Para rodar:
   ```bash
   g++ main.cpp -o frigiomusic
   ./frigiomusic


2. Clone o repositório:
```bash
git clone https://github.com/Tales066/letterboxd-musical.git
cd letterboxd-musical



