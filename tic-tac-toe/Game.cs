using System;
using System.Collections.Generic;
using System.Text;

namespace tic_tac_toe
{
    class Game
    {
        // private
        private int numberOfRounds;

        // constructor & destructor
        public Game() { }
        ~Game() { }

        // getter
        public int get_noRounds()
        {
            return numberOfRounds;
        }

        // setter

        public void set_noRounds(int r)
        {
            numberOfRounds = r;
        }

        // other methods
        public void how_many_rounds()
        {
            int tmp;
            bool correct = false;
            do
            {
                Console.WriteLine("Enter number of rounds you want to play:");
                var readLine = Console.ReadLine();
                if (!Int32.TryParse(readLine, out tmp))
                    Console.WriteLine("Enter correct option!");
                else
                    correct = true;
            } while (!correct);
            set_noRounds(tmp);
            Console.Clear();
        }

        public bool game_over(ref Player player1, ref Player player2, ref Grid grid)
        {
            if (grid.win('O'))
            {
                Console.Clear();
                Console.WriteLine("{0} won this round.", player2.get_name());
                player2.add_points();
                Console.WriteLine("Press any key to continue");
                Console.ReadKey();
                Console.Clear();
                return true;
            }
            else if (grid.win('X'))
            {
                Console.Clear();
                Console.WriteLine("{0} won this round.", player1.get_name());
                player2.add_points(); ;
                Console.WriteLine("Press any key to continue");
                Console.ReadKey();
                Console.Clear();
                return true;
            }
            else
            {
                if (grid.is_full())
                {
                    Console.Clear();
                    Console.WriteLine("Round ended in a tie.");
                    Console.WriteLine("Press any key to continue");
                    Console.ReadKey();
                    Console.Clear();
                    return true;
                }
                else
                    return false;
            }

        }

        public void play(ref Player player1, ref Player player2, ref Grid grid)
        {
            Console.WriteLine("\nLet's play!\n");

            // draw who starts first:
            Random random = new Random();
            int rand = random.Next(0, 101);
            if (rand % 2 == 0)
            {
                player1.set_turn(true);
                player2.set_turn(false);
            }

            else
            {
                player2.set_turn(true);
                player1.set_turn(false);
            }

            // game:
            do
            {
                if (player1.your_turn())
                {
                    Console.Clear();
                    Console.WriteLine("Please hand over the game to {0}.\n", player1.get_name());
                    grid.print_grid();
                    grid.mark(player1);
                    player2.set_turn(true);
                    player1.set_turn(false);
                }
                else
                {
                    Console.Clear();
                    Console.WriteLine("Please hand over the game to {0}.\n", player2.get_name());
                    grid.print_grid();
                    grid.mark(player1);
                    player1.set_turn(true);
                    player2.set_turn(false);
                }

            } while (!game_over(ref player1, ref player2, ref grid));

        }


        public void init_game(ref Player player1, ref Player player2, ref Grid grid)
        {
            how_many_rounds();
            Console.Clear();
            Console.WriteLine("Please hand over the game to the first player.\n");
            player1.introduce_yourself();
            Console.Clear();
            Console.WriteLine("Please hand over the game to the second player.\n");
            do
            {
                player2.introduce_yourself();
            } while (!player2.correct_name(player1.get_name(), player2.get_name()));

            while (numberOfRounds > 0)
            {
                grid.init_grid(); // grid initialization
                play(ref player1, ref player2, ref grid);
                numberOfRounds--;
            }
            Console.Clear();
            if (player1.get_score() > player2.get_score())
                Console.WriteLine("Congratulations! {0} won this game!\n", player1.get_name());
            else if (player2.get_score() > player1.get_score())
                Console.WriteLine("Congratulations! {0} won this game!\n", player2.get_name());
            else
                Console.WriteLine("Game ended in a tie!\n");
            Console.WriteLine("\n{0}'s score: {1}, {2}'s score: {3}\n\n", player1.get_name(), player1.get_score(), player2.get_name(), player2.get_score());
            Console.WriteLine("Press any key to continue");
            Console.ReadKey();
            Console.Clear();
        }

    }
}
