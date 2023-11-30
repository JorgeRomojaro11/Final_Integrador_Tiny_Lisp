#include <iostream>
#include <fstream>
#include <vector>

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

ConsoleBox *consoleBox = new ConsoleBox; // suponemos que ya está inicializado

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

        vector<char> script(istreambuf_iterator<char>(file), {});
        file.close();

        if (show_script)
        {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << string(script.begin(), script.end()) << endl;
            cout << ColorConsole::reset;
        }

        consoleBox->new_text();
        consoleBox->set_text(string(script.begin(), script.end()));
    }
    catch (const exception &e)
    {
        cerr << "Error durante la lectura del archivo: " << e.what() << endl;
    }
}

void load_script()
{
    string filename;
    cout << "Archivo: ";
    cin >> filename;
    load_script(filename.c_str(), true);
}

int main()
{
    try
    {
        load_script();
    }
    catch (...)
    {
        cerr << "Error desconocido." << endl;
    }

    return 0;
}

