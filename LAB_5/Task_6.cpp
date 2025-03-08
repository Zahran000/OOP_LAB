#include <iostream>
using namespace std;

class Level {
public:
    string levelName;
    int difficulty;

    Level(string name, int diff) : levelName(name), difficulty(diff) {}

    void displayDetails() {
        cout << "Level Name: " << levelName << ", Difficulty: " << difficulty << endl;
    }
};

class VideoGame {
private:
    string title;
    string genre;
    Level* levels[100]; 
    int levelCount;

public:
    VideoGame(string t, string g) : title(t), genre(g), levelCount(0) {}

    ~VideoGame() {
        for (int i = 0; i < levelCount; ++i) {
            delete levels[i];
        }
    }

    void addLevel(string name, int diff) {
        if (levelCount < 100) {
            levels[levelCount++] = new Level(name, diff);
        }
    }

    void displayGameDetails() {
        cout << "Game Title: " << title << ", Genre: " << genre << endl;
        cout << "Levels:" << endl;
        for (int i = 0; i < levelCount; ++i) {
            levels[i]->displayDetails();
        }
    }
};

int main() {
    VideoGame game("Advnture Qust", "RPG");
    game.addLevel("Forestf", 1);
    game.addLevel("Cavee", 2);
    game.addLevel("Cstle", 3);

    game.displayGameDetails();

    return 0;
}
