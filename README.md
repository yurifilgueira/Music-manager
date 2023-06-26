
# Music Playlist Manager

Este é um programa simples para gerenciar playlists de músicas. Ele permite criar playlists, adicionar músicas a elas, remover músicas, reproduzir as músicas da playlist e realizar outras operações relacionadas.

## Identificação

NOME: Yuri Filgueira Tavares de Medeiros
MATRÍCULA: 20220034872
TURMA: 02

NOME: ILO BENEVIDES DE MIRANDA CAVALCANTI
MATRÍCULA: 20220065108
TURMA: 01

## Compilação e Execução

Certifique-se de ter o g++ e o CMake instalados em seu sistema antes de prosseguir.

1. No terminal, execute o comando `cmake .` para gerar os arquivos de configuração do CMake.
2. Em seguida, execute o comando `make` para compilar o programa.
3. Após a compilação bem-sucedida, execute o programa digitando `./program`.

## Guia de Uso

O programa possui um menu principal com as seguintes opções:

1. **Criar uma playlist**: Permite criar uma nova playlist.
2. **Criar uma playlist juntando duas outras**: Cria uma nova playlist combinando duas playlists existentes.
3. **Acessar uma playlist**: Permite acessar uma playlist existente e realizar operações específicas nela.
4. **Adicionar música ao sistema**: Adiciona uma nova música ao sistema, fora de qualquer playlist.
5. **Mostrar todas as músicas**: Exibe todas as músicas presentes no sistema, incluindo as de diferentes playlists.
6. **Listar playlists**: Lista todas as playlists existentes.
7. **Copiar uma playlist**: Cria uma cópia de uma playlist existente.
8. **Copiar uma playlist e adicionar uma música**: Cria uma cópia de uma playlist existente e adiciona uma nova música à cópia.
9. **Copiar uma playlist e remover uma música**: Cria uma cópia de uma playlist existente e remove uma música da cópia.
0. **Fechar o aplicativo**: Encerra a execução do programa.

Ao selecionar a opção 3 (Acessar uma playlist), você entrará no menu da playlist selecionada. Nesse menu, você terá as seguintes opções:

- **Adicionar música**: Adiciona uma música à playlist.
- **Remover música**: Remove uma música da playlist.
- **Mostrar músicas da playlist**: Exibe todas as músicas da playlist.
- **Buscar música pelo nome**: Busca uma música na playlist pelo nome.
- **Reprodutor**: Reproduz as músicas da playlist.
- **Adicionar as músicas de outra playlist a esta playlist**: Copia as músicas de outra playlist para a playlist atual.
- **Remover as músicas de outra playlist, desta playlist**: Remove as músicas de outra playlist da playlist atual.
- **Remover a última música da playlist**: Remove a última música adicionada à playlist.
- **Voltar à tela inicial**: Retorna ao menu principal.

## Limitações

- O programa não suporta a exclusão de uma música de todas as playlists ao mesmo tempo.
- Não é possível mover músicas entre playlists ou reorganizar a ordem das músicas dentro de uma playlist.