cmake_minimum_required(VERSION 4.0)
project(ServeurCPP)

### VARIABLES ###

set(CMAKE_CXX_STANDARD 17)

## FILESYSTEM

# Racine
set(SRC src)

# Tests
set(TESTS tests)

### IMPORTS AUTOMATIQUES ###

# Fait une liste avec tous les .c et .h du projet.
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${SRC}/*.cpp ${SRC}/*.h)

# Exclut src/main.c.
list(REMOVE_ITEM SOURCES ${SRC}/main.cpp)

# Créé la librairie avec les fichiers obtenus.
add_library(CORE ${SOURCES})

# Ajoute le target sur la racine src
target_include_directories(CORE PUBLIC ${SRC})

### EXECUTABLES ###

## Executable Exo 5
add_executable(main ${SRC}/main.cpp)
target_link_libraries(main PRIVATE CORE)

## Tests

# Test serveur CPP
add_executable(testServeur ${TESTS}/testServeur.cpp)
target_link_libraries(testServeur PRIVATE CORE)

# Test camion CPP
add_executable(testCamion ${TESTS}/testCamion.cpp)
target_link_libraries(testCamion PRIVATE CORE)

# Test etat CPP
add_executable(testEtat ${TESTS}/testEtat.cpp)
target_link_libraries(testEtat PRIVATE CORE)

# Test instance CPP
add_executable(testInstance ${TESTS}/testInstance.cpp)
target_link_libraries(testInstance PRIVATE CORE)