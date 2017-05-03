#include <iostream>
#include "GameAssets.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    AssetManager * am = AssetManager::getInstance();

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