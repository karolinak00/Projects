using System;
using System.Collections.Generic;
using System.Text;

namespace who_wants_to_be_a_millionaire
{
    class Player
    {
        // private

        private string name;
        private string surname;
        private Score score;

        // constructors & destructor
        public Player()
        {
            score = new Score();
        }

        public Player(Player p)
        {
            name = p.name;
            surname = p.surname;
            score = p.score;
        }

        ~Player() { }

        //getters

        public Score get_score()
        {
            return score;
        }
        public string get_name()
        {
            return name;
        }
        public string get_surname()
        {
            return surname;
        }

        // setters
        public void add_points()
        {
            score.add_points();
        }

        public void set_score(int new_score)
        {
            score.set_score(new_score);
        }
        public void set_name(string n)
        {
            name = n;
        }
        public void set_surname(string s)
        {
            surname = s;
        }

        // other methods
        public void introduce_yourself()
        {
            string n;
            string s;
            bool correct = false; // true if name/surname is correct

            while (!correct)
            {
                Console.WriteLine("Podaj imie:");
                n = Console.ReadLine();
                if (string.IsNullOrEmpty(n))
                {
                    Console.Clear();
                    Console.WriteLine("Prosze podac imie.\n\nWcisnij dowolny klawisz aby kontynuuowac.");
                    Console.ReadKey();
                    Console.Clear();
                }

                else if (!correct_name(n))
                {
                    Console.Clear();
                    Console.WriteLine("Prosze podac poprawne imie.\n\nWcisnij dowolny klawisz aby kontynuuowac.");
                    Console.ReadKey();
                    Console.Clear();
                }
                else
                {
                    set_name(n);
                    correct = true;
                }

            }

            correct = false;
            while (!correct)
            {
                Console.WriteLine("Podaj nazwisko:");
                s = Console.ReadLine();

                if (string.IsNullOrEmpty(s))
                {
                    Console.Clear();
                    Console.WriteLine("Prosze podac imie.\n\nWcisnij dowolny klawisz aby kontynuuowac.");
                    Console.ReadKey();
                    Console.Clear();
                }

                else if (!correct_name(s))
                {
                    Console.Clear();
                    Console.WriteLine("Prosze podac poprawne imie.\n\nWcisnij dowolny klawisz aby kontynuuowac.");
                    Console.ReadKey();
                    Console.Clear();
                }
                else
                {
                    set_surname(s);
                    correct = true;
                }


            }
        }
        public bool correct_name(string name)
        {
            int counter = 0;
            for (int i = 0; i < name.Length; i++)
            {
                if (!Char.IsLetter(name[i]))
                    counter++;
            }

            if (counter != 0)
                return false;
            else
                return true;
        }

    }
}
