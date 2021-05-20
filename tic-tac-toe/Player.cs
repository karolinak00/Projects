using System;
using System.Collections.Generic;
using System.Text;

namespace tic_tac_toe
{
    class Player
    {
        // private

        private string name;
        private int score;
        private bool turn;

        // constructor & destructor
        public Player()
        {
            score = 0;
            turn = false;
        }

        ~Player() { }

        // getters
        public string get_name()
        {
            return name;
        }

        public int get_score()
        {
            return score;
        }

        public bool your_turn()
        {
            return turn;
        }

        // setters
        public void set_name(string n)
        {
            name = n;
        }

        public void set_turn(bool t)
        {
            turn = t;
        }

        // other methods
        public void add_points()
        {
            score++;
        }

        public void introduce_yourself()
        {
            Console.WriteLine("Enter your name:");
            set_name(Console.ReadLine());
            Console.Clear();
        }
        public bool correct_name(string name1, string name2)
        {
            if (name2 == name1)
            {
                Console.WriteLine("This name has already been chosen.");
                return false;
            }

            else
                return true;
        }
    }
}
