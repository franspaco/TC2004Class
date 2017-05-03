//
// Created by franspaco on 3/05/17.
//

#ifndef EVALUACIONFINAL_GAMEASSETS_H
#define EVALUACIONFINAL_GAMEASSETS_H

#include <iostream>
#include <vector>

class ExplorationShip;
class ColonizationShip;
class ObservationShip;
class StonyMeteorite;
class IronMeteorite;
class DesertPlanet;
class EarthAnalog;

class GameAsset {
protected:
    std::string name;
public:
    // Visited
    virtual void accept(GameAsset*) = 0;

    // Visitor
    virtual void visit(GameAsset* i) = 0;
    void print(){
        std::cout << name << std::endl;
    }

    std::string getName(){
        return name;
    }

};

/*
 * #####################################################################################################################
 * # # # # # # # # # # # # # # # # # # # # # # # # # # SPACECRAFTS # # # # # # # # # # # # # # # # # # # # # # # # # # #
 */
class SpaceCraft : public GameAsset {

};

class ExplorationShip : public SpaceCraft {
public:
    ExplorationShip(int index){
        name = "Exploration Ship " + std::to_string(index);
    }
    void accept(GameAsset* v) {
        v->visit(this);
    }
    void visit(GameAsset* i){
        if(this == i) return;
        std::cout << i->getName() << " collided with " << name << std::endl;
    }
};

class ColonizationShip : public SpaceCraft {
public:
    ColonizationShip(int index) {
        name = "Colonization Ship " + std::to_string(index);
    }
    void accept(GameAsset* v) {
        v->visit(this);
    }
    void visit(GameAsset* i){
        if(this == i) return;
        std::cout << i->getName() << " collided with " << name << std::endl;
    }
};

class ObservationShip : public SpaceCraft {
public:
    ObservationShip(int index) {
        name = "Observation Ship " + std::to_string(index);
    }
    void accept(GameAsset* v) {
        v->visit(this);
    }
    void visit(GameAsset* i){
        if(this == i) return;
        std::cout << i->getName() << " collided with " << name << std::endl;
    }
};

/*
 * #####################################################################################################################
 * # # # # # # # # # # # # # # # # # # # # # # # # # #  ASTEROIDS  # # # # # # # # # # # # # # # # # # # # # # # # # # #
 */
class Asteroid : public GameAsset {

};

class StonyMeteorite : public Asteroid {
public:
    StonyMeteorite(int index) {
        name = "Stony Meteorite " + std::to_string(index);
    }
    void accept(GameAsset* v) {
        v->visit(this);
    }
    void visit(GameAsset* i){
        if(this == i) return;
        std::cout << i->getName() << " collided with " << name << std::endl;
    }
};

class IronMeteorite : public Asteroid {
public:
    IronMeteorite(int index) {
        name = "Iron Meteorites " + std::to_string(index);
    }
    void accept(GameAsset* v) {
        v->visit(this);
    }
    void visit(GameAsset* i){
        if(this == i) return;
        std::cout << i->getName() << " collided with " << name << std::endl;
    }
};

/*
 * #####################################################################################################################
 * # # # # # # # # # # # # # # # # # # # # # # # # # #  ASTEROIDS  # # # # # # # # # # # # # # # # # # # # # # # # # # #
 */
class Planet : public GameAsset {

};

class DesertPlanet : public Planet  {
public:
    DesertPlanet(int index) {
        name = "Desert Planet " + std::to_string(index);
    }
    void accept(GameAsset* v) {
        v->visit(this);
    }
    void visit(GameAsset* i){
        if(this == i) return;
        std::cout << i->getName() << " collided with " << name << std::endl;
    }
};

class EarthAnalog : public Planet  {
public:
    EarthAnalog(int index) {
        name = "Earth Analog " + std::to_string(index);
    }
    void accept(GameAsset* v) {
        v->visit(this);
    }
    void visit(GameAsset* i){
        if(this == i) return;
        std::cout << i->getName() << " collided with " << name << std::endl;
    }
};

/*
 * #####################################################################################################################
 * # # # # # # # # # # # # # # # # # # # # # # # #  NEW ASSETS HERE !!  # # # # # # # # # # # # # # # # # # # # # # # #
 * Follow the tamplate:
 *
 * class <name> : public <type Spacecraft/Meteorite/Planet>  {
 * public:
 *   <name>() {
 *     name = "<name>";
 *   }
 *   void accept(GameAsset* v) {
 *     v->visit(this);
 *   }
 *   void visit(GameAsset* i){
 *     if(this == i) return;
 *     std::cout << i->getName() << " collided with " << name << std::endl;
 *   }
 * };
 *
 */



/*
 * #####################################################################################################################
 * # # # # # # # # # # # # # # # # # # # # # # # # #  Asset Manager  # # # # # # # # # # # # # # # # # # # # # # # # # #
 * <<Singleton>>
 */
class AssetManager {
private:
    AssetManager(){}
    AssetManager(AssetManager const&);

    std::vector<GameAsset *> list;

public:
    ~AssetManager(){
        while(!list.empty()){
            GameAsset* temp = list.back();
            list.pop_back();
            delete temp;
        }
    }

    static AssetManager* getInstance() {
        static AssetManager instance;
        return &instance;
    }

    template <class T>
    GameAsset * createAsset() {
        T * t =  new T(list.size());
        list.push_back(t);
        return t;
    }

    template <class T>
    T & createAssetTyped() {
        T * t =  new T(list.size());
        list.push_back(t);
        return *t;
    }
};


#endif //EVALUACIONFINAL_GAMEASSETS_H
