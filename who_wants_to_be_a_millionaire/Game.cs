using System;
using System.Collections.Generic;
using System.Text;

namespace who_wants_to_be_a_millionaire
{
    class Game
    {
        // constructor & destructor
        public Game() { }
        ~Game() { }

        // other methods
        public void new_game(ref MyList l, ref Stats s)
        {
            Console.Clear();
            Console.WriteLine("Witam! Zapraszam do zagrania w gre \"Milionerzy\".\n");
            Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
            Console.ReadKey();
            Console.Clear();
            Console.WriteLine("Na poczatku prosze o przedstawienie sie naszego kolejnego zawodnika.\n");
            Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
            Console.ReadKey();
            Console.Clear();
            bool _telephone = true;
            bool _audience = true;
            bool __50_50 = true;
            Player player = new Player();
            player.introduce_yourself();
            Console.Clear();

            Console.WriteLine("Dziekuje.\n");

            Console.WriteLine("Czas wylosowac zestaw pytan.\n");
            int nr = drawing();
            Console.WriteLine("Wylosowano zestaw nr " + nr + ".\n");
            Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
            Console.ReadKey();
            Console.Clear();

            if (init_game(ref nr, ref l))
                game(ref player, ref l, ref s, ref _telephone, ref _audience, ref __50_50);

        }

        public int drawing()
        {
            Random random = new Random();
            return random.Next(1, 4);
        }

        public bool init_game(ref int nr, ref MyList l)
        {
            if (nr == 1)
            {
                if (l.load_list(@"C:\Users\karol\source\repos\Projects\who_wants_to_be_a_millionaire\test1.txt"))
                    return true;
                else
                    return false;
            }


            else if (nr == 2)
            {
                if (l.load_list(@"C:\Users\karol\source\repos\Projects\who_wants_to_be_a_millionaire\test2.txt"))
                    return true;

                else
                    return false;
            }

            else
            {
                if (l.load_list(@"C:\Users\karol\source\repos\Projects\who_wants_to_be_a_millionaire\test3.txt"))
                    return true;

                else
                    return false;
            }
        }

        public void game(ref Player player, ref MyList l, ref Stats s, ref bool _telephone, ref bool _audience, ref bool __50_50)
        {

            int question_number = 1;
            bool surrender = false;
            bool correct = true;
            int counter = 0;
            do
            {
                if (l.ask(ref player, ref counter, ref _telephone, ref _audience, ref __50_50))
                {
                    player.get_score().add_points();
                    question_number++;
                    counter++;
                    if (question_number <= 12 && !keep_playing(ref player, ref surrender))
                    {
                        player.set_score(player.get_score().convert());
                        Console.WriteLine("Brawo! Wygrywasz " + player.get_score().get_score() + " zl!\n");
                        break;
                    }
                }

                else
                    correct = false;

            } while (correct && question_number <= 12);

            if (surrender == false)
            {
                player.set_score(player.get_score().convert());
                Console.Clear();

                if (player.get_score().get_score() == 1000000)
                    Console.WriteLine("Gratulacje! Wygrywasz MILION zlotych!\n");

                else if (player.get_score().get_score() == 0)
                    Console.WriteLine("Niestety, tym razem pozostajesz z pustymi rekami. Zawsze mozesz sprobowac zagrac jeszzce raz :)\n");
                else
                {
                    player.get_score().safety_nets();
                    if (player.get_score().get_score() == 0)
                        Console.WriteLine("Niestety, tym razem pozostajesz z pustymi rekami. Zawsze mozesz sprobowac zagrac jeszzce raz :)\n");
                    else
                        Console.WriteLine("Brawo! Wygrywasz " + player.get_score().get_score() + " zl!\n");
                }

            }

            Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
            Console.ReadKey();
            Console.Clear();

            end(ref player, ref s, ref l);
        }

        public bool keep_playing(ref Player player, ref bool surrender)
        {
            int tmp = player.get_score().convert();
            char choice = ' ';
            bool correct_option = false;
            do
            {
                Console.WriteLine("Czy chcesz grac dalej? Wybierz 1, aby grac dalej. W przeciwnym przypadku wybierz podowlny znak. Jesli zrezygnujesz teraz, mozesz zatrzymac {0} zl.\n", tmp);
                Console.WriteLine("Twoja decyzja: ");
                string input = Console.ReadLine();
                if (string.IsNullOrEmpty(input))
                {
                    Console.WriteLine("Podaj opcje!");
                    Console.WriteLine("Wcisnij dowolny klawisz aby kontynuowac.");
                    Console.ReadKey();
                    Console.Clear();
                }
                else
                {
                    choice = input[0];
                    correct_option = true;
                }
            } while (!correct_option);

            Console.Clear();

            if (choice == '1')
                return true;
            else
            {
                surrender = true;
                return false;
            }
        }
        public void end(ref Player player, ref Stats s, ref MyList l)
        {
            if (player.get_score().get_score() != 0)
                s.add(ref player);
            s.save_stats();
            l.delete_list();
        }
    }
}
