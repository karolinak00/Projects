using System;
using System.Collections.Generic;
using System.Text;

namespace tic_tac_toe
{
    class Grid
    {
        // private
        private char[,] grid = new char[4, 4];

        // constructor & destructor
        public Grid()
        {
            init_grid();
        }
        ~Grid() { }

        // other methods
        public void init_grid()
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i == 0 && j == 0)
                        grid[i, j] = ' ';
                    else if (i == 0)
                    {
                        if (j == 1)
                            grid[i, j] = 'A';
                        else if (j == 2)
                            grid[i, j] = 'B';
                        else
                            grid[i, j] = 'C';
                    }
                    else if (j == 0)
                    {
                        grid[i, j] = Convert.ToChar(i + 48);
                    }
                    else
                        grid[i, j] = ' ';
                }
            }
        }

        public bool correct_co_operates(int column_nr, int row_nr)
        {
            if (grid[row_nr, column_nr] == ' ')
                return true;
            else
            {
                Console.WriteLine("This square is already taken! Choose another one!");
                return false;
            }
        }

        public bool correct_column(char column_nr)
        {
            if (Char.ToUpper(column_nr) == 'A' || Char.ToUpper(column_nr) == 'B' || Char.ToUpper(column_nr) == 'C')
                return true;
            else
            {
                Console.WriteLine("Choose correct option!");
                return false;
            }

        }

        public bool correct_row(int row_nr)
        {
            if (row_nr >= 1 && row_nr <= 3)
                return true;
            else
            {
                Console.WriteLine("Choose correct option!");
                return false;
            }
        }

        public void mark(Player player1)
        {
            char column_nr; // column number (A, B or C)
            int column_number; // numeric column number; equals 1 if player entered 'A', 2 if player entered 'B' and 3 if player entered 'C'
            int row_nr; // row number

            do
            {
                do
                {
                    Console.WriteLine("Enter the row number:");
                    string row = Console.ReadLine();
                    Int32.TryParse(row, out row_nr);
                } while (!correct_row(row_nr));

                do
                {
                    Console.WriteLine("Enter the column number:");
                    string column = Console.ReadLine();
                    column_nr = Convert.ToChar(column);
                } while (!correct_column(column_nr));
                column_number = convert_column_nr(ref column_nr);
            } while (!correct_co_operates(column_number, row_nr));
            if (player1.your_turn())
                grid[row_nr, column_number] = 'X';
            else
                grid[row_nr, column_number] = 'O';
        }

        public int convert_column_nr(ref char column_nr)
        {
            if (Char.ToUpper(column_nr) == 'A')
                return 1;
            else if (Char.ToUpper(column_nr) == 'B')
                return 2;
            else
                return 3;
        }

        public void print_grid()
        {
            for (int i = 0; i < 4; i++)
                Console.WriteLine("{0} {1} {2} {3}", grid[i, 0], grid[i, 1], grid[i, 2], grid[i, 3]);
        }
        public bool win(char sign)
        {
            if ((grid[1, 1] == sign && grid[2, 1] == sign && grid[3, 1] == sign) ||
                (grid[1, 2] == sign && grid[2, 2] == sign && grid[3, 2] == sign) ||
                (grid[1, 3] == sign && grid[2, 3] == sign && grid[3, 3] == sign) ||
                (grid[1, 1] == sign && grid[1, 2] == sign && grid[1, 3] == sign) ||
                (grid[2, 1] == sign && grid[2, 2] == sign && grid[2, 3] == sign) ||
                (grid[3, 1] == sign && grid[3, 2] == sign && grid[3, 3] == sign) ||
                (grid[1, 1] == sign && grid[2, 2] == sign && grid[3, 3] == sign) ||
                (grid[3, 1] == sign && grid[2, 2] == sign && grid[1, 3] == sign))
                return true;
            else
                return false;
        }

        public bool is_full()
        {
            int counter = 0; // counts empty sqaures
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (grid[i, j] == ' ')
                        counter++;
                }
            }
            if (counter == 1) // tab[0,0] = ' '
                return true;
            else
                return false;
        }

    }


}
