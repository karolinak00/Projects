#include "funkcje.h"

void Statystyki(struct element *poczatek, char *nazwa, int wygrane)
{
    if(!pHead)
    {
        pHead = malloc(sizeof *pHead);
        strcpy(pHead->nazwa, nazwa);
        pHead->wygrane = wygrane;
        pHead->pNastepny = NULL;
    }

    else
    {
        struct element *wsk = poczatek;
        while(wsk->pNastepny != NULL)
			wsk = wsk->pNastepny;
		struct element * nowy = malloc(sizeof(*pHead));
		strcpy(nowy->nazwa, nazwa);
		nowy->wygrane = wygrane;
		nowy->pNastepny = NULL;
		wsk->pNastepny = nowy;
    }

}

void Przygotuj_statystyki(FILE*fp, struct element *poczatek)
{
    char linia[30];
    char nazwa[30];
    char liczba[30];
    int licznik = 0;
    int wygrane = 0;

    while(fgets(linia, 30, fp))
    {
        if(fmod(licznik,2)==1)
        {
            strcpy(liczba, linia);
            wygrane = strtol(liczba, NULL, 10);
            Statystyki(pHead, nazwa, wygrane);
        }

        else
            strcpy(nazwa, linia);

        licznik++;

    }
}

void Wyswietl_statystyki(struct element *poczatek)
{
    if(pHead)
    {
        printf("%s\tgry wygrane: %i\n", poczatek->nazwa, poczatek->wygrane);

        if(poczatek->pNastepny != NULL)
            Wyswietl_statystyki(poczatek->pNastepny);
    }

}

void Zasady_gry()
{
    system("cls");
    printf("Cel gry: zatopienie wszystkich statkow nalezacych do przeciwnika.\n\n");
    system("pause");
    system("cls");
    printf("Gracze w plikach zaznaczaja swoje floty (gracz pierwszy w pliku \"flota1.txt\", zas gracz drugi w pliku \"flota2.txt\").");
    Czekaj(3500);
    printf("\n\nDo dyspozycji jest 100 pol oznaczonych kropkami. Na tych polach powinny znalezc sie nastepujace statki: \n");
    Czekaj(3000);
    printf("-jeden czteromasztowiec,\n");
    Czekaj(1500);
    printf("-dwa trojmasztowce,\n");
    Czekaj(1500);
    printf("-trzy dwumasztowce,\n");
    Czekaj(1500);
    printf("-cztery jednomasztowce.\n\n");
    system("pause");
    system("cls");
    printf("Statki mozna zaznaczac w pionie lub w poziomie.\n\n");
    Czekaj(1500);
    printf("Moga one w dowolny sposob przylegac do boku pola gry, nie moga jednak stykac sie z innymi statkami.\n\n");
    system("pause");
    system("cls");
    printf("Przebieg rozgrywki:\n");
    Czekaj(1500);
    printf("Kazdy z graczy probuje znalezc statek przeciwnika, podajac dowolne wspolrzedne pol na planszy.\n");
    Czekaj(2000);
    printf("Jesli gracz trafi, ma prawo strzelic kolejny raz - dopoki nie spudluje.\n\n");
    system("pause");
    system("cls");
    printf("Wygrywa ten gracz, ktory jako pierwszy zatopi wszystkie okrety przeciwnika.\n\n");
    system("pause");
}

void Czekaj(int x)
{
    float czas = clock();
    while(clock()<czas+x);

}

int Dobry_rozmiar(FILE*fp)
{
    char pom[14];
    int liczba_znakow_do9 = 12; // w kazdym wierszu jest widocznych jedenascie znakow ( w pierwszym '*' i litery od A do J, w kolejnych jedna z liczb z przedzialu od 0 do 9 i 10 pol), ale trzeba jeszcze doliczyc znak nowej linii ('/n')
    int liczba_znakow_w9 = 11; // w wierszu oznaczonym jako '9' jest widocznych tylko jedenascie znakow (w wierszu tym nie wystepuje znak konca linii)
    int prawidlowa_liczba_wierszy = 11;
    int kolumny=0;
    int wiersze=0;
    while(fgets(pom, 14, fp))
    {
        wiersze++;
        for(int i=0; i < strlen(pom); i++)
            kolumny++;

        if(pom[0] == '9')
        {
            if(kolumny!=liczba_znakow_w9)
                return 0;
        }
        else if(kolumny != liczba_znakow_do9)
            return 0;

        kolumny = 0;
    }

    if(wiersze != prawidlowa_liczba_wierszy)
         return 0;

    return 1;
}

int Czy_dobre_znaki(FILE*fp)
{
    char pom[11];
    int licznik=0;
    while(fgets(pom, 11, fp))
    {
        for(int i = 0; i < strlen(pom-1); i++)
        {
            if(pom[i+1]!='.' || pom[i+1] != 'X' || pom[i+1] != 'x')
                return 0;

        }
        licznik++;
    }
    return 1;
}

int Sprawdz_poprawnosc(char **flota, int wiersze, int kolumny)
{
    int jednomasztowce = 4;
    int dwumasztowce = 3;
    int trojmasztowce = 2;
    int czteromasztowce = 1;
    int licznik1 = 0;
    int licznik2 = 0;
    int licznik = 1;

    for(int i = wiersze-1; i >= 0; i--)
    {
        for(int j = kolumny-1; j >= 0; j--)
        {

            if (toupper(flota[i][j]) == 'X')
            {
                if(i==0 || j==0)
                    continue;

                else if(i == wiersze-1 && j == kolumny-1)
                {
                    if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i][j-1]) != 'X')
                    {
                        jednomasztowce--;
                        flota[i][j] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) == 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i-2][j-1]) != 'X' && toupper(flota[i-2][j]) != 'X')
                    {
                        dwumasztowce--;
                        flota[i][j] = 'I';
                        flota[i-1][j] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) == 'X' && toupper(flota[i-2][j]) == 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i-2][j-1]) != 'X' && toupper(flota[i-3][j-1]) != 'X' && toupper(flota[i-3][j]) != 'X')
                    {
                        trojmasztowce--;
                        flota[i][j] = 'I';
                        flota[i-1][j] = 'I';
                        flota[i-2][j] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) == 'X' && toupper(flota[i-2][j]) == 'X' && toupper(flota[i-3][j]) == 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i-2][j-1]) != 'X' && toupper(flota[i-3][j-1]) != 'X' && toupper(flota[i-4][j]) != 'X' && toupper(flota[i-4][j-1]) != 'X')
                    {
                        czteromasztowce--;
                        flota[i][j] = 'I';
                        flota[i-1][j] = 'I';
                        flota[i-2][j] = 'I';
                        flota[i-3][j] = 'I';
                    }

                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i][j-1]) == 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j-2]) != 'X' && toupper(flota[i][j-2]) != 'X')
                    {
                        dwumasztowce--;
                        flota[i][j] = 'I';
                        flota[i][j-1] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i][j-1]) == 'X' && toupper(flota[i][j-2]) == 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j-2]) != 'X' && toupper(flota[i-1][j-3]) != 'X' && toupper(flota[i][j-3]) != 'X')
                    {
                        trojmasztowce--;
                        flota[i][j] = 'I';
                        flota[i][j-1] = 'I';
                        flota[i][j-2] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i][j-1]) == 'X' && toupper(flota[i][j-2]) == 'X' && toupper(flota[i][j-3]) == 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j-2]) != 'X' && toupper(flota[i-1][j-3]) != 'X' && toupper(flota[i][j-4]) != 'X' && toupper(flota[i-1][j-4]) != 'X')
                    {
                        czteromasztowce--;
                        flota[i][j] = 'I';
                        flota[i][j-1] = 'I';
                        flota[i][j-2] = 'I';
                        flota[i][j-3] = 'I';
                    }

                    else
                        return 0;
                }

                else if(i == wiersze-1)
                {
                    if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i][j+1]) != 'X' && toupper(flota[i-1][j+1]) != 'X')
                    {
                        jednomasztowce--;
                        flota[i][j] = 'I';
                    }

                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) == 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i-2][j]) != 'X' && toupper(flota[i-2][j-1]) != 'X' && toupper(flota[i+1][j]) != 'X' && toupper(flota[i+1][j-1]) != 'X')
                    {
                        dwumasztowce--;
                        flota[i][j] = 'I';
                        flota[i-1][j] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) == 'X' && toupper(flota[i-2][j]) == 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i-3][j]) != 'X' && toupper(flota[i-3][j-1]) != 'X' && toupper(flota[i-2][j-1]) != 'X' && toupper(flota[i+1][j]) != 'X' && toupper(flota[i+1][j-1]) != 'X')
                    {
                        trojmasztowce--;
                        flota[i][j] = 'I';
                        flota[i-1][j] = 'I';
                        flota[i-2][j] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) == 'X' && toupper(flota[i-2][j]) == 'X' && toupper(flota[i-3][j]) == 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i-4][j]) != 'X' && toupper(flota[i-4][j-1]) != 'X' && toupper(flota[i-3][j-1]) != 'X' && toupper(flota[i-2][j-1]) != 'X' && toupper(flota[i+1][j]) != 'X' && toupper(flota[i+1][j-1]) != 'X')
                    {
                        czteromasztowce--;
                        flota[i][j] = 'I';
                        flota[i-1][j] = 'I';
                        flota[i-2][j] = 'I';
                        flota[i-3][j] = 'I';
                    }

                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i][j-1]) == 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i][j-2]) != 'X' && toupper(flota[i-1][j-2]) != 'X' && toupper(flota[i][j+1]) != 'X' && toupper(flota[i-1][j+1]) != 'X')
                    {
                        dwumasztowce--;
                        flota[i][j] = 'I';
                        flota[i][j-1] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i][j-1]) == 'X' && toupper(flota[i][j-2]) == 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i][j-3]) != 'X' && toupper(flota[i-1][j-3]) != 'X' && toupper(flota[i-1][j-2]) != 'X' && toupper(flota[i][j+1]) != 'X' && toupper(flota[i-1][j+1]) != 'X')
                    {
                        trojmasztowce--;
                        flota[i][j] = 'I';
                        flota[i][j-1] = 'I';
                        flota[i][j-2] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i][j-1]) == 'X' && toupper(flota[i][j-2]) == 'X' && toupper(flota[i][j-3]) == 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i][j-4]) != 'X' && toupper(flota[i-1][j-4]) != 'X' && toupper(flota[i-1][j-3]) != 'X' && toupper(flota[i-1][j-2]) != 'X' && toupper(flota[i][j+1]) != 'X' && toupper(flota[i-1][j+1]) != 'X')
                    {
                        czteromasztowce--;
                        flota[i][j] = 'I';
                        flota[i][j-1] = 'I';
                        flota[i][j-2] = 'I';
                        flota[i][j-3] = 'I';
                    }
                    else
                        return 0;
                }
                else if(j == kolumny-1)
                {
                    if(toupper(flota[i][j]) == 'X' && toupper(flota[i+1][j]) != 'X' && toupper(flota[i+1][j-1]) != 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i-1][j]) != 'X')
                    {
                        jednomasztowce--;
                        flota[i][j] = 'I';
                    }

                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) == 'X' && toupper(flota[i+1][j]) != 'X' && toupper(flota[i+1][j-1]) != 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i-2][j-1]) != 'X' && toupper(flota[i-2][j]) != 'X')
                    {
                        dwumasztowce--;
                        flota[i][j] = 'I';
                        flota[i-1][j] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) == 'X' && toupper(flota[i-2][j]) == 'X' && toupper(flota[i+1][j]) != 'X' && toupper(flota[i+1][j-1]) != 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i-2][j-1]) != 'X' && toupper(flota[i-3][j]) != 'X' && toupper(flota[i-3][j-1]) != 'X')
                    {
                        trojmasztowce--;
                        flota[i][j] = 'I';
                        flota[i-1][j] = 'I';
                        flota[i-2][j] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) == 'X' && toupper(flota[i-2][j]) == 'X' && toupper(flota[i-3][j]) == 'X' && toupper(flota[i+1][j]) != 'X' && toupper(flota[i+1][j-1]) != 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i-2][j-1]) != 'X' && toupper(flota[i-4][j]) != 'X' && toupper(flota[i-3][j-1]) != 'X' && toupper(flota[i-4][j-1]) != 'X')
                    {
                        czteromasztowce--;
                        flota[i][j] = 'I';
                        flota[i-1][j] = 'I';
                        flota[i-2][j] = 'I';
                        flota[i-3][j] = 'I';
                    }

                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i][j-1]) == 'X' && toupper(flota[i][j+1]) != 'X' && toupper(flota[i-1][j+1]) != 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i-1][j-2]) != 'X' && toupper(flota[i][j-2]) != 'X')
                    {
                        dwumasztowce--;
                        flota[i][j] = 'I';
                        flota[i][j-1] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i][j-1]) == 'X' && toupper(flota[i][j-2]) == 'X' && toupper(flota[i][j+1]) != 'X' && toupper(flota[i-1][j+1]) != 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i-1][j-2]) != 'X' && toupper(flota[i][j-3]) != 'X' && toupper(flota[i-1][j-3]) != 'X')
                    {
                        trojmasztowce--;
                        flota[i][j] = 'I';
                        flota[i][j-1] = 'I';
                        flota[i][j-2] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i][j-1]) == 'X' && toupper(flota[i][j-2]) == 'X' && toupper(flota[i][j-3]) == 'X' && toupper(flota[i][j+1]) != 'X' && toupper(flota[i-1][j+1]) != 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j-1]) != 'X' && toupper(flota[i-1][j-2]) != 'X' && toupper(flota[i][j-4]) != 'X' && toupper(flota[i-1][j-3]) != 'X' && toupper(flota[i-1][j-4]) != 'X')
                    {
                        czteromasztowce--;
                        flota[i][j] = 'I';
                        flota[i][j-1] = 'I';
                        flota[i][j-2] = 'I';
                        flota[i][j-3] = 'I';
                    }
                    else
                        return 0;
                }
                else
                {
                    if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j+1]) != 'X' && toupper(flota[i][j+1]) != 'X' && toupper(flota[i+1][j+1]) != 'X' && toupper(flota[i+1][j]) != 'X' && toupper(flota[i+1][j-1]) != 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i-1][j-1]) != 'X')
                    {
                        jednomasztowce--;
                        flota[i][j] = 'I';
                    }

                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) == 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i+1][j-1]) != 'X' && toupper(flota[i+1][j]) != 'X' && toupper(flota[i+1][j+1]) != 'X' && toupper(flota[i][j+1]) != 'X' && toupper(flota[i-1][j+1]) != 'X' && toupper(flota[i-2][j]) != 'X' && toupper(flota[i-2][j+1]) != 'X' && toupper(flota[i-2][j-1]) != 'X' && toupper(flota[i-1][j-1]) != 'X')
                    {
                        dwumasztowce--;
                        flota[i][j] = 'I';
                        flota[i-1][j] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) == 'X' && toupper(flota[i-2][j]) == 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i+1][j-1]) != 'X' && toupper(flota[i+1][j]) != 'X' && toupper(flota[i+1][j+1]) != 'X' && toupper(flota[i][j+1]) != 'X' && toupper(flota[i-1][j+1]) != 'X' && toupper(flota[i-3][j]) != 'X' && toupper(flota[i-3][j+1]) != 'X' && toupper(flota[i-3][j-1]) != 'X' && toupper(flota[i-2][j+1]) != 'X' && toupper(flota[i-2][j-1]) != 'X' && toupper(flota[i-1][j-1]) != 'X')
                    {
                        trojmasztowce--;
                        flota[i][j] = 'I';
                        flota[i-1][j] = 'I';
                        flota[i-2][j] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i-1][j]) == 'X' && toupper(flota[i-2][j]) == 'X' && toupper(flota[i-3][j]) == 'X' && toupper(flota[i][j-1]) != 'X' && toupper(flota[i+1][j-1]) != 'X' && toupper(flota[i+1][j]) != 'X' && toupper(flota[i+1][j+1]) != 'X' && toupper(flota[i][j+1]) != 'X' && toupper(flota[i-1][j+1]) != 'X' && toupper(flota[i-4][j]) != 'X' && toupper(flota[i-4][j-1]) != 'X' && toupper(flota[i-4][j+1]) != 'X' && toupper(flota[i-3][j+1]) != 'X' && toupper(flota[i-3][j-1]) != 'X' && toupper(flota[i-2][j+1]) != 'X' && toupper(flota[i-2][j-1]) != 'X' && toupper(flota[i-1][j-1]) != 'X')
                    {
                        czteromasztowce--;
                        flota[i][j] = 'I';
                        flota[i-1][j] = 'I';
                        flota[i-2][j] = 'I';
                        flota[i-3][j] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i][j-1]) == 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j+1]) != 'X' && toupper(flota[i][j+1]) != 'X' && toupper(flota[i+1][j+1]) != 'X' && toupper(flota[i+1][j]) != 'X' && toupper(flota[i+1][j-1]) != 'X' && toupper(flota[i][j-2]) != 'X' && toupper(flota[i+1][j-2]) != 'X' && toupper(flota[i-1][j-2]) != 'X' && toupper(flota[i-1][j-1]) != 'X')
                    {
                        dwumasztowce--;
                        flota[i][j] = 'I';
                        flota[i][j-1] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i][j-1]) == 'X' && toupper(flota[i][j-2]) == 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j+1]) != 'X' && toupper(flota[i][j+1]) != 'X' && toupper(flota[i+1][j+1]) != 'X' && toupper(flota[i+1][j]) != 'X' && toupper(flota[i+1][j-1]) != 'X' && toupper(flota[i][j-3]) != 'X' && toupper(flota[i+1][j-3]) != 'X' && toupper(flota[i-1][j-3]) != 'X' && toupper(flota[i+1][j-2]) != 'X' && toupper(flota[i-1][j-2]) != 'X' && toupper(flota[i-1][j-1]) != 'X')
                    {
                        trojmasztowce--;
                        flota[i][j] = 'I';
                        flota[i][j-1] = 'I';
                        flota[i][j-2] = 'I';
                    }
                    else if(toupper(flota[i][j]) == 'X' && toupper(flota[i][j-1]) == 'X' && toupper(flota[i][j-2]) == 'X' && toupper(flota[i][j-3]) == 'X' && toupper(flota[i-1][j]) != 'X' && toupper(flota[i-1][j+1]) != 'X' && toupper(flota[i][j+1]) != 'X' && toupper(flota[i+1][j+1]) != 'X' && toupper(flota[i+1][j]) != 'X' && toupper(flota[i+1][j-1]) != 'X' && toupper(flota[i][j-4]) != 'X' && toupper(flota[i-1][j-4]) != 'X' && toupper(flota[i+1][j-4]) != 'X' && toupper(flota[i+1][j-3]) != 'X' && toupper(flota[i-1][j-3]) != 'X' && toupper(flota[i+1][j-2]) != 'X' && toupper(flota[i-1][j-2]) != 'X' && toupper(flota[i-1][j-1]) != 'X')
                    {
                        czteromasztowce--;
                        flota[i][j] = 'I';
                        flota[i][j-1] = 'I';
                        flota[i][j-2] = 'I';
                        flota[i][j-3] = 'I';
                    }
                    else
                        return 0;
                }
            }
        }
    }

    if (jednomasztowce == 0 && dwumasztowce == 0 && trojmasztowce == 0 && czteromasztowce == 0)
        return 1;

    else
        return 0;
}

void Uzupelnij_flote(FILE*fp, char **flota, int wiersze, int kolumny)
{
    char pom[12];
    int licznik=0;
    int tmp = 0;
    char *tab;

    fseek(fp, 0, SEEK_SET);
    while(fgets(pom, 12, fp))
    {
        for(int i=0; i<strlen(pom); i++)
            licznik++;
    }

    tab = (char*)malloc(licznik * sizeof (char));

    fseek(fp, 0, SEEK_SET);
    while(fgets(pom, 12, fp))
    {
        for(int j = 0; j < strlen(pom); j++)
        {
            tab[tmp] = pom[j];
            tmp++;
        }
    }

    for(int i=0; i<licznik; i++)
    {
        if(tab[licznik]==' ')
            tab[licznik] = (int) "";
        else if (tab[licznik] == '\n')
            tab[licznik] = '\0';
    }

    for (int i=0; i<wiersze; i++)
    {
        for(int j= 0; j< kolumny; j++)
        {
            if(i==wiersze-1 && j==kolumny-1)
                flota[i][j]='\0';
            else
                flota[i][j] = tab[j+i*kolumny];
        }
    }
    free(tab);
    tab = 0;
}


void Przygotuj(char flota[11][11], char znak) // flota ma rozmiar 11x11
{
    for(int i =0; i< 11; i++)
    {
        for(int j=0; j<11; j++)
        {
            if (i==0 && j==0)
                flota[i][j] = '*';
            else if (i==0 && j==1)
                flota[i][j] = 'A';
            else if(i==0)
                flota[i][j] = flota[i][j-1]+1;
            else if (i==1 && j==0)
                flota[i][j] = '0';
            else if (j==0)
                flota[i][j] = flota[i-1][j] + 1;
            else
                flota[i][j] = znak;
        }
    }
}

int Gra(char **flota1, char **flota2, char *imie1, char *imie2, int wiersze1, int wiersze2, struct element *pHead)
{
    int trafienia1 = 0;
    int trafienia2 = 0;
    char wiersz;
    char kolumna;
    char strzaly1[11][11];
    char strzaly2[11][11];
    Przygotuj(strzaly1, ' ');
    Przygotuj(strzaly2, ' ');
    while(trafienia1 < 20 && trafienia2 < 20) // statki zajmuja lacznie 20 pol, wiec wygra ten gracz, ktory trafi w 20 miejsc
    {

        printf("Prosze o przekazanie gry %s.\n\n", imie1);
        system("pause");
        int licz1=0;
        int licz2=1;
        while(licz1 == 0)
        {

            system("cls");
            printf("%s, Twoje strzaly aktualnie wygladaja tak:\n\n", imie1);
            for(int i = 0; i < 11; i++)
            {
                for(int j = 0; j < 11; j++)
                    printf("%c", strzaly1[i][j]);
                printf("\n");
            }

            printf("\n\n%s, podaj kolumne: \n\n", imie1);
            scanf(" %c", &kolumna);
            if(Czy_dobra_kolumna(kolumna))
            {
                printf("\n\nPodaj wiersz(pamietaj, ze w tej wersji gry wiersze oznaczone sa liczbami od 0 do 9): \n\n");
                scanf(" %c", &wiersz);
                system("cls");
                if(Czy_dobry_wiersz(wiersz))
                {
                    if(toupper(flota2[(int)wiersz - 47][toupper(kolumna) -64]) == 'I')
                    {
                        strzaly1[(int)wiersz - 47][toupper(kolumna) -64] = 'X';
                        system("cls");
                        printf("Trafiony!\n\n");
                        trafienia1++;


                        if(Czy_zatopiony(flota2, (int)wiersz - 47, toupper(kolumna) -64))
                        {
                            printf("Zatopiony!\n\n");
                            if(trafienia1 == 20)
                            {
                                system("pause");
                                system("cls");
                                printf("Gratulacje! %s wygrywa!\n\n", imie1);
                                system("pause");
                                Uaktualnij_statystyki(imie1, pHead);
                                Ususn_flote(flota1, wiersze1);
                                Ususn_flote(flota2, wiersze2);
                                Zakoncz(pHead);
                                return 0;
                            }
                        }

                        system("pause");
                        system("cls");
                        flota2[(int)wiersz - 47][toupper(kolumna) -64] = 'X';

                        continue;
                    }
                    else if(toupper(flota2[(int)wiersz - 47][toupper(kolumna) -64]) == 'X')
                    {
                        system("cls");
                        printf("Juz tutaj strzelano! Tracisz kolejke!\n\n");
                        licz1++;
                        licz2--;
                        system("pause");
                        system("cls");
                    }

                    else
                    {
                        strzaly1[(int)wiersz - 47][toupper(kolumna) -64] = '-';
                        system("cls");
                        printf("Pudlo!\n\n");
                        licz1++;
                        licz2--;
                        system("pause");
                        system("cls");
                    }
                }
                else
                {
                    printf("Podano zly wiersz. Prosze o ponowne podanie wspolrzednych.\n\n");
                    system("pause");
                    system("cls");
                    continue;
                }

            }
            else
            {
                printf("Podano zla kolumne. Prosze o ponowne podanie wspolrzednych.\n\n");
                system("pause");
                continue;
            }
        }

        printf("Teraz prosze o przekazanie gry %s.\n\n", imie2);
        system("pause");

        while(licz2==0)
        {

            system("cls");
            printf("%s, Twoje strzaly aktualnie wygladaja tak:\n\n", imie2);
            for(int i = 0; i < 11; i++)
            {
                for(int j = 0; j < 11; j++)
                    printf("%c", strzaly2[i][j]);
                printf("\n");
            }
            printf("\n\n%s, podaj kolumne: \n\n", imie2);
            scanf(" %c", &kolumna);
            if(Czy_dobra_kolumna(kolumna))
            {
                printf("\n\nPodaj wiersz(pamietaj, ze w tej wersji gry wiersze oznaczone sa liczbami od 0 do 9): \n\n");
                scanf(" %c", &wiersz);

                if(Czy_dobry_wiersz(wiersz))
                {
                    if(toupper(flota1[(int)wiersz - 47][toupper(kolumna) -64]) == 'I')
                    {
                        strzaly2[(int)wiersz - 47][toupper(kolumna) -64] = 'X';
                        system("cls");
                        printf("Trafiony!\n\n");
                        trafienia2++;

                        if(Czy_zatopiony(flota1, (int)wiersz - 47, toupper(kolumna) -64))
                        {
                            printf("Zatopiony!\n\n");
                            if(trafienia2 == 20)
                            {
                                system("pause");
                                system("cls");
                                printf("Gratulacje! %s wygrywa!\n\n", imie2);
                                system("pause");
                                Uaktualnij_statystyki(imie2, pHead);
                                Ususn_flote(flota1, wiersze1);
                                Ususn_flote(flota2, wiersze2);
                                Zakoncz(pHead);
                                return 0;
                            }
                        }
                        system("pause");
                        system("cls");
                        flota1[(int)wiersz - 47][toupper(kolumna) -64] = 'X';

                        continue;
                    }
                    else if(toupper(flota1[(int)wiersz - 47][toupper(kolumna) -64]) == 'X')
                    {
                        system("cls");
                        printf("Juz tutaj strzelano! Tracisz kolejke!\n\n");
                        licz2++;
                        licz1--;
                        system("pause");
                        system("cls");
                    }

                    else
                    {
                        strzaly2[(int)wiersz - 47][toupper(kolumna) -64] = '-';
                        system("cls");
                        printf("Pudlo!\n\n");
                        licz2++;
                        licz1--;
                        system("pause");
                        system("cls");
                    }

                }
                else
                {
                    printf("\nPodano zly wiersz. Prosze o ponowne podanie wspolrzednych.\n\n");
                    system("pause");
                    continue;
                }

            }
            else
            {
                printf("\nPodano zla kolumne. Prosze o ponowne podanie wspolrzednych.\n\n");
                system("pause");
                continue;
            }
        }

    }
    return 0;
}


int Czy_dobra_kolumna(char kolumna)
{
    if(isalpha(kolumna) && toupper(kolumna) >= 'A' && toupper(kolumna) <= 'J')
        return 1;

    else
        return 0;
}

int Czy_dobry_wiersz(char wiersz)
{
    if((int)wiersz >= 48 && (int)wiersz <= 57)
        return 1;
    else
        return 0;
}

int Czy_zatopiony(char **flota, int wiersz, int kolumna)
{
     int licznik = 1;


    while(wiersz-licznik > 0 && licznik < 4) // statek nie moze byc dluzszy niz na odleglosc 3 pol od miejsca trafienia (w pesymistycznym przypadku)
    {
        if(flota[wiersz-licznik][kolumna] != 'I')
            licznik++;
        else
        {
            if(flota[wiersz-licznik+1][kolumna] == '.' || (flota[wiersz+licznik-1][kolumna] >= '0' && flota[wiersz+licznik-1][kolumna] <='9'))
                break;

            else
                return 0;

        }
    }
licznik = 1;

    while(wiersz+licznik < 11 && licznik < 4)
    {
        if(flota[wiersz+licznik][kolumna] != 'I')
            licznik++;
        else
        {
            if(flota[wiersz+licznik-1][kolumna] == '.')
                break;

            else
                 return 0;

        }
    }

    licznik = 1;

    while(kolumna-licznik > 0 && licznik < 4)
    {
        if(flota[wiersz][kolumna-licznik] != 'I')
            licznik++;
        else
        {
            if(flota[wiersz][kolumna-licznik+1] == '.' || (flota[wiersz][kolumna+licznik-1] >= 'A' && flota[wiersz][kolumna+licznik-1] <='J'))
            {

                break;
            }

            else
                return 0;

        }
    }
    licznik = 1;

    while(kolumna+licznik < 11 && licznik < 4)
    {
        if(flota[wiersz][kolumna+licznik] != 'I')
            licznik++;
        else
        {
            if(flota[wiersz][kolumna+licznik-1] == '.')
                return 1;
            else
                return 0;
        }
    }
    return 1;
}

void Ususn_flote(char**flota, int wiersze)
{
    for(int i = 0; i < wiersze; i++)
        free(flota[i]);

    free(flota);
    flota = 0;

}

void Zapisz_do_statystyk(FILE*fp, struct element *poczatek)
{

    struct element *wsk = poczatek;
    while (wsk)
    {
        fprintf(fp, "%s%i\n", wsk->nazwa, wsk->wygrane);
        wsk = wsk->pNastepny;
    }

}

void Uaktualnij_statystyki(char *nazwa, struct element *poczatek)
{
    strcat(nazwa, "\n");
    int licznik = 0;
    if(!pHead)
    {
        pHead = malloc(sizeof *pHead);
        strcpy(pHead->nazwa, nazwa);
        pHead->wygrane = 1;
        pHead->pNastepny = NULL;
        licznik++;
    }

    else
    {

        struct element *wsk = poczatek;
        while (wsk)
        {
            if (strcmp(wsk->nazwa, nazwa)==0)
            {
                 wsk->wygrane++;
                 licznik++;
                 break;
            }
            else
                wsk = wsk->pNastepny;
        }
       if(licznik == 0)
           Statystyki(pHead, nazwa, 1);
    }
}

void Usun_statystyki(struct element *pHead)
{

    if (pHead)
	{
		while (pHead)
		{
			struct element *p = pHead;
			pHead = pHead->pNastepny;
			free(p);
			p = 0;
		}
	}
}


void Zakoncz(struct element *poczatek)
{
    char tab1[11][11];
    char tab2[11][11];
    Przygotuj(tab1, '.');
    Przygotuj(tab2, '.');
    remove("flota1.txt");
    remove("flota2.txt");
    FILE*fp1 = fopen("flota1.txt", "w");
    if(fp1)
    {
        int licznik=0;
        for(int i = 0; i < 11; i++)
        {
            for(int j = 0; j < 11; j++)
                 fprintf(fp1, "%c", tab1[i][j]);

            licznik++;
            if(licznik < 11)
                fprintf(fp1, "\n");

        }
        fclose(fp1);
    }
    else
        printf("Nie udalo sie utworzyc nowego pliku.\n");

    FILE*fp2 = fopen("flota2.txt", "w");
    if(fp2)
    {
        int licznik=0;
        for(int i = 0; i < 11; i++)
        {
            for(int j = 0; j < 11; j++)
                fprintf(fp2, "%c", tab2[i][j]);
            licznik++;
            if(licznik < 11)
                fprintf(fp2, "\n");
        }
        fclose(fp2);
    }
    else
        printf("Nie udalo sie utworzyc nowego pliku.\n");

    remove("statystyki.txt");
    FILE*fp3 = fopen("statystyki.txt", "w");
    if(fp3)
    {
        Zapisz_do_statystyk(fp3, pHead);
        fclose(fp3);
    }
    else
    printf("Nie udalo sie zapisac statystyk.\n");
    Usun_statystyki(pHead);
}
