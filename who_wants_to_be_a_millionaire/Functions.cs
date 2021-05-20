using System;
using System.Collections.Generic;
using System.Text;

namespace who_wants_to_be_a_millionaire
{
    class Functions
    {
        public Functions() { }
        ~Functions() { }

        public void menu()
        {
            Stats s = new Stats();
            MyList l = new MyList(); // list contains questions and answers
            Game game = new Game();
            char choice;
            string input;
            if (s.create_stats())
            {
                do
                {
                    bool correct = false;
                    do
                    {
                        Console.WriteLine("MENU\n");
                        Console.WriteLine("Aby poznac zasady gry, wybierz 1.");
                        Console.WriteLine("Aby rozpoczac gre, wybierz 2.");
                        Console.WriteLine("Aby wyswietlic statystyki, wybierz 3.");
                        Console.WriteLine("Aby zakonczyc prace z programem, wybierz 0.");
                        input = Console.ReadLine();
                        if (input.Length == 1)
                            correct = true;
                        else
                        {
                            Console.WriteLine("Podaj poprawna opcje!\n");
                            Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
                            Console.ReadKey();
                            Console.Clear();
                        }
                    } while (!correct);
                    choice = input[0];

                    if (choice == '1')
                        instruction();
                    else if (choice == '2')
                        game.new_game(ref l, ref s);

                    else if (choice == '3')
                    {
                        Console.Clear();
                        Console.WriteLine("Statystyki:");
                        s.print_stats();
                        Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
                        Console.ReadKey();
                        Console.Clear();
                    }

                    else if (choice == '0')
                    {
                        Console.Clear();
                        Console.WriteLine("Dziekuje za prace z programem :)\n");
                        Console.WriteLine("Do zobaczenia!:)\n");
                        break;
                    }
                    else
                    {
                        Console.WriteLine("Prosze wybrac poprawna opcje.\n");
                        Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
                        Console.ReadKey();
                        Console.Clear();
                    }
                } while (choice != '0');

            }
        }

        public void instruction()
        {
            Console.Clear();
            Console.WriteLine("Przed Toba 12 pytan. Kazda poprawna odpowiedz przybliza Cie do wygrania miliona zlotych.\n");
            Console.WriteLine("Po udzieleniu poprawnej odpowiedzi Twoja wygrana zwieksza sie.\n");
            Console.WriteLine("Sa dwa progi gwarantowane: 1000zl i 40 000 zl. Jesli po przekroczeniu ktoregos z tych progow udzielisz blednej odpowiedzi, Twoja nagroda bedzie wynosila tyle, ile wartosc pieniedzy w ostatnio osiagnietym progu gwarantowanym.\n");
            Console.WriteLine("Nie martw sie, nie musisz znac odpowiedzi na kazde pytanie. Pomocne moga okazac sie trzy kola ratunkowe:");
            Console.WriteLine("-telefon do naszego eksperta, ktory zna odpowiedz na kazde pytanie,");
            Console.WriteLine("-glos publicznosci - publicznosc glosuje na wariant odpowiedzi, ktory ich zdaniem jest poprawny,");
            Console.WriteLine("-50/50, czyli odrzucone zostana dwie bledne odpowiedzi.");
            Console.WriteLine("Aby skorzystac z kola ratunkowego, po odczytaniu pytania wybierz litere k.\n");
            Console.WriteLine("Nie musisz odpowiadac na wszystkie 12 pytan. Jesli uznasz, ze wygrana Cie zadowala, PRZED odczytaniem kolejnego pytania mozesz zrezygnowac z gry - wtedy wygrywasz tyle, ile masz aktualnie na swoim koncie.\n");
            Console.WriteLine("Czas na udzielenie odpowiedzi jest nieograniczony.\n");
            Console.WriteLine("Powodzenia!\n");
            Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
            Console.ReadKey();
            Console.Clear();

        }
    }
}
