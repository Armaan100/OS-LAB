/*
Write a C++ program that includes a Config class to manage language settings for game
players. The Config class should support the following features:
1. Default Language: If a player doesn't specify a language, the class should
automatically set it to a default value and display a message.
2. Specified Language: Allow players to choose and set a specific language, with a
message confirming the selection.
3. Copy Language to Static Object: Implement a copy constructor that allows
copying the language setting from the static Config object, which represents the default
language setting, to another player. The copied language should always come from this static
object, not from any other player.
Program Requirements:
17 | Page Copyright © [2024] Author(s): Dr. Suresh Chandra Raikwar and Dr. Lokendra Vishwakarma
1. Player Count: Track the number of active players who set their language, excluding
the static reference player used only for copying languages. This static object should not be
counted as a player, so no message should be displayed when it is created.
2. Static Reference Object: Use a static Config object as a reference for copying
language settings. This static object should not trigger any output message when created and
should not be included in the active player count.
3. Static Function: Implement a static function in the Config class to display the
number of active players, excluding the static reference object.
*/

#include<iostream>
using namespace std;

class Config{
    private:
    string language;

    static int activePlayers;
    static Config defaultConfig;    //static reference object

    public:
    //Default COnstructor
    Config(){
        this->language = "Default Language";
    }

    Config(const string& lang){
        this->language = lang;
        activePlayers++;
        cout<<'Langage set to '<<this->language<<endl;
    }

    //Copy Constructor
    Config(Config& other){
        this->language = defaultConfig.language;
        activePlayers++;
        cout<<"Language copied from default "<<this->language<<endl;
    }

    //Destructor
    ~Config(){
        activePlayers--;
    }

    static void displayActivePlayers(){
        cout<<"Number of active players: "<<activePlayers<<endl;
    }

    string getLanguage() const{
        return language;
    }
};


//intitialize static members
int Config::activePlayers = 0;
Config Config::defaultConfig;

int main() {
    // Optionally, set a different default language
    // Config::setDefaultLanguage("French");

    // Creating a player with default language (no language specified)
    Config playerDefault;
    // No message should be displayed

    // Creating players with specified languages
    Config player1("Spanish"); // Should display a message
    Config player2("German");  // Should display a message

    // Creating a player by copying language from defaultConfig
    Config playerCopy(playerDefault); // Should copy from default and display a message

    // Display active players
    Config::displayActivePlayers(); // Should display 3

    return 0;
}
