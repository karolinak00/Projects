using System;
using System.Collections.Generic;
using System.Text;

namespace who_wants_to_be_a_millionaire
{
    class Score
    {
        // private

        private int score;

        // constructor & destructor
        public Score()
        {
            score = 0;
        }
        ~Score() { }

        // getters
        public int get_score()
        {
            return score;
        }

        // setters
        public void set_score(int new_score)
        {
            score = new_score;
        }
        
        public void add_points()
        {
            score++;
        }
        
        // other methods
        public void safety_nets()
        {
            if (score >= 40000) // prog gwarantowany
                score = 40000;
            else if (score >= 1000) //prog gwarantowany
                score = 1000;
            else
                score = 0;
        }
        public int convert()
        {
            if (score == 0)
                return 0;

            else if (score == 1)
                return 500;

            else if (score == 2)
                return 1000;

            else if (score == 3)
                return 2000;

            else if (score == 4)
                return 5000;

            else if (score == 5)
                return 10000;

            else if (score == 6)
                return 20000;

            else if (score == 7)
                return 40000;

            else if (score == 8)
                return 75000;

            else if (score == 9)
                return 125000;

            else if (score == 10)
                return 250000;

            else if (score == 11)
                return 500000;

            else
                return 1000000;
        }

    }
}
