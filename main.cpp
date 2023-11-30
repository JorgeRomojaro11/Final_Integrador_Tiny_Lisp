#include <iostream>
#include <fstream>
#include <string>

void load_script(const char* filename, bool show_script = false) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::ios_base::failure("No se pudo abrir el archivo '" + std::string(filename) + "'.");
    }

    std::string line;
    while (std::getline(file, line)) {
        if (show_script) {
            std::cout << line << std::endl;
        }
    }

    file.close();
}

void load_script() {
    std::string filename;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> filename;

    try {
        load_script(filename.c_str(), true);
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Error de archivo: " << e.what() << std::endl;
        return;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }
}

int main() {
    try {
        load_script();
    } catch (...) {
        std::cerr << "Error desconocido." << std::endl;
    }

    return 0;
}

