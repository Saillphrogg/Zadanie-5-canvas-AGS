# Opis
ASCII Renderer to projekt w języku C++, który tworzy obrazki w formie plików ASCII na podstawie danych z pliku konfiguracyjnego. Program obsługuje trzy różne kształty: prostokąty, kwadraty i koła.


## Wymagania

- Kompilator C++ z obsługą standardu C++11
- System operacyjny Windows, Linux czy macOS

## Instalacja

1. Sklonuj repozytorium:
   ```bash
   git clone https://github.com/twoje-repozytorium/ascii-renderer.git
   cd ascii-renderer
   
## Kompilacja

1. Wpisz w terminalu/wierszu poleceń:
   ```bash
   g++ -std=c++11 -o ascii_renderer ascii_renderer.cpp

## Użycie

1. Przygotuj plik konfiguracyjny, np. config.txt zaearty w tym repozytorium, zgodnie z poniższym przykładem (bez strzalek i komentarzy).
   ```plaintext
   20 10                <-szerokość canvasu, wysokość canvasu
   .                    <-symbol oznaczający piksel nienależący do żadnej figury
   output.txt           <-nazwa pliku wyjściowego z obrazkiem
   Rectangle 2 2 5 3 #  <-typ figury, współrzędne, szerokość, wysokość, symbol
   Square 10 3 4 *      <-typ figury, współrzędne, rozmiar, symbol
   Circle 15 5 3 o      <-typ figury, współrzędne środka, promień, symbol
   
2. Uruchom program, podając nazwę pliku konfiguracyjnego jako argument
   ```bash
   ./ascii_renderer config.txt   <-na systemie Unix
   ascii_renderer.exe config.txt <-na systemie Windows

3. Otrzymujesz plik output.txt, np. dla config.txt w naszym pliku:
   ```plaintext
   ....................
   ....................
   ..#####........o....
   ..#####...***ooooo..
   ..#####...***ooooo..
   ..........**ooooooo.
   ..........***ooooo..
   .............ooooo..
   ...............o....
   ....................
