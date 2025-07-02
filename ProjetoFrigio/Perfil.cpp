#include "Perfil.h"
#include "Resenha.h"
#include "FilaDeInteresses.h"

#include <iostream>
using namespace std;

	void Perfil:: MostrarPerfil()const 
	{
        cout << "\n👤 Perfil do Usuário\n";
        cout << "Nome: " << nome << endl;

        if(1>0)//teste
        {
            cout << "\nNenhum álbum avaliado.\n";
        }
        else
        {
            cout << "\n🎵 Seus álbuns avaliados:\n";
            albunsOuvidos.listarAlbunsPorLinha(3);
        }

        if(filaDeInteresses.filaDeAlbum.empty())
        {
            cout << "\nNenhum álbum foi encontrado na sua lista de interesses.\n";
        }
        else
        {
            cout << "\n📝 Sua lista de interesses:\n";
            filaDeInteresses.ExibirFilaDeInteresses(3);
        }
    }

