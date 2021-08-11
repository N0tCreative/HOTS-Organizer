#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum role {Tank=0, Bruiser, Ranged_Assassin, Melee_Assassin, Healer, Support}; //class of hero
enum universe {Warcraft=0, StarCraft, Diablo, Overwatch, Nexus}; //heros original game

//contains attributes of the heros
class hero {
    private:
        string heroName;
        role heroRole;
        universe heroUni;
        bool mage; //main source of dps comes from abilities
        bool burst; //damage comes in short bursts
        bool sustain; //ability to remain in combat for long periods of time (combination of mana efficiency and self heal)

    public:
    //constructor for heros that are not initialized
    hero() {
        heroName = "";
        heroRole = role::Tank;
        heroUni = universe::Warcraft;
        mage = false;
        burst = false;
        sustain = false;
    }

    hero(string newName, role newRole, universe newUniverse, bool newMage, bool newBurst, bool newSustain) {
        heroName = newName;
        heroRole = newRole;
        heroUni = newUniverse;
        mage = newMage;
        burst = newBurst;
        sustain = newSustain;
    }

    void setName(string newName) {
        heroName = newName;
    }

    string getName() {
        return heroName;
    }

    void setRole(role newRole) {
        heroRole = newRole;
    }

    role getRole() {
        return heroRole;
    }

    void setUniverse(universe newUniverse) {
        heroUni = newUniverse;
    }

    universe getUniverse() {
        return heroUni;
    }

    void setMage(bool newMage) {
        mage = newMage;
    }

    bool isMage() {
        return mage;
    }

    void setBurst(bool newBurst) {
        burst = newBurst;
    }

    bool isBurst() {
        return burst;
    }

    void setSustain(bool newSustain) {
        sustain = newSustain;
    }

    bool isSustain() {
        return sustain;
    }

};

//for converting bools to human readable text TODO: remove after testing is done
inline string boolToString(bool b)
{
  return b ? "true" : "false";
}


int main() {
    //map used to convert short form of role into enum
    unordered_map<string, role> roleConverter ={    {"tnk", role::Tank}, 
                                                    {"bru", role::Bruiser}, 
                                                    {"ras", role::Ranged_Assassin}, 
                                                    {"mas", role::Melee_Assassin},
                                                    {"hea", role::Healer},
                                                    {"sup", role::Support}
                                                    };
    //map used to convert short form of universe into enum
    unordered_map<string, universe> uniConverter ={ {"wc", universe::Warcraft}, 
                                                    {"sc", universe::StarCraft}, 
                                                    {"di", universe::Diablo}, 
                                                    {"ow", universe::Overwatch},
                                                    {"ne", universe::Nexus},
                                                    };
    string temp;
    string roles[] = {"Tank", "Bruiser", "Ranged_Assassin", "Melee_Assassin", "Healer", "Support"}; //used to convert enum back into string
    string universes[] = {"Warcraft", "StarCraft", "Diablo", "Overwatch", "Nexus"};//used to convert enum back into string
    hero tmp_hero; //test hero
    ifstream heroList;

    //open text file with values in it
    heroList.open("heroList.txt");
    if(!heroList.is_open()) {
        cout << "heroList.txt failed to open please check your file";
        return -1;
    }

    //start of getting data from text file
    //getting heros name
    getline(heroList, temp);
    tmp_hero.setName(temp);
    //getting heros role then trimming it and converting to enum
    getline(heroList, temp);
    temp.erase(temp.begin(), temp.begin() + temp.find_first_not_of(" \n\r\t"));
    tmp_hero.setRole(roleConverter.find(temp)->second);
    //getting heros universe then trimming it and converting to enum
    getline(heroList, temp);
    temp.erase(temp.begin(), temp.begin() + temp.find_first_not_of(" \n\r\t"));
    tmp_hero.setUniverse(uniConverter.find(temp)->second);
    //getting if hero is a mage
    getline(heroList, temp);
    temp.erase(temp.begin(), temp.begin() + temp.find_first_not_of(" \n\r\t"));
    tmp_hero.setMage("true" == temp || "True" == temp);
    //getting if hero is burst damage/healing
    getline(heroList, temp);
    temp.erase(temp.begin(), temp.begin() + temp.find_first_not_of(" \n\r\t"));
    tmp_hero.setBurst("true" == temp || "True" == temp);
    //getting if hero has sustain
    getline(heroList, temp);
    temp.erase(temp.begin(), temp.begin() + temp.find_first_not_of(" \n\r\t"));
    tmp_hero.setSustain("true" == temp || "True" == temp);
    heroList.close();
    //end of getting data from text file

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << tmp_hero.getName() + "\n";
    cout << roles[tmp_hero.getRole()] + "\n";
    cout << universes[tmp_hero.getUniverse()] + "\n";
    cout << boolToString(tmp_hero.isMage()) + "\n";
    cout << boolToString(tmp_hero.isBurst()) + "\n";
    cout << boolToString(tmp_hero.isSustain()) + "\n";

    
    return 0;
}