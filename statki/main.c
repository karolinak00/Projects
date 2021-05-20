#include "funkcje.h"

int main(int argc, char* argv[])
{
    char imie1[29];
    char imie2[29];
    int licznik = 0;
    char **flota1;
    char **flota2;
    int wiersze1=0;
    int kolumny1=0;
    int wiersze2=0;
    int kolumny2=0;
    char opcja;
    char nazwaPliku1[200];
    char nazwaPliku2[200];
    char nazwaPliku3[200];


    for(int a=0; a<argc; a++)
    {
        char argument[20];
        strcpy(argument, argv[a]);
        if(strcmp(argument, "-s")==0)
        {
			strcpy(nazwaPliku1, argv[a + 1]);
			FILE*plik3 = fopen(nazwaPliku1, "r");
            if(plik3)
            {
                Przygotuj_statystyki(plik3, pHead);
                Wyswietl_statystyki(pHead);
                fclose(plik3);
            }
        else
            printf("Plik ze statystykami nie istnieje.\n");


            system("pause");
            system("cls");
			licznik++;
			a++;
		}
		else if (strcmp(argument, "-i")==0)
		{
			strcpy(nazwaPliku2, argv[a + 1]);
			licznik++;
			a++;
		}
		else if (strcmp(argument, "-j")==0)
		{
			strcpy(nazwaPliku3, argv[a + 1]);
			licznik++;
			a++;
		}
    }

    if (licznik != 3)
    {
        printf("Podano zla liczbe parametrow.\n\n");
        system("pause");
        Zakoncz(pHead);
        return 0;
    }

    system("pause");
    system("cls");
    printf("Witajcie! Zapraszam do zagrania w statki :)\n\n");
    Czekaj(2000);
    printf("Poprosze o podanie imienia pierwszego gracza: ");
    gets(imie1);

    Czekaj(1000);
    printf("\nDziekuje. Teraz poprosze o przedstawienie sie drugiego gracza: ");
    gets(imie2);
    while(!strcmp(imie1, imie2))
    {
        printf("Prosze o podanie innej nazwy, ta jest juz zajeta.\n");
        gets(imie2);
    }
    Czekaj(1000);
    printf("\nDziekuje.");
    Czekaj(3000);
    system("cls");
    printf("Czy wyswietlic zasady gry?");
    printf("\n\nWcisnij t jezeli chcesz poznac zasady, w przeciwnym wypadku nacisnij dowolny klawisz rozny od t.\n");
    scanf("%c", &opcja);
    printf("\n");
    if(opcja =='t')
        Zasady_gry();
    system("cls");

    printf("Teraz musze sprawdzic, czy floty zostaly naniesione w poprawny sposob.\n\n");
    Czekaj(1500);

    FILE* plik1 = fopen(nazwaPliku2, "r");
    if(plik1)
    {
        int licznik = 0;
        char pom[14];
        if(!Dobry_rozmiar(plik1) || !Czy_dobre_znaki(plik1))
        {
            printf("%s, Twoja flota nie zostala poprawnie naniesiona. Prosze, popraw bledy i ponownie uruchom gre.\n\n", imie1);
            system("pause");
            return 0;
        }
        fseek(plik1, 0, SEEK_SET);
        while(fgets(pom, 14, plik1))
        {
            wiersze1++;
            if(licznik==0)
            {
                for(int i = 0; i < strlen(pom); i++)
                kolumny1++;
            }
            licznik++;
        }
        flota1 = malloc(wiersze1 * sizeof(char *));
        if(flota1 == NULL)
        {
            printf("\nNie udalo sie przydzielic pamieci.\n\n");
            system("pause");
            return 0;
        }
        for(int i = 0; i < wiersze1; i++)
        {
            flota1[i] = malloc (kolumny1 * sizeof(char));
            if(flota1[i] == NULL)
            {
                printf("\nNie udalo sie przydzielic pamieci.\n\n");
                system("pause");
                free(flota1);
                flota1 = 0;
                return 0;
            }
        }
        Uzupelnij_flote(plik1, flota1, wiersze1, kolumny1);
        if(!Sprawdz_poprawnosc(flota1, wiersze1, kolumny1))
        {
            printf("\n\n%s, Twoja flota nie zostala poprawnie naniesiona. Prosze, popraw bledy i ponownie uruchom gre.\n\n", imie1);
            system("pause");
            Ususn_flote(flota1, wiersze1);
            return 0;

        }
        fclose(plik1);
    }
    else
    {
        printf("Nie udalo sie otworzyc pliku \"%s\".\n\n", nazwaPliku2);
        system("pause");
        return 0;
    }
    FILE* plik2 = fopen(nazwaPliku3, "r");
    if(plik2)
    {
        int licznik = 0;
        char pom[14];
        if(!Dobry_rozmiar(plik2) || !Czy_dobre_znaki(plik2))
        {
            printf("%s, Twoja flota nie zostala poprawnie naniesiona. Prosze, popraw bledy i ponownie uruchom gre.\n\n", imie2);
            system("pause");
            return 0;
        }
        fseek(plik2, 0, SEEK_SET);
        while(fgets(pom, 14, plik1))
        {
            wiersze2++;
            if(licznik==0)
            {
                for(int i = 0; i < strlen(pom); i++)
                kolumny2++;
            }
            licznik++;
        }
        flota2 = malloc(wiersze2 * sizeof(char *));
        if(flota2 == NULL)
        {
            printf("\nNie udalo sie przydzielic pamieci.\n\n");
            system("pause");
            return 0;
        }
        for(int i = 0; i < wiersze1; i++)
        {
            flota2[i] = malloc (kolumny2 * sizeof(char));
            if(flota2[i] == NULL)
            {
                printf("\nNie udalo sie przydzielic pamieci.\n\n");
                system("pause");
                free(flota2);
                flota2 = 0;
                return 0;
            }
        }
        Uzupelnij_flote(plik2, flota2, wiersze2, kolumny2);

        if(!Sprawdz_poprawnosc(flota2, wiersze2, kolumny2))
        {
            printf("\n\n%s, Twoja flota nie zostala poprawnie naniesiona. Prosze, popraw bledy i ponownie uruchom gre.\n\n", imie2);
            system("pause");
            Ususn_flote(flota1, wiersze1);
            Ususn_flote(flota2, wiersze2);
            return 0;
        }
        fclose(plik2);
    }
    else
    {
        printf("Nie udalo sie otworzyc pliku \"%s\".\n\n", nazwaPliku3);
        system("pause");
        Ususn_flote(flota1, wiersze1);
        return 0;
    }
    printf("Floty zostaly naniesione poprawnie, wiec mozemy zaczac gre.\n\n");
    system("pause");
    system("cls");
    Gra(flota1, flota2, imie1, imie2, wiersze1, wiersze2, pHead);
    return 0;
}
