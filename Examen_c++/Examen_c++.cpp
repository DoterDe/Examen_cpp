#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
//using namespace std;
//using namespace std::filesystem;
//
//class FileManager {
//public:
//    static void showFile(const string& path) {
//        try {
//            if (exists(path)) {
//                for (const auto& entry : directory_iterator(path)) {
//                    cout << (entry.is_directory() ? "[DIR] " : "[FILE] ")
//                        << entry.path().filename().string() << '\n';
//                }
//            }
//            else {
//                cerr << "Path does not exist.\n";
//            }
//        }
//        catch (const filesystem_error& e) {
//            cerr << "Error: " << e.what() << '\n';
//        }
//    }
//
//    static void createFile(const string& path) {
//        ofstream file(path);
//        if (file) {
//            cout << "File created: " << path << '\n';
//        }
//        else {
//            cerr << "Failed to create file.\n";
//        }
//    }
//
//    static void createFolder(const string& path) {
//        try {
//            if (create_directory(path)) {
//                cout << "Folder created: " << path << '\n';
//            }
//            else {
//                cerr << "Failed to create folder.\n";
//            }
//        }
//        catch (const filesystem_error& e) {
//            cerr << "Error: " << e.what() << '\n';
//        }
//    }
//
//    static void deleteFile(const string& path) {
//        try {
//            if (remove_all(path) > 0) {
//                cout << "Deleted: " << path << '\n';
//            }
//            else {
//                cerr << "Failed to delete: " << path << '\n';
//            }
//        }
//        catch (const filesystem_error& e) {
//            cerr << "Error: " << e.what() << '\n';
//        }
//    }
//
//    static void renameFile(const string& oldName, const string& newName) {
//        try {
//            rename(oldName, newName);
//            cout << "Renamed to: " << newName << '\n';
//        }
//        catch (const filesystem_error& e) {
//            cerr << "Error: " << e.what() << '\n';
//        }
//    }
//
//    static void copyFile(const string& source, const string& destination) {
//        try {
//            copy(source, destination, copy_options::recursive);
//            cout << "Copied to: " << destination << '\n';
//        }
//        catch (const filesystem_error& e) {
//            cerr << "Error: " << e.what() << '\n';
//        }
//    }
//
//    static uintmax_t Size(const string& path) {
//        try {
//            if (is_regular_file(path)) {
//                return file_size(path);
//            }
//            else if (is_directory(path)) {
//                uintmax_t size = 0;
//                for (const auto& entry : recursive_directory_iterator(path)) {
//                    if (is_regular_file(entry)) {
//                        size += file_size(entry);
//                    }
//                }
//                return size;
//            }
//        }
//        catch (const filesystem_error& e) {
//            cerr << "Error: " << e.what() << '\n';
//        }
//        return 0;
//    }
//
//   
//    static void search(const string& path, const string& mask) {
//        try {
//            vector<string> results;
//            for (const auto& entry : recursive_directory_iterator(path)) {
//                if (entry.path().filename().string().find(mask) != string::npos) {
//                    results.push_back(entry.path().string());
//                }
//            }
//
//            if (!results.empty()) {
//                cout << "Found " << results.size() << " items:\n";
//                for (const auto& result : results) {
//                    cout << result << '\n';
//                }
//            }
//            else {
//                cout << "No items found matching the mask: " << mask << '\n';
//            }
//        }
//        catch (const filesystem_error& e) {
//            cerr << "Error: " << e.what() << '\n';
//        }
//    }
//};
//
//int main() {
//
//    string path;
//
//    int choice;
//
//    while (true) {
//        cout << "\nFile Manager Menu:\n"
//            << "1. Show contents\n"
//            << "2. Create file\n"
//            << "3. Create folder\n"
//            << "4. Delete item\n"
//            << "5. Rename item\n"
//            << "6. Copy item\n"
//            << "7. Calculate size\n"
//            << "8. Search by mask\n"
//            << "9. Exit\n"
//            << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Enter path: ";
//            cin >> path;
//            FileManager::showFile(path);
//            break;
//        case 2:
//            cout << "Enter file path: ";
//            cin >> path;
//            FileManager::createFile(path);
//            break;
//        case 3:
//            cout << "Enter folder path: ";
//            cin >> path;
//            FileManager::createFolder(path);
//            break;
//        case 4:
//            cout << "Enter path to delete: ";
//            cin >> path;
//            FileManager::deleteFile(path);
//            break;
//        case 5: {
//            string newName;
//            cout << "Enter current path: ";
//            cin >> path;
//            cout << "Enter new name: ";
//            cin >> newName;
//            FileManager::renameFile(path, newName);
//            break;
//        }
//        case 6: {
//            string dest;
//            cout << "Enter source path: ";
//            cin >> path;
//            cout << "Enter destination path: ";
//            cin >> dest;
//            FileManager::copyFile(path, dest);
//            break;
//        }
//        case 7:
//            cout << "Enter path to calculate size: ";
//            cin >> path;
//            cout << "Size: " << FileManager::Size(path) << " bytes\n";
//            break;
//        case 8: {
//            string mask;
//            cout << "Enter path to search in: ";
//            cin >> path;
//            cout << "Enter mask: ";
//            cin >> mask;
//            FileManager::search(path, mask);
//            break;
//        }
//        case 9:
//            cout << "Exiting...\n";
//            return 0;
//        default:
//            cout << "Invalid choice. Try again.\n";
//        }
//    }
//};



using namespace std;

class Hangman {
private:
    string secretWord;
    string guessedWord;
    int attempts;
    vector<char> guessedLetters;

public:
    Hangman(const string& word) : secretWord(word), attempts(6) {
        guessedWord = string(word.length(), '_');
    }

    void guessLetter(char letter) {
        bool found = false;

        for (size_t i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == letter) {
                guessedWord[i] = letter;
                found = true;
            }
        }

        if (!found) {
            --attempts;
        }

        guessedLetters.push_back(letter);
    }

    bool isGameOver() {
        return attempts == 0 || guessedWord == secretWord;
    }

    void display() {
        cout << "Word: " << guessedWord << endl;
        cout << "Attempts left: " << attempts << endl;
        cout << "Guessed letters: ";
        for (char c : guessedLetters) {
            cout << c << " ";
        }
        cout << endl;
    }

    bool isGuessed() const {
        return guessedWord == secretWord;
    }

    string getSecretWord() const {
        return secretWord;
    }

    int getAttempts() const {
        return attempts;
    }
};

vector<string> loadWords(const string& filename) {
    vector<string> words;
    ifstream file(filename);
    string word;

    if (file.is_open()) {
        while (getline(file, word)) {
            words.push_back(word);
        }
        file.close();
    }
    else {
        cerr << "Error opening file." << endl;
    }

    return words;
}

int main() {
    string filePath = "C:\\Users\\chila\\Downloads\\word.txt.txt";  
    vector<string> words = loadWords(filePath);

    if (words.empty()) {
        cout << "No words to guess." << endl;
        return 0;
    }

    srand(static_cast<unsigned int>(time(0)));
    string secretWord = words[rand() % words.size()];

    Hangman game(secretWord);
    game.display();

    while (!game.isGameOver()) {
        cout << "Enter a letter: ";
        char letter;
        cin >> letter;

        game.guessLetter(letter);
        game.display();
    }

    if (game.isGuessed()) {
        cout << "Congratulations! You've guessed the word: " << game.getSecretWord() << endl;
    }
    else {
        cout << "Game over! The word was: " << game.getSecretWord() << endl;
    }

    return 0;
}
