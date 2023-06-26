#include <iostream>
#include <limits>
#include <ios>
#include <List.h>
#include <Music.h>
#include <Playlist.h>
#include <SystemMusics.h>
#include <SystemPlaylists.h>
#include <fstream>
#include <cstring>

using std::cin;
using std::string;
using std::fstream;
using std::ios;

void flush()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

void addArchiveMusics()
{

}

int main()
{



//Processo de leitura do arquivo
    fstream playlists;
    string line;
    string word;

    playlists.open("playlists.txt", ios::in);

    SystemPlaylists *sp = new SystemPlaylists();
    SystemMusics *sm = new SystemMusics();
    
    
    if (playlists.is_open())
    {
        while(getline(playlists, line))
        {
            
            string str = line;
            char delimiter = ';';
            size_t playlistEnd = str.find(delimiter);
            string playlist = str.substr(0, playlistEnd);
            sp->addPlaylistToSystem(new Playlist(playlist));

            size_t start = playlistEnd + 1;
            char musicDelimiter = ',';
            size_t musicEnd = str.find(musicDelimiter, start);

            while (musicEnd != string::npos) {
                char separator = ':';
                size_t separatorPos = str.find(separator, start);

                if (separatorPos != string::npos) {
                    string music = str.substr(start, separatorPos - start);
                    string artist = str.substr(separatorPos + 1, musicEnd - separatorPos - 1);
                    Music *m = new Music(artist, music);
                    sm->addMusicToSystem(m);
                    sp->searchPlaylist(playlist)->addMusic(m);
                }

                start = musicEnd + 1;
                musicEnd = str.find(musicDelimiter, start);
            }

            char separator = ':';
            size_t separatorPos = str.find(separator, start);
            if (separatorPos != string::npos) {
                string music = str.substr(start, separatorPos - start);
                string artist = str.substr(separatorPos + 1);
                Music *m = new Music(artist, music);
                sm->addMusicToSystem(m);
                sp->searchPlaylist(playlist)->addMusic(m);
            }

        }
    }

    playlists.close();

    // sp->addPlaylistToSystem(new Playlist("PL1"));
    // sp->searchPlaylist("PL1")->addMusic(new Music("A1", "M1"));
    // sp->searchPlaylist("PL1")->addMusic(new Music("A2", "M2"));
    // sp->searchPlaylist("PL1")->addMusic(new Music("A3", "M3"));
    // sp->searchPlaylist("PL1")->addMusic(new Music("A4", "M4"));
    // sp->searchPlaylist("PL1")->addMusic(new Music("A5", "M5"));

    // sp->addPlaylistToSystem(new Playlist("PL2"));
    // sp->searchPlaylist("PL2")->addMusic(new Music("A1", "M1"));
    // sp->searchPlaylist("PL2")->addMusic(new Music("A6", "M6"));
    // sp->searchPlaylist("PL2")->addMusic(new Music("A7", "M7"));
    // sp->searchPlaylist("PL2")->addMusic(new Music("A8", "M8"));
    // sp->searchPlaylist("PL2")->addMusic(new Music("A9", "M9"));

    Playlist *p = new Playlist();
    string name;
    string nameArtist;

    int choice = -50;

    while (choice != 0)
    {
        system("clear");
        cout << "1 - Criar uma playlist" << endl;
        cout << "2 - Criar uma playlist juntando duas outras" << endl;
        cout << "3 - Acessar uma playlist" << endl;
        cout << "4 - Adicionar música ao sistema" << endl;
        cout << "5 - Mostrar todas as músicas" << endl;
        cout << "6 - Listar playlists" << endl;
        cout << "7 - Copiar uma playlist" << endl;
        cout << "8 - Copiar uma playlist e adicionar uma música" << endl;
        cout << "9 - Copiar uma playlist e remover uma música" << endl;
        cout << "0 - Fechar o aplicatvo" << endl;

        cout << "Escolha uma opção: ";
        cin >> choice;
        flush();

        switch (choice)
        {
            case 1:
            {
                system("clear");
                cout << "Defina o nome da playlist: ";
                getline(cin, name);
                sp->addPlaylistToSystem(new Playlist(name));

                cout << "Playlist criada com sucesso" << endl;

                cout << "Pressione '0' para voltar a tela inicial: ";
                int x;
                cin >> x;

                if (x == 0)
                    break;
            }
            break;
            case 2:
            {
                system("clear");

                string playlist1, playlist2;

                cout << "Digite o nome das playlists que deseja juntar:\n" << endl;
                cout << "Playlist 1: ";
                getline(cin, playlist1);

                int option = -1;
                while (sp->searchPlaylist(playlist1) == nullptr)
                {
                    option = -1;
                    cout << "Essa playlist não existe. Por favor, tente novamente ou pressione '0' para voltar ao menu principal" << endl;
                    cout << "1 - Tentar novamente" << endl;
                    cout << "0 - Voltar ao menu inicial" << endl;

                    cout << "Escolha uma opção: ";
                    cin >> option;

                    if (option == 1){
                        flush();
                        getline(cin, playlist1);
                    }
                    else {
                        break;
                    }
                }
                
                if (option == 0){
                    break;
                }

                cout << "\nPlaylist 2: ";
                getline(cin, playlist2);

                while (sp->searchPlaylist(playlist2) == nullptr)
                {
                    cout << "Essa playlist não existe. Por favor, tente novamente ou pressione '0' para voltar ao menu principal: ";
                    option = -1;
                    cout << "1 - Tentar novamente" << endl;
                    cout << "0 - Voltar ao menu inicial" << endl;

                    cout << "Escolha uma opção: ";
                    cin >> option;

                    if (option == 1){
                        flush();
                        getline(cin, playlist2);
                    }
                    else {
                        break;
                    }
                }

                if (option == 0){
                    break;
                }

                cout << "\nEscolha um nome para a nova playlist: ";
                getline(cin, name);

                sp->addPlaylistToSystem(new Playlist(name, *(*sp->searchPlaylist(playlist1) + *sp->searchPlaylist(playlist2))));//Construtor cópia e sobrecarga do operador '+'

                cout << "Playlist criada com sucesso." << endl;
                cout << "Pressione '0' para voltar a tela inicial: ";
                cin >> option;

            } 
            break;
            case 3:
            {
                system("clear");
                int choice2 = -1;
                cout << "Digite a playlist que será acessada: ";
                getline(cin, name);
                if (sp->searchPlaylist(name) != nullptr)
                {
                    p = sp->searchPlaylist(name);
                }
                else
                {
                    cout << "Playlist não encontrada ou vazia." << endl;
                    cout << "Pressione '0' para voltar a tela inicial: ";

                    int option;
                    cin >> option;
                    break;
                }
                while (choice2 != 0)
                {

                    system("clear");

                    cout << "1 - Adicionar música" << endl;
                    cout << "2 - Remover música" << endl;
                    cout << "3 - Mostrar músicas da playlist" << endl;
                    cout << "4 - Buscar música pelo nome" << endl;
                    cout << "5 - Reprodutor" << endl;
                    cout << "6 - Adicionar as músicas de outra playlist a esta playlist" << endl;
                    cout << "7 - Remover as músicas de outra playlist, desta playlist" << endl;
                    cout << "8 - Remover a última música da playlist" << endl;
                    cout << "0 - Voltar a tela inicial" << endl;

                    cout << "Escolha uma opção: ";

                    cin >> choice2;
                    flush();

                    switch (choice2)
                    {
                        case 1:
                        {
                            system("clear");

                            cout << "Digite o nome da música: ";
                            getline(cin, name);

                            cout << "\nDigite o nome do artista/banda: ";
                            getline(cin, nameArtist);

                            Music *m = new Music(nameArtist, name);
                            
                            sm->addMusicToSystem(m);
                            *p << m;//Usando a sobrecarga do operador '<<' para adicinar uma música.

                            cout << "Música adicionada com sucesso" << endl;
                            cout << "Pressione '0' para voltar ao menu da playlist: ";
                            int x;
                            cin >> x;
                        }
                        break;

                        case 2:
                        {
                            system("clear");
                            cout << "Qual música você deseja remover: ";
                            getline(cin, name);

                            p->remove(p->searchByName(name));

                            int x;
                            cout << "Música removida com sucesso" << endl;
                            cout << "Pressione '0' para voltar ao menu da playlist: ";
                            cin >> x;
                        }
                        break;

                        case 3:
                        {
                            system("clear");

                            if(p->getSize() > 0){
                                p->printMusics();
                            }
                            else
                            {
                                cout << "Não há músicas nesta playlist." << endl;
                            }

                            int x;
                            cout << "Pressione '0' para voltar ao menu da playlist: ";
                            cin >> x;
                        }
                        break;

                        case 4:
                        {
                            system("clear");

                            cout << "Digite o nome da música que será buscada: ";
                            getline(cin, name);

                            if (p->searchByName(name) != nullptr)
                            {
                                cout << "Música encontrada" << endl;
                                cout << p->searchByName(name);
                            }
                            else
                            {
                                system("clear");
                                cout << "Música não encontrada." << endl;
                            }

                            int x;
                            cout << "Pressione '0' para voltar ao menu da playlist: ";
                            cin >> x;
                        }
                        break;

                        case 5:
                        {
                            system("clear");
                            int x;
                            Music *m = p->nextMusic();
                            while (m != nullptr)
                            {
                                system("clear");
                                cout << "Reproduzindo: " << m->getName() << endl;

                                cout << "1 - Próxima" << endl;
                                cout << "0 - Voltar para o menu da playlist" << endl;
                                cout << "Escolha uma opção: ";
                                cin >> x;

                                if (x == 1)
                                {
                                    m = p->nextMusic();
                                    if (m == nullptr)
                                    {
                                        system("clear");
                                        cout << "As músicas da playlist acabaram" << endl;
                                        break;
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }

                            cout << "Pressione '0' para voltar ao menu da playlist: ";
                            cin >> x;
                        }
                        break;
                        case 6:
                        {
                            system("clear");

                            cout << "Digite o nome da playlist que contem as músicas: ";
                            getline(cin, name);

                            if (sp->searchPlaylist(name) == nullptr)
                            {
                                cout << "Playlist não encontrada" << endl;
                            }
                            else
                            {
                                p->addMusic(*sp->searchPlaylist(name));
                                cout << "Músicas adicionadas com sucesso." << endl;
                            }

                            int x;
                            cout << "Pressione '0' para voltar ao menu da playlist: ";
                            cin >> x;
                            
                        }
                        break;
                        case 7:
                        {
                            system("clear");

                            cout << "Digite o nome da playlist que contem as músicas a serem deletadas: ";
                            getline(cin, name);

                            if (sp->searchPlaylist(name) == nullptr)
                            {
                                cout << "Playlist não encontrada" << endl;
                            }
                            else
                            {
                                p->remove(*sp->searchPlaylist(name));
                                cout << "Músicas removidas com sucesso." << endl;
                            }

                            int x;
                            cout << "Pressione '0' para voltar ao menu da playlist: ";
                            cin >> x;
                            
                        }
                        case 8:
                        {   

                            system("clear");
                            Music *m = new Music();
                            *p >> *m;

                            if (m->getName() != "null")
                            {
                                cout << "Música removida com sucesso" << endl;
                                cout << "A música removida foi '" << m->getName() << "' do/da '" << m->getNameArtist() << "'." << endl;
                            }
                            else
                            {
                                cout << "A playlist está vazia. Nenhuma música foi removida." << endl;
                            }

                            int x;
                            cout << "Pressione '0' para voltar ao menu da playlist: ";
                            cin >> x;
                        }
                        break;
                        case 0:
                        {
                            break;
                        }
                    }
                }
            }
            break;
            case 4:
            {
                system("clear");

                cout << "Digite o nome da música: ";
                getline(cin, name);

                cout << "\nDigite o nome do artista/banda: ";
                getline(cin, nameArtist);

                Music *m = new Music(nameArtist, name);

                sm->addMusicToSystem(m);
                int x;
                cout << "Música adicionada com sucesso" << endl;
                cout << "Pressione '0' para voltar ao menu: ";
                cin >> x;
            }
            break;

            case 5:
            {

                system("clear");
                if (sm->getMusics()->getSize() == 0) 
                {
                    cout << "Não há músicas no sistema." << endl;
                }
                else
                {
                    sm->printSystemMusics();
                }

                int x;
                cout << "Pressione '0' para voltar ao menu: ";
                cin >> x;
            }
            break;
            case 6:
            {
                system("clear");

                if (sp->getPlaylists()->getSize() == 0) 
                {
                    cout << "Não há playlists no sistema." << endl;
                }
                else
                {
                    sp->printSystemPlaylists();
                }

                int x;
                cout << "Pressione '0' para voltar ao menu: ";
                cin >> x;
            }
            break;
            case 7:
            {
                system("clear");
                cout << "Digite o nome da playlist que será copiada: ";
                getline(cin, name);
                
                int x;
                
                if (sp->searchPlaylist(name) == nullptr){
                    cout << "Playlist não encontrada." << endl;
                }
                else {
                    cout << "Digite o nome da nova playlist: ";
                    string nameNewPlaylist;
                    getline(cin, nameNewPlaylist);

                    sp->addPlaylistToSystem(new Playlist(nameNewPlaylist, *sp->searchPlaylist(name)));

                    cout << "Playliyst criada com sucesso !" << endl;
                }
                    cout << "Pressione '0' para voltar ao menu: ";
                    cin >> x;
            }
            break;
            case 8:
            {
                system("clear");

                cout << "Digite o nome da playlist desejada: " << endl;
                getline(cin, name);

                if(sp->searchPlaylist(name) != nullptr)
                {
                    cout << "Digite o nome da nova playlist: " << endl;
                    string namePlaylist;
                    getline(cin, namePlaylist);

                    string nameMusic;
                    cout << "Digite o nome da música: ";
                    getline(cin, nameMusic);

                    cout << "\nDigite o nome do artista/banda: ";
                    getline(cin, nameArtist);

                    sp->addPlaylistToSystem(new Playlist(namePlaylist, *(*sp->searchPlaylist(name) +  new Music(nameArtist, nameMusic))));

                    cout << "Playlist criada com sucesso" << endl;

                    int x;
                    cout << "Pressione '0' para voltar ao menu: ";
                    cin >> x;

                }
            }
            break;
            case 9:
            {
                system("clear");

                cout << "Digite o nome da playlist desejada: " << endl;
                getline(cin, name);

                if(sp->searchPlaylist(name) != nullptr)
                {
                    cout << "Digite o nome da nova playlist: " << endl;
                    string namePlaylist;
                    getline(cin, namePlaylist);

                    string nameMusic;
                    cout << "Digite o nome da música: ";
                    getline(cin, nameMusic);

                    cout << "\nDigite o nome do artista/banda: ";
                    getline(cin, nameArtist);

                    sp->addPlaylistToSystem(new Playlist(namePlaylist, *(*sp->searchPlaylist(name) -  new Music(nameArtist, nameMusic))));

                    cout << "Playlist criada com sucesso" << endl;

                    int x;
                    cout << "Pressione '0' para voltar ao menu: ";
                    cin >> x;

                }
            }
            break;
        }
    }


//Processo de esrita do arquivo
    playlists.open("playlists.txt", ios::out);
    Node<Playlist *> *current = sp->getPlaylists()->getHead();

    while (current != nullptr)
    {
        playlists << current->getData()->getName() << ";";
        Node<Music *> *mscs = current->getData()->getPlaylist()->getHead();
        if (mscs == nullptr)
        {
            playlists << "\n";
        }
        while(mscs != nullptr)
        {

            if (mscs->getData()->getName() != current->getData()->getLastMusic()->getData()->getName())
            {
                playlists << mscs->getData()->getName() << ":" << mscs->getData()->getNameArtist() << ",";
            }
            else if (mscs->getData()->getName() == current->getData()->getLastMusic()->getData()->getName())
            {
                playlists << mscs->getData()->getName() << ":" << mscs->getData()->getNameArtist() << "\n";
            }

            mscs = mscs->getNext();
        }

        current = current->getNext();
    }
    

    delete p;
    delete sm;
    delete sp;

    playlists.close();

    return 0;
}