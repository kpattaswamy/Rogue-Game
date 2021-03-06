#ifndef DUNGEONXMLHANDLER_H_
#define DUNGEONXMLHANDLER_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
// NEED TO KNOW WHAT to INCLUDE
#include "Action.hpp"
#include "Armor.hpp"
#include "Creature.hpp"
#include "CreatureAction.hpp"
#include "CreatureActionSubClasses.hpp"
#include "Displayable.hpp"
#include "Dungeon.hpp"
#include "Item.hpp"
#include "ItemAction.hpp"
#include "ItemActionSubClasses.hpp"
#include "Magic.hpp"
#include "Monster.hpp"
#include "ObjectDisplayGrid.hpp"
#include "Passage.hpp"
#include "Player.hpp"
#include "Room.hpp"
#include "Scroll.hpp"
#include "Structure.hpp"
#include "Sword.hpp"
//
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/sax2/Attributes.hpp>

class DungeonXMLHandler : public xercesc::DefaultHandler{
private:
    int DEBUG = 1;
    int maxPassages = 0;
    int passageCount = 0;
    int maxRooms = 0;
    int roomCount = 0;
    int width;
    int topHeight;
    int bottomHeight;
    int gameHeight;

    Dungeon *crDungeon;

    std::string CLASSID = "DungeonXMLHandler";
    std::string data ;


    Displayable * displayableBeingParsed;
    Action * actionBeingParsed;


    std::vector<Action*> actionBeingParseds;
    std::vector<Displayable*> displayableBeingParseds;
    //structure
    std::vector<Room*> rooms;
    std::vector<Passage*> passages;
    //creature
    Player * player;
    std::vector<Monster*> monsters;
    //items
    std::vector<Scroll*> scrolls;
    std::vector<Armor*> armors;
    std::vector<Sword*> swords;
    //actions
    std::vector<CreatureAction*> creatureActions;
    std::vector<ItemAction*> itemActions;




    bool bVisible = false;
    bool bMaxhit = false;
    bool bHpmoves = false;
    bool bHp = false;
    bool bType = false;
    bool bItemIntValue = false;
    bool bActionIntValue = false;
    bool bActionCharValue = false;
    bool bActionMessage = false;
    bool bPosx = false;
    bool bPosy = false;
    bool bWidth = false;
    bool bHeight = false;
    //void addPassage(Passage passage);
    //void addRoom(Room room);

public:
    std::vector<Room*> getRooms();
    std::vector<Passage*> getPassages();
    DungeonXMLHandler();
    void startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes) ;
    void endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName) ;
    void fatalError(const xercesc::SAXParseException&);
    void characters(const XMLCh * const ch, const XMLSize_t length ) ;
    std::string toString();
    void addPassage(Passage passage);
    void addRoom(Room room);
    std::vector<Monster*> getMonsters();
    Player * getPlayer();
    std::vector<Scroll*> getScrolls();
    std::vector<Armor*> getArmors();
    std::vector<Sword*> getSwords();


    //code i wrote
    //int getGameHeight();
    int getWidth();
    int getTopHeight();
       
    int getGameHeight();
    int getBottomHeight();

    Dungeon * getDungeon();

};

#endif /* STUDENTXMLHANDLER_H_ */
