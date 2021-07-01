#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

enum role {Tank=0, Bruiser, Ranged_Assassin, Melee_Assassin, Healer, Support}; //class of hero
enum universe {Warcraft=0, StarCraft, Diablo, Overwatch, Nexus}; //heros original game




//contains aspects of the heros
class hero {
    public:
        string heroName;
        role heroRole;
        universe heroUni;
};


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
    hero abathur; //test hero
    ifstream heroList;

    heroList.open("heroList.txt");
    if(!heroList.is_open()) {
        cout << "heroList.txt failed to open please check your file";
        return -1;
    }
    cout << "opened file correctly\n";

    //start of getting data from text file
    //getting heros name
    getline(heroList, abathur.heroName);
    //getting heros role then trimming it and converting to enum
    getline(heroList, temp);
    temp.erase(temp.begin(), temp.begin() + temp.find_first_not_of(" \n\r\t"));
    abathur.heroRole = roleConverter.find(temp)->second;
    //getting heros universe then trimming it and converting to enum
    getline(heroList, temp);
    temp.erase(temp.begin(), temp.begin() + temp.find_first_not_of(" \n\r\t"));
    abathur.heroUni = uniConverter.find(temp)->second;
    heroList.close();
    //end of getting data from text file

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << abathur.heroName +"\n";
    cout << roles[abathur.heroRole] +"\n";
    cout << universes[abathur.heroUni] +"\n";

    
    return 0;
}