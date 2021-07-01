#include <iostream>
#include <fstream>

enum role {Tank, Bruiser, Ranged_Assassin, Melee_Assassin, Healer, Support}; //class of hero
enum universe {Warcraft, StarCraft, Diablo, Overwatch, Nexus}; //heros original game

//contains aspects of the heros
class hero {
    public:
        role heroRole;
        universe heroUni;
};

int main() {
    std::cout << "hello";
    return 0;
}