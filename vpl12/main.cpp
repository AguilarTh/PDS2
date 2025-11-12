#include "avaliacao_basica_streaming.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include <map>

#include "Playlist.hpp"
#include "Catalogo.hpp"

using namespace std;

int main() {

    Catalogo Album_do_doka;
    // Tava faltando esse map, entender melhor dps
    std::map<std::string, Playlist> My_playlists;
    string line;

    while(1){
        getline(cin, line);

        if(line.empty()){
            continue;
        }

        string comando;
        stringstream ss(line);
        ss >> comando;

        if(comando == "add_musica") {
            string titulo, artista, genero;
            int duracao_s;

            ss >> titulo >> duracao_s >> artista >> genero;

            bool isOk = Album_do_doka.add_musica(titulo, duracao_s,
                                                artista, genero);
            
            if(isOk){
                cout << "OK: musica " << titulo << " adicionada" << endl;
            } else {
                cout << "Erro: titulo " << titulo << " repetido" << endl;
            }
        }

        else if(comando == "add_podcast") {
            string titulo, host;
            int duracao_s, episodio;

            ss >> titulo >> duracao_s >> host >> episodio;

            bool isOk = Album_do_doka.add_podcast(titulo, duracao_s,
                                                host, episodio);
            
            if(isOk){
                cout << "OK: podcast " << titulo << " adicionado" << endl;
            } else {
                cout << "Erro: titulo " << titulo << " repetido" << endl;
            }
        }

        else if(comando == "list_all") {
            Album_do_doka.list_all();
        }

        else if(comando == "pl_new") {
            string name;
            ss >> name;
            
            My_playlists[name] = Playlist(name); 
            
            cout << "OK: playlist " << name << " criada" << endl;
        }

        else if(comando == "pl_add") {
            string nome_playlist, titulo_midia;
            ss >> nome_playlist >> titulo_midia;

            auto resultado_do_insert = My_playlists.insert(
                std::make_pair(nome_playlist, Playlist(nome_playlist))
            );
            
            bool era_nova = resultado_do_insert.second;

            if (era_nova) {
                cout << "OK: playlist " << nome_playlist << " criada" << endl;
            }

            auto midia_ptr = Album_do_doka.get(titulo_midia);
            
            if (midia_ptr == nullptr) {
                cout << "Erro: midia " << titulo_midia << " inexistente" << endl;
                continue; 
            }

            auto it_playlist = resultado_do_insert.first;
            it_playlist->second.add(midia_ptr);
        }

        else if(comando == "pl_list") {
            string name;
            ss >> name;
            
            auto it = My_playlists.find(name);
            if (it == My_playlists.end()) {
                cout << "Erro: playlist " << name << " inexistente" << endl;
            } else {
                it->second.list(); 
            }
        }

        else if(comando == "pl_play") {
            string name;
            ss >> name;

            auto it = My_playlists.find(name);
            if (it == My_playlists.end()) {
                cout << "Erro: playlist " << name << " inexistente" << endl;
            } else {
                it->second.play_all(); 
            }
        }

        else if(comando == "play") {
            string titulo;
            ss >> titulo;

            auto midia = Album_do_doka.get(titulo);
            if (midia == nullptr) {
                cout << "Erro: midia " << titulo << " inexistente" << endl;
            } else {
                midia->play();
            }
        }

        else if(comando == "b") {
            avaliacao_basica();
        }

        else if(comando == "quit") {
            break; 
        }
    }
  
    return 0;
}