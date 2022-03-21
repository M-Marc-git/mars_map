/**
 * \file input.h
 * \brief Système d'entrés
 */ 
#ifndef EVENT_INPUT
#define EVENT_INPUT

/**
 * \brief Initialisation du système d'entrés
 */ 
void init_input();

/**
 * \brief Met le status d'une touche
 * \param key la touche dont le status doit changer
 * \param status le status à donner
 */ 
void set_key(int key, int status);

/**
 * \brief Récupère le status d'une touche
 * \param key la touche dont le status doit être récuperé
 * \return 1 si la touche est enfoncée, 0 sinon
 */ 
int get_key(int key);

#endif //EVENT_INPUT
