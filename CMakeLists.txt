cmake_minimum_required(VERSION 3.22.1)
project(teste VERSION 0.1 LANGUAGES CXX )

include_directories( include )


add_executable( program
                application/Program.cpp
                entities/Artist.cpp 
                entities/Music.cpp 
                entities/Playlist.cpp)