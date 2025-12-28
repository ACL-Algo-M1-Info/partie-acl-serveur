cmake_minimum_required(VERSION 4.0)
project(ServeurCPP)

### VARIABLES ###

set(CMAKE_CXX_STANDARD 17)

## FILESYSTEM

# Racine
set(SRC src)

# Tests
set(TESTS tests)

### LIBRAIRIES EXTERNES ###

# Threads
find_package(Threads REQUIRED)

# Liste des librairies externes à lier
set(EXT_LIB ws2_32 Threads::Threads)

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
target_link_libraries(main PRIVATE ${EXT_LIB} CORE)

## Tests

# Test serveur CPP
add_executable(testServeur ${TESTS}/testServeur.cpp)
target_link_libraries(testServeur PRIVATE ${EXT_LIB} CORE)

# Test camion CPP
add_executable(testCamion ${TESTS}/testCamion.cpp)
target_link_libraries(testCamion PRIVATE ${EXT_LIB} CORE)

# Test etat CPP
add_executable(testEtat ${TESTS}/testEtat.cpp)
target_link_libraries(testEtat PRIVATE ${EXT_LIB} CORE)

# Test instance CPP
add_executable(testInstance ${TESTS}/testInstance.cpp)
target_link_libraries(testInstance PRIVATE ${EXT_LIB} CORE)

# Test Liste template (PElement)
add_executable(testPElement ${TESTS}/TestPElement.cpp)
target_link_libraries(testPElement PRIVATE ${EXT_LIB} CORE)

# Test graphe
add_executable(testGrapheGeneral ${TESTS}/TestGrapheGeneral.cpp)
target_link_libraries(testGrapheGeneral PRIVATE CORE)

# Test coordonnee
add_executable(testCoordonnee tests/TestCoordonnee.cpp)
target_link_libraries(testCoordonnee PRIVATE CORE)

# Test Chargeur
add_executable(testChargeurJson tests/TestChargeur.cpp)
target_link_libraries(testChargeurJson PRIVATE CORE)

# Test TSP
add_executable(testTSP tests/TestTSP.cpp)
target_link_libraries(testTSP PRIVATE CORE)
