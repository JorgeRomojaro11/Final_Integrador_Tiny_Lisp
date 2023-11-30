#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
    static constexpr auto reset = "\033[0m";
};
struct ConsoleBox
{
    void new_text() { /*...*/ }
    void set_text(const string &text) { cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox;
void load_script(const char* filename, bool show_script = false)
{
    try
    {
        ifstream file(filename, ios::binary);

        if (!file.is_open())
        {
            cerr << "Error de apertura de " << filename << endl;
            return;
        }

