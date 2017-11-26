/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: victor
 *
 * Created on 25 de noviembre de 2017, 22:53
 */

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <SFML/Window/Event.hpp>
#include <iostream>

using namespace std;

/*
 * 
 */
#define kVel 8
#define kWinX 1300
#define kWinY 680

int main(int argc, char** argv)
{
    //--------------DEFINITIONS----------------------------
    
    int mouseDelta = 0;
    int mouseDeltaAux = 0;
    int estado=0;//estado de menuç
    bool cambio=false;
    bool muestraMarca = false;
    
    
    
    //-----------------------------------------------------------
   
    sf::RenderWindow window(sf::VideoMode(kWinX, kWinY), "hibuddyAPP");
    
    //-------------ZOOM TEXTURES-------------------------
    sf::Texture tZoom1;
    if (!tZoom1.loadFromFile("assets/zoom1.png"))
    {
        // error...
    }
    
    sf::Texture tZoom2;
    if (!tZoom2.loadFromFile("assets/zoom2.png"))
    {
        // error...
    }
    
    sf::Texture tZoom3;
    if (!tZoom3.loadFromFile("assets/zoom3.png"))
    {
        // error...
    }
    
    sf::Texture tZoom4;
    if (!tZoom4.loadFromFile("assets/zoom4.png"))
    {
        // error...
    }
    
    sf::Texture tZoom5;
    if (!tZoom5.loadFromFile("assets/zoom5.png"))
    {
        // error...
    }
    
    sf::Texture zoomTexture[5] = {tZoom1, tZoom2,tZoom3,tZoom4,tZoom5 };
    
    
    //--------------SPRITE ZOOM-----------------------------
    
    sf::Sprite sMap;
    sMap.setTexture(tZoom1);
    sMap.setOrigin(sMap.getTexture()->getSize().x/2, sMap.getTexture()->getSize().y/2);
    sMap.setPosition(kWinX/2 + 50, kWinY/2);
    
    //------------------------------------------------------
    
    
    //ahora cargo texturas
    
    
    
    
    
    sf::Texture tBotonMenu;
    if (!tBotonMenu.loadFromFile("assets/boton.png"))
    {
        // error...
    }
    sf::Sprite sBotonMenu;
    sBotonMenu.setTexture(tBotonMenu);
    sBotonMenu.setPosition(kWinX/2-115, kWinY/2-187);
    
    sf::Texture tFlecha;
    if (!tFlecha.loadFromFile("assets/flecha.png"))
    {
        // error...
    }
    sf::Sprite sFlecha;
    sFlecha.setTexture(tFlecha);
    sFlecha.setPosition((kWinX/2)-120, (kWinY/2)-197);
    
    
    //-----------------------------------------------------------

    
    /*sf::Texture tMira;
    if (!tMira.loadFromFile("assets/mira.png"))
    {
        // error...
    }
    sf::Sprite sMira;
    tMira.setSmooth(true);
    sMira.setTexture(tMira);
    sMira.setOrigin(9/2,9/2);
    sMira.setPosition(kWinX/2, (kWinY/2)+20);*/
    
    sf::Texture tMarco;
    if (!tMarco.loadFromFile("assets/Marco-con foto.png"))
    {
        // error...
    }
    sf::Sprite sMarco;
    sMarco.setTexture(tMarco);
    sMarco.setOrigin(sMarco.getTexture()->getSize().x/2, sMarco.getTexture()->getSize().y/2 );
    sMarco.setPosition(kWinX/2, kWinY/2);
    
    
    sf::Texture tDesplegable;
    if (!tDesplegable.loadFromFile("assets/desplegableperfil.png"))
    {
        // error...
    }
    sf::Sprite sDesplegable;
    sDesplegable.setTexture(tDesplegable);
    sDesplegable.setOrigin(sDesplegable.getTexture()->getSize().x/2, sDesplegable.getTexture()->getSize().y/2 );
    sDesplegable.setPosition(kWinX/2, kWinY/2);
    
    
    sf::Texture tLista;
    if (!tLista.loadFromFile("assets/lista-600.png"))
    {
        // error...
    }
    sf::Sprite sLista;
    sLista.setTexture(tLista);
    sLista.setOrigin(sLista.getTexture()->getSize().x/2, sLista.getTexture()->getSize().y/2 );
    sLista.setPosition(kWinX/2, kWinY/2);
    
    
    sf::Texture tPerfil;
    if (!tPerfil.loadFromFile("assets/Perfil.png"))
    {
        // error...
    }
    sf::Sprite sPerfil;
    sPerfil.setTexture(tPerfil);
    sPerfil.setOrigin(sPerfil.getTexture()->getSize().x/2, sPerfil.getTexture()->getSize().y/2 );
    sPerfil.setPosition(kWinX/2, kWinY/2);
    
    sf::Texture tMarca;
    if (!tMarca.loadFromFile("assets/marca_roja.png"))
    {
        // error...
    }
    sf::Sprite sMarca;
    sMarca.setTexture(tMarca);
    //sMarca.setOrigin(sMarca.getTexture()->getSize().x/2, sMarca.getTexture()->getSize().y/2 );
    sMarca.setPosition(kWinX/2-35, kWinY/2-40);
    

    sf::Texture tFondo;
    if (!tFondo.loadFromFile("assets/fondo.png"))
    {
        // error...
    }
    sf::Sprite sFondo;
    sFondo.setTexture(tFondo);
    sFondo.setOrigin(sFondo.getTexture()->getSize().x/2, sFondo.getTexture()->getSize().y/2 );
    sFondo.setPosition(kWinX/2, kWinY/2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            cambio=false;
            //--------------------------------------------
            
            if(estado==0){//si esta en el menu
                if (event.type == sf::Event::MouseWheelMoved)
            {
                mouseDeltaAux += event.mouseWheel.delta;
                if(( mouseDeltaAux < 0 && mouseDelta == 0 ) || ( mouseDeltaAux > 0 && mouseDelta == 4 )){
                         
                } else{
                    mouseDelta += mouseDeltaAux;
                    
                    //if(mouseDeltaAux<){
                        
                    //}
                    
                }
                mouseDeltaAux= 0;
                //sMap.setOrigin(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
                sMap.setTexture(zoomTexture[mouseDelta]);
                
                         
            }
                
                if(mouseDelta == 4){
                    sf::Vector2i mm = sf::Mouse::getPosition(window);
                    if(mm.x>sMarca.getPosition().x && mm.x<sMarca.getPosition().x+sMarca.getTexture()->getSize().x && mm.y>sMarca.getPosition().y && mm.y<sMarca.getPosition().y+sMarca.getTexture()->getSize().y){
                        muestraMarca = true;
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                            estado = 2;
                        }
                    }else{
                        muestraMarca = false;
                    }
                }
                
                
                
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    sf::Vector2i mp = sf::Mouse::getPosition(window);
                   
                    if(mp.x>(kWinX/2)-115 && mp.x<(kWinX/2)-115+sFlecha.getTexture()->getSize().x && mp.y>(kWinY/2)-187 && mp.y<(kWinY/2)-187+sFlecha.getTexture()->getSize().y){

                        estado=1;//estado en que se abre menu
                        cambio=true;
                    }
                    
                }
             
                
                
                
            }
            
            
            if(cambio==false && estado==1){
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    sf::Vector2i me = sf::Mouse::getPosition(window);
                   
                    if(me.x>(kWinX/2)-115 && me.x<(kWinX/2)-115+sFlecha.getTexture()->getSize().x && me.y>(kWinY/2)-187 && me.y<(kWinY/2)-187+sFlecha.getTexture()->getSize().y){
                        estado=0;//estado en que se abre menu
                    }
                }
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                        estado=2;
                    }
            }
            
            
            if(estado==2){
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    sf::Vector2i ma = sf::Mouse::getPosition(window);
                   
                    if(ma.x>(kWinX/2)-115 && ma.x<(kWinX/2)+115 && ma.y>(kWinY/2)-40 && ma.y<(kWinY/2)){
                        estado=3;//estado en que se abre perfil
                    }
                }
            }
            
            //--------------------------------------------
            

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //----------------------------------------------------
        
         window.draw(sFondo);
        
        switch(estado){
            case 0://menu principal
                window.draw(sMap);
                window.draw(sFondo);
                window.draw(sMarco);
                window.draw(sBotonMenu);
                if(muestraMarca == true && mouseDelta == 4){
                    window.draw(sMarca);
                }
            break;
            case 1:
                window.draw(sMap);
                window.draw(sFondo);
                window.draw(sDesplegable);
                window.draw(sFlecha);
            break;
            case 2:
                window.draw(sFondo);
                window.draw(sLista);
            break;
            case 3:
                window.draw(sFondo);
                window.draw(sPerfil);
            break;
        }
        //----------------------------------------------------
        window.display();
    }

    return 0;
}

