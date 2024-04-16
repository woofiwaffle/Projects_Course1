#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



void processMoves(string moves, vector<string>& whiteMoves, vector<string>& blackMoves) {
    size_t pos = 0;
    std::string token;
    std::string delimiter = " ";
    bool isWhite = true;
    while((pos = moves.find(delimiter)) != string::npos){
        token = moves.substr(0, pos);
        if(token.find('.') != string::npos){
            isWhite = true;
        }
        else{
            if(isWhite){
                whiteMoves.push_back(token);
            }
            else{
                blackMoves.push_back(token);
            }
            isWhite = !isWhite;
        }
        moves.erase(0, pos + delimiter.length());
    }
    if(!moves.empty()){
        if(isWhite){
            whiteMoves.push_back(moves);
        }
        else{
            blackMoves.push_back(moves);
        }
    }
}



void writeToFile(const vector<string>& whiteMoves, const vector<string>& blackMoves) {
    ofstream outFile("C:\\Users\\User\\CLionProjects\\practical1sem1(LETI)\\Separator\\output.txt");

    if(!outFile){
        cerr << "Failed to open 'output.txt' file" << endl;
        return;
    }

    outFile << "Moves white" << endl;
    for(const auto &move : whiteMoves){
        outFile << move << std::endl;
    }

    outFile << endl << "Moves black" << endl;
    for(const auto &move : blackMoves){
        outFile << move << endl;
    }

    outFile.close();

    cout << "The moves were recorded in the 'output.txt' file." << endl;
}



int main() {
    ifstream inFile("C:\\Users\\User\\CLionProjects\\practical1sem1(LETI)\\Separator\\input.txt");

    if(!inFile){
        cerr << "Failed to open 'input.txt' file" << endl;
        return 1;
    }

    string moves;
    getline(inFile, moves);

    vector<string> whiteMoves;
    vector<string> blackMoves;

    processMoves(moves, whiteMoves, blackMoves);

    inFile.close();

    writeToFile(whiteMoves, blackMoves);

    return 0;
}