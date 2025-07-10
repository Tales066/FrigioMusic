#include "Album.h"

    Album::Album(std::string titulo, Autor autor, int anoLancamento)
	{
		this->titulo = titulo;
		this->autor = autor;
		this->anoLancamento = anoLancamento;
	}
	Album::Album(std::string titulo, Autor autor, int anoLancamento, double nota)
	{
		this->titulo = titulo;
		this->autor = autor;
		this->anoLancamento = anoLancamento;
		this->nota = nota;

	}
		  //getters
	std::string Album::GetTitulo() const
		{
			return titulo;

		}
	std::string Album::GetAutor() const
		{
			return autor.nome;
		}
	int Album::GetAno() const
		{
			return anoLancamento;
		}
	double Album::GetNota() const
	{
		return nota;
	}
