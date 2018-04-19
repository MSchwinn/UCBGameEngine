#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Window.h"

namespace ucb
{
    /// Hauptklasse zur Repräsentation eines Spieles
    class Game
    {
      public:
        Game( );
        Game( int width, int height, sf::String title );
        ~Game( );

        void run( );

      private:
        /// Verarbeitet Eingabe innerhalb der Spieleschleife
        void HandleInput( );

        /// Aktualisiert die Weltdaten
        /// \param dt die vergangene Zeit seit dem letzten Frame (aktuell fixed 60 FPS also 0.16 s)
        void Update( sf::Time dt );

        /// Render die Spielewelt
        void Render( );

      private:
        ucb::Window m_window;
        sf::Clock _updateTimer, _frameTimer;
        int _frameCounter = 0, _updateCounter = 0;
        const sf::Time _frameTime = sf::seconds( 1.0f / 60.0f );
        sf::Time _elapsedTime = sf::Time::Zero;

    };
}


