//
// Created by admin on 09.01.2018.
//

#include "Game.h"

#define RADIUS 10

ucb::Game::Game( int width, int height, sf::String title )
        : m_window( title, width, height )
{

}

void ucb::Game::run( )
{
    while ( m_window.isOpen( ))
    {
        //FPS messen und Zeitmanagement
        if ( _frameTimer.getElapsedTime( ).asSeconds( ) >= 1.0 )
        {
            printf( "FPS: %d\n", _frameCounter );
            printf( "Update FPS: %d\n", _updateCounter );
            _frameTimer.restart( );
            _frameCounter = 0;
            _updateCounter = 0;
        }
        _frameCounter++;

        _elapsedTime += _updateTimer.restart( );

        //Inner Loop mit fixer Frame Rate
        while ( _elapsedTime >= _frameTime )
        {
            HandleInput( );

            Update( _frameTime );

            _updateCounter++;
            _elapsedTime -= _frameTime;
        }

        Render( );
    }

}

void ucb::Game::HandleInput( )
{

}

void ucb::Game::Update( sf::Time dt )
{
    m_window.Update( );
}

void ucb::Game::Render( )
{
    sf::CircleShape kreis( 50 );
    m_window.Draw( kreis );
}

ucb::Game::~Game( )
{

}
