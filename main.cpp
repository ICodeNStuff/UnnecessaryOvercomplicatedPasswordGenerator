#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>
#include <ctime>
#include <cstdlib>
#include <random>
#include <string>


std::string gen_string()
{
    std::string first_gen = "abcdefgh";
    std::random_device rd;
    std::mt19937 gen(rd());
    unsigned short int choose_template;
    srand(time(NULL));
    choose_template = rand() % 5;
    if (choose_template == 5)
    {
        first_gen = "abcdefgh";
    }
    if (choose_template == 4)
    {
        first_gen = "abcdefghi";
    }
    if (choose_template == 3)
    {
        first_gen = "abcdefghij";
    }
    if (choose_template == 2)
    {
        first_gen = "abcdefghijk";
    }
    if (choose_template == 1)
    {
        first_gen = "abcdefghijkl";
    }
    if (choose_template == 0)
    {
        first_gen = "abcdefghijklm";
    }
    int randomize;
    std::uniform_int_distribution<> dis(0, 100);
    for (int i = 0; i < first_gen.length(); i++)
    {
        srand(time(NULL));
        randomize = rand() % 100;
        first_gen[i] += (char)dis(gen);
        randomize = rand() % 100;
    }

    std::hash<std::string>hasher;
    size_t hash = hasher(first_gen);
    
    //first_gen = hash;
    //  std::cout << hash;
    first_gen = std::to_string(hash);
    //std::cout << first_gen;
    std::uniform_int_distribution<> genc(0, 80);
    std::uniform_int_distribution<> num1(0, 8);
    std::uniform_int_distribution<> num2(0, 6);
    std::uniform_int_distribution<> num3(0, 2);
    std::uniform_int_distribution<> num4(0, 7);
    for (int j = 0; j < first_gen.length(); j++)
    {
        if (first_gen[j] == '1')
        {
            first_gen[j] += (char)num1(gen);
        }
        else
            if (first_gen[j] == '3')
            {
                first_gen[j] += (char)num2(gen);
            }
            else
                if (first_gen[j] == '7')
                {
                    first_gen[j] += (char)num3(gen);
                }
                else
                    if (first_gen[j] == '2')
                    {
                        first_gen[j] += (char)num4(gen);
                    }
                    else
                        first_gen[j] += (char)genc(gen);

    }
   // std::cout << first_gen;
    return first_gen;
}

int main(void)
{

    std::string s1, s2, s3;
    s1 = gen_string();
    s2 = gen_string();
    s3 = s1 + s2;
   
    std::cout << s3 << "\n";
    
    
        

   

    
    return 0;
}
