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

        if (file.peek() == ifstream::traits_type::eof())
        {
            cerr << "El archivo esta vacio." << endl;
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
    catch (const ios_base::failure &e)
    {
        cerr << "Error de archivo: " << e.what() << endl;
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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


