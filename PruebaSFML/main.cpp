#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

const double PI = 3.14159265358979323846;

int main() {
    sf::RenderWindow ventana(sf::VideoMode(800, 800), "Ojo de Mosca");

    const float centroX = 400.0f;
    const float centroY = 400.0f;
    const float radio = 200.0f;
    const int numVertices = 17;

    // Calcula los vértices en los límites de la circunferencia
    std::vector<sf::Vector2f> vertices;
    for (int i = 0; i < numVertices; i++) {
        float angulo = 2 * PI * i / numVertices;
        float x = centroX + radio * std::cos(angulo);
        float y = centroY + radio * std::sin(angulo);
        vertices.push_back(sf::Vector2f(x, y));
    }

    // Crea un objeto VertexArray para las aristas
    sf::VertexArray aristas(sf::Lines);
    for (size_t i = 0; i < vertices.size(); i++) {
        for (size_t j = i + 1; j < vertices.size(); j++) {
            aristas.append(sf::Vertex(vertices[i]));
            aristas.append(sf::Vertex(vertices[j]));
        }
    }

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }
        }

        ventana.clear();
        ventana.draw(aristas);
        ventana.display();
    }

    return 0;
}
