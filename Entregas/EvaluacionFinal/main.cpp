#include <iostream>
#include "GameAssets.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    AssetManager * am = AssetManager::getInstance();

    /*
    StonyMeteorite ga1 = am->createAssetTyped<StonyMeteorite>();
    EarthAnalog ga2 = am->createAssetTyped<EarthAnalog>();

    //Visitor* v1 = Visitor::getVisitor<PrintVisitor>();
    //Visitor* colv = Visitor::getVisitor<CollisionVisitor>();

    ga1.print();

    ga2.print();

    ga1.accept(&ga2);*/

    std::vector<GameAsset*> things;
    things.push_back(am->createAsset<ExplorationShip>());
    things.push_back(am->createAsset<ExplorationShip>());
    things.push_back(am->createAsset<ColonizationShip>());
    things.push_back(am->createAsset<ObservationShip>());
    things.push_back(am->createAsset<StonyMeteorite>());
    things.push_back(am->createAsset<IronMeteorite>());
    things.push_back(am->createAsset<DesertPlanet>());
    things.push_back(am->createAsset<EarthAnalog>());

    for (int i = 0; i < things.size(); ++i) {
        for (int j = 0; j < things.size(); ++j) {
            things[i]->accept(things[j]);
        }
    }


    return 0;
}