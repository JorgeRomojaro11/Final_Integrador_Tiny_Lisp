#include <iostream>
#include <fstream>
#include <string>

void load_script(const char* filename, bool show_script = false) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo '" << filename << "'.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (show_script) {
            std::cout << line << std::endl;
        }
    }

    file.close();
}
    }