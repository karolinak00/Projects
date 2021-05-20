using System;
using System.Collections.Generic;
using System.Text;

namespace tic_tac_toe
{
    class functions
    {
        // private
        Player player1 = new Player();
        Player player2 = new Player();
        Grid grid = new Grid();
        Game game = new Game();

        // constructor & destructor
        public functions() { }
        ~functions() { }

       // other methods

        public void print_instruction()
        {
            Console.WriteLine("The game is played on a grid that's 3 squares by 3 squares.");
            Console.WriteLine("First player is X, second player is O. You take turns putting your marks in empty squares.");
            Console.WriteLine("The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.");
            Console.WriteLine("When all 9 squares are full, the game is over.If no player has 3 marks in a row, the game ends in a tie.");
            Console.WriteLine("\nPress any key to continue");
            Console.ReadKey();
        }

        public void menu()
        {
            bool correct = false;
            int choice = 0;
            do
            {
                do
                {
                    Console.Clear();
                    Console.WriteLine("Press 1 to play.");
                    Console.WriteLine("Press 2 to read instruction.");
                    Console.WriteLine("Press 3 to end game.\n");
                    string readLine = Console.ReadLine();
                    if (!Int32.TryParse(readLine, out choice))
                        Console.WriteLine("Enter correct option!");
                    if (choice != 1 && choice != 2 && choice != 3)
                        Console.WriteLine("Enter correct option!");
                    else
                        correct = true;
                } while (!correct);
                switch (choice)
                {
                    case 1:
                        Console.Clear();
                        game.init_game(ref player1, ref player2, ref grid);
                        break;

                    case 2:
                        Console.Clear();
                        print_instruction();
                        break;

                    case 3:
                        Console.Clear();
                        Console.WriteLine("Thanks for playing :) See you soon!\n");
                        break;
                }
            } while (choice != 3);

        }

    }
}
