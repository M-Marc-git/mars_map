/**
 * \file window.h
 * \brief Implémentation de la fenetre en utilisant GLFW
 */ 
#ifndef RENDER_WINDOW
#define RENDER_WINDOW

typedef struct Window {
    int width;
    int height;
    void* handle;
} Window;

/**
 * \brief Ouvre une nouvelle fenetre
 * \param width largeur de la fenetre
 * \param height hauteur de la fenetre
 * \param title titre de la fenetre
 * \return nouvelle fenetre
 */ 
Window create_window(int width, int height, const char* title);

/**
 * \brief Verifi si la fenetre est ouverte, échange les tampons, vide les tampons de couleur et de profondeur
 * \param self la fenetre à tester
 * \return 1 si la fenetre est ouverte 0 sinon
 */ 
int is_window_open(const Window* self);

/**
 * \brief Détruit la fenetre
 * \param self la fenetre à détruire
 */ 
void destroy_window(Window* self);

#endif //RENDER_WINDOW
