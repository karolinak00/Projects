#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

struct element
{
    char nazwa[30];
    int wygrane;
    struct element *pNastepny;

} element;

struct element *pHead;


/**
Funkcja uklada z przeslanych do niej danych liste jednokierunkowa.
@param poczatek wskaznik na glowe listy
@param nazwa nazwa gracza
@param wygrane liczba wygranych przez danego gracza rozgrywek
*/
void Statystyki(struct element *poczatek, char *nazwa, int wygrane);

/**
Funkcja pobiera z pliku kolejne linie, dzieli je na nazwy graczy i liczbe wygranych przez nich gier oraz wysyla otrzymane dane do funkcji "Statystyki".
@param fp wskaznik do pliku ze statystykami
@param poczatek wskaznik na glowe listy
*/
void Przygotuj_statystyki(FILE*fp, struct element *poczatek);

/**
Funkcja wyswietla statystyki.
@param poczatek wskaznik na glowe listy
*/
void Wyswietl_statystyki(struct element *poczatek);

/**
Funkcja wyswietla zasady gry
*/
void Zasady_gry();

/**
Funkcja zatrzymuje na pewien czas system, dzieki czemu komunikaty na ekranie pojawiaja sie w okreslonych odstepach czasowych
@param x czas w milisekundach
*/
void Czekaj(int x);

/**
Funkcja sprawdza, czy naniesiona w pliku flota ma prawidlowy rozmiar.
@param fp wskaznik do pliku
@return 1, jezeli flota ma poprawny rozmiar, w przeciwnym przypadku zwracana jest wartosc 0
*/
int Dobry_rozmiar(FILE*fp);

/**
Funkcja sprawdza, czy naniesiona w pliku flota sklada sie z dozwolonych znakow.
@param fp wskaznik do pliku
@return 1, jezeli w pliku zostaly uzyte dozwolone znaki, w przeciwnym przypadku zwracana jest wartosc 0
*/
int Czy_dobre_znaki(FILE*fp);

/**
Funkcja uzupelnia wczesniej zaalokowana dynamicznie tablice znakami z pliku.
@param fp wskaznik do pliku
@param wiersze liczba wierszy tablicy
@param kolumny liczba kolumn tablicy
*/
void Uzupelnij_flote(FILE*fp, char **flota, int wiersze, int kolumny);

/**
Funkcja sprawdza, czy flota zostala naniesione w poprawny sposob.
@param flota wskaznik do tablicy, w ktorej naniesiona jest flota
@param wiersze liczba wierszy tablicy
@param kolumny liczba kolumn tablicy
@return 1, jezeli flota zostala poprawnie naniesiona, w przeciwnym przypadku zwracana jest wartosc 0
*/
int Sprawdz_poprawnosc(char **flota, int wiersze, int kolumny);

/**
Funkcja wypelnia tablice tak, aby wiersz zerowy skladal sie z liter A-J, a zerowa kolumna z liczb 0-9. Wspolrzednej (0,0) przypisany jest znak '*', a reszta tablicy wypelniona jest okreslonym znakiem (' ' w trakcie gry, '.', gdy tablica zapisywana jest do pliku). Dzieki tej funkcji gracz moze zobaczyc, w ktore miejsca juz strzelal, a po zakonczeniu gry funkcja ta pozwala na wyczyszczenie pliku z flota i przygotowanie jej do nastepnej gry.
@param flota tablica, ktora przygotowuje sie do gry lub do zapisu do pliku
@param znak znak, ktorym tablica ma zostac wypelniona
*/
void Przygotuj(char flota[11][11], char znak);

/**
Funkcja odpowiedzialna jest za przeprowadzenie gry.
@param flota1 flota pierwszego gracza
@param flota2 flota drugiego gracza
@param imie1 imie pierwszego gracza
@param imie2 imie drugiego gracza
@param wiersze1 liczba wierszy tablicy flota1
@param wiersze2 liczba wierszy tablicy flota2
@param pHead wskaznik na glowe listy
@return 0, co oznacza koniec gry
*/
int Gra(char **flota1, char **flota2, char *imie1, char *imie2, int wiersze1, int wiersze2, struct element *pHead);

/**
Funkcja sprawdza, czy adres kolumny podany przez gracza jest prawidlowy.
@param kolumna adres kolumny podany przez gracza
@return 1, jezeli adres kolumny jest poprawny, w przeciwnym przypadku zwracana jest wartosc 0
*/
int Czy_dobra_kolumna(char kolumna);

/**
Funkcja sprawdza, czy adres wiersza podany przez gracza jest prawidlowy.
@param wiersz adres wiersza podany przez gracza
@return 1, jezeli wiersz jest poprawny, w przeciwnym przypadku zwracana jest wartosc 0
*/
int Czy_dobry_wiersz(char wiersz);

/**
Funkcja sprawdza, czy trafiony statek zostal zatopiony.
@param flota tablica zawierajaca flote przeciwnika
@param wiersz adres wiersza, do ktorego strzelano
@param kolumna adres kolumny, do ktorej strzelano
@return 1, jesli statek zostal zatopiony, jezeli nie, zwracana jest wartosc 0
*/
int Czy_zatopiony(char **flota, int wiersz, int kolumna);

/**
Funkcja usuwa tablice z naniesiona flota.
@param flota tablica, w ktorej naniesiona jest flota
@param wiersz liczba wierszy tablicy
*/
void Ususn_flote(char**flota, int wiersze);

/**
Funkcja uaktualnia statystyki, tzn. sprawdza, czy nazwa zwyciezcy zostala juz kiedys zapisana w statystykach. Jesli tak, liczba wygranych przez niego gier zostaje zwiekszona o jeden. W przeciwnym przypadku nazwa gracza dodawana jest do listy przechowujacej dane ze statystykami.
@param nazwa nazwa gracza
@param poczatek wskaznik na glowe listy
*/
void Uaktualnij_statystyki(char*nazwa, struct element *poczatek);

/**
Funkcja usuwa liste ze statystykami.
@param poczatek wskaznik na glowe listy
*/
void Usun_statystyki(struct element* poczatek);

/**
Funkcja aktualizuje statystyki po zakonczonej grze.
@param fp wskaznik do pliku ze statystykami
@param poczatek wskaznik na glowe listy
@param nazwa nazwa gracza, ktory wygral
*/
void Zapisz_do_statystyk(FILE* fp, struct element* poczatek);

/**
Funkcja usuwa pliki "flota1.txt" i "flota2.txt"oraz zastepuje je nowymi plikami o tych samych nazwach, ktore sa przygotowane do nowej gry. Nastepuje zaktualizowanie pliku ze statystykami oraz usuniecie listy, w ktorej dotychczas przechowywane byly statystyki.
@param poczatek wskaznik na glowe listy
*/
void Zakoncz(struct element *poczatek);
