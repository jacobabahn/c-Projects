// Name: Jacob Bahn
// Assignment number: 2
// Assignment: Word Search pt 2
// File name: wordsearch.cpp
// Date Last Modified: September 21, 2020
// Honor Statement: I have neither given nor received any unauthorized help on this assignment.
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "wordsearch.h"

// Produces an answer key for a wordsearch puzzle given a
// puzzle and a list of words to find.
// puzzle: the word search puzzle to solve
// wordlist: the list of words to find within the puzzle
// Returns a new puzzle with the extraneous letters replaced
// with periods (.), revealing the locations of the words to find


LetterMatrix find_word(int row, int col, int rowc, int colc, std::string word, const LetterMatrix& puzzle, const LetterMatrix& solution) {
    LetterMatrix copy = solution;
    if (rowc == 0 && colc == 0) {
        return solution;
    }
    for (auto letter : word) {
        try {
            if (puzzle.at(row).at(col) == letter) {
                copy.at(row).at(col) = letter;
                row += rowc;
                col += colc;
            }
            else {
                return solution;
            }
        }
        catch (std::exception& e) {
            return solution;
        }
    }
    return copy;
}

LetterMatrix determine_position(const LetterMatrix& puzzle, const LetterMatrix& solution, const std::vector<std::string>& wordlist) {
    LetterMatrix old_solution = solution;
    LetterMatrix new_solution = solution;
    bool found_word;
    std::vector<int> change = { -1, 0, 1 };
    for (auto word : wordlist){
        found_word = false;
        for (int i = 0; i < puzzle.size(); i++) {
            if (found_word) {
                break;
            }
            for (int j = 0; j < puzzle[0].size(); j++) {
                if (found_word) {
                    break;
                }
                for (auto rowc : change) {
                    if (found_word) {
                        break;
                    }
                    for (auto colc : change) {
                        new_solution = find_word(i, j, rowc, colc, word, puzzle, old_solution);
                        if (old_solution != new_solution) {
                            found_word = true;
                            old_solution = new_solution;
                            break;
                        }
                    }
                }
            }
        }
    }
    return old_solution;
}

LetterMatrix solve(const LetterMatrix& puzzle, 
                   const std::vector<std::string>& wordlist) {
    // Build an initial solution filled with periods
    LetterMatrix solution(puzzle.size(),
                          std::vector<char>(puzzle[0].size(), '.'));
    //LetterMatrix puzzles = puzzle;
    
    solution = determine_position(puzzle, solution, wordlist);

    return solution;
}



