#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

string setRGBColor(int r, int g, int b) {
    return "\033[38;2;" + to_string(r) + ";" + to_string(g) + ";" + to_string(b) + "m";
}

int main() {
    cout << "\n\n\n";
    const int width = 55;
    const int height = 20;
    const float scale_x = 0.035;
    const float scale_y = 0.068;
    srand(time(0));

    bool heart_started = false;
    bool heart_ended = false;
    for (int y = height; y >= -height; y--) {
        bool has_heart_pixels = false;
        string line;
        for (int x = -width; x <= width; x++) {
            float x_scaled = x * scale_x;
            float y_scaled = y * scale_y;
            float heart_eq = pow(x_scaled * x_scaled + y_scaled * y_scaled - 1, 3) - x_scaled * x_scaled * y_scaled * y_scaled * y_scaled;
            if (heart_eq <= 0) {
                has_heart_pixels = true;
                char symbols[] = {'#', '@', '*', '%', '&', '+', '=', '$'};
                int random_index = rand() % (sizeof(symbols) / sizeof(symbols[0]));
                if (rand() % 2 == 0) {
                    line += setRGBColor(250, 237, 177) + symbols[random_index];
                } else {
                    line += setRGBColor(250, 137, 137) + symbols[random_index];
                }
            } else {
                line += " ";
            }
        }

        cout << line << "\033[0m\n";
        if (has_heart_pixels && !heart_started) heart_started = true;
        if (heart_started && !has_heart_pixels) heart_ended = true;
        if (heart_ended) break;
    }


    string signature[] = {
            "H   H  AAA  PPPP  PPPP  Y   Y     V   V   AAA  L      EEEEE  N   N  TTTTT  I  N   N  EEEEE ||  SSS      DDDD   AAA  Y   Y",
            "H   H A   A P   P P   P  Y Y      V   V  A   A L      E      NN  N    T    I  NN  N  E     || S         D   D A   A  Y Y ",
            "HHHHH AAAAA PPPP  PPPP    Y       V   V  AAAAA L      EEEE   N N N    T    I  N N N  EEEE      SSS      D   D AAAAA   Y  ",
            "H   H A   A P     P       Y        V V   A   A L      E      N  NN    T    I  N  NN  E            S     D   D A   A   Y  ",
            "H   H A   A P     P       Y         V    A   A LLLLL  EEEEE  N   N    T    I  N   N  EEEEE     SSS      DDDD  A   A   Y  "
    };

    // Вывод подписи
    for (const string& original_line : signature) {
        string line;
        for (char ch : original_line) {
            if (ch != ' ') {
                char symbols[] = {'#', '@', '*', '%', '&', '+', '=', '$'};
                int random_index = rand() % (sizeof(symbols) / sizeof(symbols[0]));
                if (rand() % 2 == 0) {
                    line += setRGBColor(250, 237, 177) + symbols[random_index];
                } else {
                    line += setRGBColor(250, 137, 137) + symbols[random_index];
                }
            } else {
                line += " ";
            }
        }

        cout << line << "\033[0m\n";
    }

    cout << "\nНажмите Enter, чтобы выйти...";
    cin.get();
    return 0;
}