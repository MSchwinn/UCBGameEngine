//
// Created by admin on 12.04.2018.
//

#include "Window.h"


ucb::Window::Window( )
{
    ucb::Window::Initialize( "Kein Titel", sf::Vector2u( 800, 600 ));
}

ucb::Window::Window( const std::string &p_title, const sf::Vector2u &p_size )
{
    ucb::Window::Initialize( p_title, p_size );
}

ucb::Window::Window( const std::string &p_title, const int p_sizeX, const int p_sizeY )
{
    ucb::Window::Initialize( p_title, sf::Vector2u( p_sizeX, p_sizeY ));
}

void ucb::Window::Initialize( const std::string &p_title, const sf::Vector2u &p_size )
{
    m_title = p_title;
    m_size = p_size;
    m_isFullscreen = false;
    ucb::Window::Create( );
    m_isOpen = true;
}

void ucb::Window::Create( )
{
    sf::Uint32 style = m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default;
    m_window.create( sf::VideoMode( m_size.x, m_size.y ), m_title, style );
}

void ucb::Window::Destroy( )
{
    m_window.close( );
}

void ucb::Window::BeginDraw( )
{
    m_window.clear( sf::Color::Black );
}

void ucb::Window::Draw( sf::Drawable &p_object )
{
    m_window.draw( p_object );
}

void ucb::Window::EndDraw( )
{
    m_window.display( );
}

void ucb::Window::Update( )
{
    sf::Event event;
    while ( m_window.pollEvent( event ))
    {
        if ( event.type == sf::Event::Closed )
        {
            m_isOpen = false;
            ucb::Window::Destroy( );
        }
    }
}

void ucb::Window::ToggleFullScreen( )
{
    m_isFullscreen = !m_isFullscreen;
    ucb::Window::Destroy( );
    ucb::Window::Create( );
}

bool ucb::Window::isOpen( )
{
    return m_isOpen;
}

sf::Vector2u ucb::Window::GetWindowSize( )
{
    return m_size;
}

bool ucb::Window::isFullscreen( )
{
    return m_isFullscreen;
}

ucb::Window::~Window( )
{
    ucb::Window::Destroy( );
}

