using System;
using System.Collections.Generic;
using System.Text;

namespace who_wants_to_be_a_millionaire
{
    class Quiz
    {
        // private
        private string question;
        private string answerA;
        private string answerB;
        private string answerC;
        private string answerD;
        private char correct;

        // constructors & destructor
        public Quiz() { }
        public Quiz(string q, string A, string B, string C, string D, char c)
        {
            question = q;
            answerA = A;
            answerB = B;
            answerC = C;
            answerD = D;
            correct = c;
        }

        public Quiz(Quiz q)
        {
            question = q.question;
            answerA = q.answerA;
            answerB = q.answerB;
            answerC = q.answerC;
            answerD = q.answerD;
            correct = q.correct;
        }

        ~Quiz() { }

        // getters
        public char get_correct()
        {
            return correct;
        }
        public string get_question()
        {
            return question;
        }

        public string getA()
        {
            return answerA;
        }
        public string getB()
        {
            return answerB;
        }
        public string getC()
        {
            return answerC;
        }
        public string getD()
        {
            return answerD;
        }

        // setters
        public void set_correct(char c)
        {
            correct = c;
        }
        public void set_question(string q)
        {
            question = q;
        }

        public void setA(string a)
        {
            answerA = a;
        }
        public void setB(string b)
        {
            answerB = b;
        }
        public void setC(string c)
        {
            answerC = c;
        }
        public void setD(string d)
        {
            answerD = d;
        }
    }
}
