#include <iostream>
#include <vector>
#include <windows.h>

void drawBoard(const std::vector<char>& board) {
    std::cout << "\n";
    std::cout << " " << board[0] << " ┃ " << board[1] << " ┃ " << board[2] << " \n";
    std::cout << "━━━╋━━━╋━━━\n";
    std::cout << " " << board[3] << " ┃ " << board[4] << " ┃ " << board[5] << " \n";
    std::cout << "━━━╋━━━╋━━━\n";
    std::cout << " " << board[6] << " ┃ " << board[7] << " ┃ " << board[8] << " \n";
    std::cout << "\n";
}

bool checkWin(const std::vector<char>& board, char player) {
    const int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6} 
    };

    for (int i = 0; i < 8; ++i) {
        if (board[winPatterns[i][0]] == player &&
            board[winPatterns[i][1]] == player &&
            board[winPatterns[i][2]] == player) {
            return true;
        }
    }
    return false;
}

bool checkDraw(const std::vector<char>& board) {
    for (char cell : board) {
        if (cell != 'X' && cell != 'O') {
            return false;
        }
    }
    return true;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char currentPlayer = 'X';
    bool gameOver = false;

    std::cout << "=== Мега шедевро игра Крестики-Нолики ===" << std::endl;

    while (!gameOver) {
        drawBoard(board);

        int choice;
        std::cout << "Игрок " << currentPlayer << ", выберите номер ячейки (псс.. нужно написать цифру куда ты хочешь походить): ";

        if (!(std::cin >> choice) || choice < 1 || choice > 9 || board[choice - 1] == 'X' || board[choice - 1] == 'O') {
            std::cout << "Неверный ход! Попробуй еще раз.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        board[choice - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            drawBoard(board);
            std::cout << "Поздравляем! Игрок " << currentPlayer << " победил!\n";
            gameOver = true;
        } else if (checkDraw(board)) {
            drawBoard(board);
            std::cout << "Ничья! Хорошая игра.\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
