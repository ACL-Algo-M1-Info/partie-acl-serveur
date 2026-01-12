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
target_link_libraries(main PRIVATE CORE ${EXT_LIB})

## Tests

# Test serveur CPP 1
add_executable(testServeurTest ${TESTS}/testServeurTest.cpp)
target_link_libraries(testServeurTest PRIVATE CORE ${EXT_LIB})

# Test serveur CPP 2
add_executable(testServeur ${TESTS}/testServeur.cpp)
target_link_libraries(testServeur PRIVATE CORE ${EXT_LIB})

# Test ordonnancement machine CPP
add_executable(testOrdonnancementMachine ${TESTS}/testOrdonnancementMachine.cpp)
target_link_libraries(testOrdonnancementMachine PRIVATE CORE ${EXT_LIB})

# Test etat CPP
add_executable(testEtat ${TESTS}/testEtat.cpp)
target_link_libraries(testEtat PRIVATE CORE ${EXT_LIB})

# Test instance CPP
add_executable(testInstance ${TESTS}/testInstance.cpp)
target_link_libraries(testInstance PRIVATE CORE ${EXT_LIB})

# Test Jackson
add_executable(testJackson ${TESTS}/testJackson.cpp)
target_link_libraries(testJackson PRIVATE ${EXT_LIB} CORE)

# Test algorithme de programmation dynamique
add_executable(testAlgoProgDynamique ${TESTS}/testAlgoProgDynamique.cpp)
target_link_libraries(testAlgoProgDynamique PRIVATE ${EXT_LIB} CORE)

# Test Liste template (PElement)
add_executable(testPElement ${TESTS}/TestPElement.cpp)
target_link_libraries(testPElement PRIVATE CORE ${EXT_LIB})

# Test graphe
add_executable(testGrapheGeneral ${TESTS}/TestGrapheGeneral.cpp)
target_link_libraries(testGrapheGeneral PRIVATE CORE)

# Test coordonnee
add_executable(testCoordonnee ${TESTS}/TestCoordonnee.cpp)
target_link_libraries(testCoordonnee PRIVATE CORE)

# Test TSP
add_executable(testTSP ${TESTS}/TestTSP.cpp)
target_link_libraries(testTSP PRIVATE CORE)

# Test messageBase
add_executable(testMessagesServeur ${TESTS}/testMessagesServeur.cpp)
target_link_libraries(testMessagesServeur PRIVATE CORE)

# Test ChargeurTemplate
add_executable(testChargeurTemplate ${TESTS}/TestChargeurTemplate.cpp)
target_link_libraries(testChargeurTemplate PRIVATE CORE)

# Test ChargeurTemplate et TSP
add_executable(testChargeurTemplateEtTSP ${TESTS}/TestChargeurTemplateEtTSP.cpp)
target_link_libraries(testChargeurTemplateEtTSP PRIVATE CORE)

# Test parseur JSON
add_executable(testParseurJson ${TESTS}/testParseurJson.cpp)
target_link_libraries(testParseurJson PRIVATE CORE)

# Test chargeur JSON générique
add_executable(testChargeurGenerique ${TESTS}/TestChargeurGenerique.cpp)
target_link_libraries(testChargeurGenerique PRIVATE CORE)


add_executable(testGrapheVideTsp ${TESTS}/TestGrapheVideTsp.cpp)
target_link_libraries(testGrapheVideTsp PRIVATE CORE)