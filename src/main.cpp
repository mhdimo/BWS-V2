#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "DateUtils.cpp" // Include function for the Date calculation
#include "MathUtils.cpp" // Include mathematical functions for the BWS-V2
#include "Player.cpp" // Include player Class
#include "Parser.cpp" // Include functions and business logic for data parsing
#include "Date.cpp" // Include Date class implementation

int main() {
    std::string filename = "player_data.txt"; // Nome del file dei dati giocatori

    try {
        std::vector<Player> players = parsePlayerData(filename);

        for (Player& player : players) {
            std::vector<Date> arrayN1, arrayN2, arrayN3;
            splitDateArrays(player.getBadgeDates(), arrayN1, arrayN2, arrayN3);

            int sizeofArrayN1 = arrayN1.size();
            int sizeofArrayN2 = arrayN2.size();
            int sizeofArrayN3 = arrayN3.size();

            double long bwsRank = calculateBWSrank(player.getActualRank(), player.getNumBadges(), sizeofArrayN1, sizeofArrayN2, sizeofArrayN3);

            player.setBWSRank(bwsRank);
        }

        std::ofstream outputFile("results.txt");
        if (!outputFile.is_open()) {
            std::cerr << "Impossibile creare il file di output!" << std::endl;
            return 1;
        }

        for (const auto& player : players) {
            outputFile << "Username: " << player.getUsername() << std::endl;
            outputFile << "New BWS Rank: " << player.getBWSRank() << std::endl;
            
            outputFile << std::endl;
        }
        std::cout<<"Data Parsed! Have fun screening =)"<<std::endl;
        outputFile.close();
    } catch (const std::exception& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
