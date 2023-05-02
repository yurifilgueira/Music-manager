cmake_minimum_required(VERSION 3.22.1)
project(teste VERSION 0.1 LANGUAGES CXX )

include_directories( include )


add_executable( program
                src/application/Program.cpp
                src/entities/Artist.cpp 
                src/entities/Music.cpp 
                src/entities/Playlist.cpp
                src/entities/SystemMusics.cpp
                src/entities/SystemPlaylists.cpp)