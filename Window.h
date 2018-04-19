//
// Created by admin on 12.04.2018.
//

#ifndef EXAMPLES_WINDOW_H
#define EXAMPLES_WINDOW_H

#include <string>
#include <SFML/System.hpp>
#include "SFML/Graphics.hpp"
#include <SFML/Graphics/Drawable.hpp>

namespace ucb
{

    class Window
    {
      public:
        Window( );

        /// Erzeugt ein neues Fenster
        /// \param p_title Der Titel des Fensters
        /// \param p_size  Die Größe des Fensters als Vektor2D
        Window( const std::string &p_title, const sf::Vector2u &p_size );

        /// Erzeugt ein neues Fenster
        /// \param p_title Der Titel des Fensters
        /// \param p_sizeX Die Breite des Fensters
        /// \param p_sizeY Die Höhe des Fensters
        Window( const std::string &p_title, const int p_sizeX, const int p_sizeY );

        ~Window( );

        /// Funktion zum Update des Fensters
        void Update( );

        /// Funktion zum Zeichnen von zeichenbaren Objekten im Fenster
        /// \param p_object Das zu zeichnende Objekt
        void Draw( sf::Drawable &p_object );

        void BeginDraw( );

        void EndDraw( );

        /// Funktion zum Wechseln zwischen Vollbild- und Fenstermodus
        void ToggleFullScreen( );

        /// Liefert die Fenstergröße zurück
        /// \return Fenstergröße als Vektor2D
        sf::Vector2u GetWindowSize( );

        /// Funktion zum Überprüfen, ob das Fenster noch offen ist
        /// \return true, falls Fenster geöffnet, sonst false
        bool isOpen( );

        /// Funktion zum Überprüfen ob Vollbildmodus aktiv ist
        /// \return true, falls Vollbildmodus aktiv
        bool isFullscreen( );

      private:
        sf::RenderWindow m_window;
        sf::Vector2u m_size;
        std::string m_title;
        bool m_isOpen;
        bool m_isFullscreen;

        void Initialize( const std::string &p_title, const sf::Vector2u &p_size );

        void Create( );

        void Destroy( );
    };

}
#endif //EXAMPLES_WINDOW_H
