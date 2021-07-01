#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum role {Tank, Bruiser, Ranged_Assassin, Melee_Assassin, Healer, Support}; //class of hero
enum universe {Warcraft, StarCraft, Diablo, Overwatch, Nexus}; //heros original game

//contains aspects of the heros
class hero {
    public:
        string heroName;
        role heroRole;
        universe heroUni;
};

int main() {
    ifstream heroList;
    heroList.open("heroList.txt");
    if(!heroList.is_open()) {
        cout << "heroList.txt failed to open please check your file";
        return -1;
    }
    cout << "opened file correctly";



    heroList.close();
    return 0;
}