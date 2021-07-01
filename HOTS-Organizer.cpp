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
    std::ifstream heroList;
    heroList.open("heroList.txt");
    if(!heroList.is_open()) {
        std::cout << "heroList.txt failed to open please check your file";
        return -1;
    }
    std::cout << "opened file correctly";
    heroList.close();
    return 0;
}