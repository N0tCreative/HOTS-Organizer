#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

enum role : unsigned char {Tank=0, Bruiser, Ranged_Assassin, Melee_Assassin, Healer, Support}; //class of hero
enum universe : unsigned char {Warcraft=0, StarCraft, Diablo, Overwatch, Nexus}; //heros original game

//contains attributes of the heros
struct hero {
    public:
        string heroName;
        role heroRole;
        universe heroUni;
        bool mage; //main source of dps comes from abilities
        bool burst; //damage comes in short bursts
        bool sustain; //ability to remain in combat for long periods of time (combination of mana efficiency and self heal)
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
};

//for converting bools to human readable text (taken from stack overflow) TODO: remove after testing is done
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
                                                    {"ne", universe::Nexus}
                                                    };
    string temp;
    string roles[] = {"Tank", "Bruiser", "Ranged Assassin", "Melee Assassin", "Healer", "Support"}; //used to convert enum back into string
    string universes[] = {"Warcraft", "StarCraft", "Diablo", "Overwatch", "Nexus"};//used to convert enum back into string
    hero tmp_hero; //test hero
    ifstream heroList;
    unordered_map<string, hero> heroFinder;
    hero returnHero;

    //open text file with values in it
    heroList.open("heroList.txt");
    if(!heroList.is_open()) {
        cout << "heroList.txt failed to open please check your file";
        return -1;
    }

    //start of getting data from text file
    //getting heros name
    while (getline(heroList, temp)) {
        tmp_hero.heroName =temp;
        //getting heros role then trimming it and converting to enum
        getline(heroList, temp);
        temp.erase(temp.begin(), temp.begin() + temp.find_first_not_of(" \n\r\t"));
        tmp_hero.heroRole = roleConverter.find(temp)->second;
        //getting heros universe then trimming it and converting to enum
        getline(heroList, temp);
        temp.erase(temp.begin(), temp.begin() + temp.find_first_not_of(" \n\r\t"));
        tmp_hero.heroUni = uniConverter.find(temp)->second;
        //getting if hero is a mage
        getline(heroList, temp);
        temp.erase(temp.begin(), temp.begin() + temp.find_first_not_of(" \n\r\t"));
        tmp_hero.mage =("true" == temp || "True" == temp);
        //getting if hero is burst damage/healing
        getline(heroList, temp);
        temp.erase(temp.begin(), temp.begin() + temp.find_first_not_of(" \n\r\t"));
        tmp_hero.burst =("true" == temp || "True" == temp);
        //getting if hero has sustain
        getline(heroList, temp);
        temp.erase(temp.begin(), temp.begin() + temp.find_first_not_of(" \n\r\t"));
        tmp_hero.sustain =("true" == temp || "True" == temp);

        heroFinder.insert({tmp_hero.heroName, tmp_hero});
    }
    heroList.close();
    //end of getting data from text file

    returnHero = heroFinder.at("Alarak");
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    //cout << tmp_hero.heroName + "\n";
    //cout << roles[tmp_hero.heroRole] + "\n";
    //cout << universes[tmp_hero.heroUni] + "\n";
    //cout << boolToString(tmp_hero.mage) + "\n";
    //cout << boolToString(tmp_hero.burst) + "\n";
    //cout << boolToString(tmp_hero.sustain) + "\n";

    cout << returnHero.heroName + "\n";
    cout << roles[returnHero.heroRole] + "\n";
    cout << universes[returnHero.heroUni] + "\n";
    cout << boolToString(returnHero.mage) + "\n";
    cout << boolToString(returnHero.burst) + "\n";
    cout << boolToString(returnHero.sustain) + "\n";
    
    return 0;
}