#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

  //create window
  sf::RenderWindow window(sf::VideoMode(640,480),"First Window");

  //create rectangle to draw 
  sf::RectangleShape rect1(sf::Vector2f(128.0f,128.0f));
  rect1.setFillColor(sf::Color::White);
  rect1.setPosition(320,240);
  rect1.setOrigin(rect1.getSize().x / 2, rect1.getSize().y / 2);

  // texture
  sf::Texture npcTex;
  if(!npcTex.loadFromFile("npc.png")) {
    std::cout << "unable to load texture";
  }
  sf::Sprite npc(npcTex);
  
  sf::Vector2u size = npcTex.getSize();
  npc.setOrigin(size.x / 2, size.y / 2);
  sf::Vector2f increment(0.4f, 0.4f); 

  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed) {
        window.close();
      }
    }

    //make sprite bounce 
    if((npc.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0) || (npc.getPosition().x - (size.x / 2) < 0 && increment.x < 0)) 
    {
      increment.x = -increment.x;
    }

    if((npc.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0) || (npc.getPosition().y - (size.y / 2) < 0 && increment.y < 0)) 
    {
      increment.y = -increment.y;
    }
    npc.setPosition(npc.getPosition() + increment);
    window.clear(sf::Color::Black);
    //window.draw(rect1);
    window.draw(npc);
    window.display();
  }
}

