#include <iostream>
#include <string>
#include "Structure.hpp"
#include "Room.hpp"
#include "Monster.hpp"
#include "Creature.hpp"

Room::Room(std::string _roomName) : Structure(){
    roomName = _roomName;
}

void Room::setId(int _room){
    room = _room;

}

void Room::setCreature(Creature _monster){
    monster = _monster;
    //std::cout<< "Room::setCreature : " << monster << std::endl;
}

std::vector<int> Room::GetPosX(){
   return posX;
}

std::vector<int> Room::GetPosY(){
   return posY;
}

int Room::GetHeight(){
   return height;
}

int Room::GetWidth(){
   return width;
}


std::string Room::toString(){
    std::string str;
    /*+ "Creature : " + monster.toString()*!!!!*/;
    str = "Room Name: " + roomName + " room: " + std::to_string(room) + "\n";

    //Print all Info, same as all print in .cpp classes    
    str += "   Visible: " + std::to_string(visible) + "\n";
    str += "   Posx: \n";

    for (int posx : posX) {
        str += "   ";
        str += std::to_string(posx) + "\n";
    }

    str += "   Posy: \n";
    for (int posy : posY) {
        str += "   ";
        str += std::to_string(posy) + "\n";
    }
    /* Not useful, but could still be accessed
    str += "   ItemIntValue: " + std::to_string(v) + "\n";
    std::string type_string{t};
    str += "   Type: " + type_string + "\n";
    str += "   Hp: " + std::to_string(Hp) + "\n";
    str += "   Hpmoves: " + std::to_string(hpMoves) + "\n";
    str += "   Maxhit: " + std::to_string(maxHit) + "\n";
    */
    str += "   Width: " + std::to_string(width) + "\n";
    str += "   Height: " + std::to_string(height) + "\n";
    //End of print all Info, same as all print in .cpp classes
    return str;
}


