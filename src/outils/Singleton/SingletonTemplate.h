//
// Created by lucas on 22/12/2025.
//

#pragma once

/**
 * Template d'un Meyer's Singleton
 * @tparam C : classe du singleton
 */
template <class C>
class SingletonTemplate
{
   protected:
    /**
     * Constructeur par défaut du singleton
     */
    SingletonTemplate() {}

   public:
    /**
     * Méthode permettant de récupérer l'instance du singleton et de la créer si
     * elle n'existe pas
     * @return : pointeur sur l'instance du singleton
     */
    static C* getInstance();

    /**
     * Empêche la copie du singleton
     */
    SingletonTemplate(const SingletonTemplate*) = delete;

    /**
     * Empêche la copie du singleton
     */
    SingletonTemplate& operator=(const SingletonTemplate*) = delete;
};

