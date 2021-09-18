//
//  main.cpp
//  quadr._Gleichungen_Lösen
//
//  Created by Matthias Meierlohr & Jonas Hörter on 17.02.20.
//  Copyright © 2020 p l a n  MH  .exe . All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

char variable;

std::string input;

std::vector<std::string> addendsLeft;
std::vector<std::string> addendsRight;
std::vector<std::string> allAddends;
std::vector<std::string> numbersAddresses;

float rightNumber;

std::vector<float> allNumbers;

bool inputIsCorrect;

void CheckUserInput()
{
    int lastsign = input.length();
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != '1' && input[i] != '2' && input[i] != '3' && input[i] != '4' && input[i] != '5' && input[i] != '6' && input[i] != '7' && input[i] != '8' && input[i] != '9' && input[i] != '0' && input[i] != '/' && input[i] != '+' && input[i] != '-' && input[i] != '^' && input[i] != '=' && input[i] != 'x' && input[i] != ' ')
        {
            std::cout<<"// Error 1: Use of unknown sign '"<<input[i]<<"'"<<std::endl;
        }
            
    }
    
   if (input[lastsign] == '+' || input[lastsign] == '=' || input[lastsign] == '-')
   {
       std::cout<<"Error 2: Inconsistent line ending: '"<<input[lastsign]<<"'"<<std::endl;
   }
}

//  Diese Funktion nimmt den ersten erkannten Buchstaben als Variablennamen und ersetzt jeden dieser Buchstaben durch ein 'x'
void CustomVariables()
{
    int i = 0;
    
    do
    {
        if (input[i] == 'A' || input[i] == 'a' || input[i] == 'B' || input[i] =='b' || input[i] == 'C' || input[i] == 'c' || input[i] == 'D' || input[i] == 'd' || input[i] == 'E' || input[i] == 'e' || input[i] == 'F' || input[i] == 'f' || input[i] == 'G'  || input[i] == 'g'  || input[i] == 'H'  || input[i] == 'h'  || input[i] == 'I'  || input[i] == 'i'  || input[i] == 'J'   || input[i] == 'j'  || input[i] == 'K'  || input[i] == 'k'  || input[i] == 'L'  || input[i] == 'l'  || input[i] == 'M'  || input[i] == 'm'  || input[i] == 'N'  || input[i] == 'n'  || input[i] == 'O'  || input[i] == 'o'  || input[i] == 'P'  || input[i] == 'p'  || input[i] == 'Q'  || input[i] == 'q'  || input[i] == 'R'  || input[i] == 'r'  || input[i] == 'S'  || input[i] == 's'  || input[i] == 'T'  || input[i] == 't'  || input[i] == 'U'  || input[i] == 'V'  || input[i] == 'v'  || input[i] == 'W'  || input[i] == 'w'  || input[i] == 'X'  || input[i] == 'x'  || input[i] == 'Y'  || input[i] == 'y'  || input[i] == 'Z'  || input[i] == 'z')
        {
            variable = input[i];
            
            break;
        }
        
        i++;
    }
    while( input[i] != 'A' || input[i] != 'a' || input[i] != 'B' || input[i] !='b' || input[i] != 'C' || input[i] != 'c' || input[i] != 'D' || input[i] != 'd' || input[i] != 'E' || input[i] != 'e' || input[i] != 'F' || input[i] != 'f' || input[i] != 'G'  || input[i] != 'g'  || input[i] != 'H'  || input[i] != 'h'  || input[i] != 'I'  || input[i] != 'i'  || input[i] != 'J'   || input[i] != 'j'  || input[i] != 'K'  || input[i] != 'k'  || input[i] != 'L'  || input[i] != 'l'  || input[i] != 'M'  || input[i] != 'm'  || input[i] != 'N'  || input[i] != 'n'  || input[i] != 'O'  || input[i] != 'o'  || input[i] != 'P'  || input[i] != 'p'  || input[i] != 'Q'  || input[i] != 'q'  || input[i] != 'R'  || input[i] != 'r'  || input[i] != 'S'  || input[i] != 's'  || input[i] != 'T'  || input[i] != 't'  || input[i] != 'U'  || input[i] != 'V'  || input[i] != 'v'  || input[i] != 'W'  || input[i] != 'w'  || input[i] != 'X'  || input[i] != 'x'  || input[i] != 'Y'  || input[i] != 'y'  || input[i] != 'Z'  || input[i] != 'z');
    
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == variable)
        {
            input.replace(i, 1, "x");
        }
    }
    
    CheckUserInput();
}

//  Diese Funktion ergänzt fehlende Zahlen, z.B. x = 1x
void HandleOnlyXs()
{
    bool rewrite = false;
    
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == 'x')
        {
            if (i == 0)
            {
                rewrite = true;
            }
            else if (input[i-1] == '+' || input[i-1] == '=')
            {
                rewrite = true;
            }
            
            if (rewrite == true)
            {
                input.insert(i, "1");
            }
        }
        
        rewrite = false;
    }
}

//    Für Ausdrücke wie x/3
void RewriteX()
{
    std::string divisorS;
    std::string dividendS;
    std::string replaceholder;
    std::string text;
    
    float divisorF;
    float divivdendF;
    float factor;
    
    int y = 0;
    int z = 0;
    
    bool thereIsX = false;


    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '/')
        {
            divisorS = "";
            dividendS = "";
            text = "";
            replaceholder = "";
            divisorF = 0.0;
            divivdendF = 0.0;
            factor = 0.0;
    
            y = i + 1;
            
            if (input[i-1] == 'x')
            {
                z = i - 2;
                thereIsX = true;
            }
            else if (input[i-1] != 'x')
            {
                z = i - 1;
            }
            
            do
            {
                divisorS += input[y];
                y++;
            }
            while (input[y] != ' ' && y <= input.length() );
            
            do
            {
                dividendS += input[z];
                z--;
            }
            while (input[z] != ' ' && z >= 0);
        
            
            if (thereIsX == true)
            {
                 text = dividendS + input[i-1] + input[i] + divisorS;
            }
            else
            {
                 text = dividendS + input[i] + divisorS;
            }
                       
            divisorF = std::stof(divisorS);
            divivdendF = std::stof(dividendS);
            
            factor = divivdendF/divisorF;
            
            if (thereIsX == true)
            {
                replaceholder = std::to_string(factor) + "x ";
            }
            else
            {
                replaceholder = std::to_string(factor);
            }

            input.replace(z + 1, text.length() + 1, replaceholder);

        }
    }
    
}

// Diese Funktion setzt fehlende Leerzeichen ein und löscht überflüssige Leerzeichen
void CleanUpInput()
{
    bool replace = false;
    
    CustomVariables();
    
//    Diese Schleife löscht alle Leerzeichen
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
        {
            input.erase(i, 1);
        }
    }
    
//    Diese Schleife tauscht alle Minuszeichen, die als Rechenoperator gelten, durch Pluszeichen aus und ändert das Vorzeichen
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '-')
        {
            if (i == 0)
            {
                replace = false;
            }
            
            else if (input[i+1] == '-')
            {
                replace = true;
            }
            
            else if (input[i-1] == '-' || input[i-1] == '+' || input[i-1] == '=')
            {
                replace = false;
            }
            
            else if (input[i-1] != '-' || input[i-1] != '+' || input[i-1] != '=')
            {
                replace = true;
            }
            
            if (replace == true)
            {
                input.replace(i, 1, "+");
                
                if (input[i+1] == '-')
                {
                    input.erase(i + 1, 1);
                }
                
                else if (input[i+1] != '-')
                {
                    input.insert(i + 1, "-");
                }
            }
        }
        replace = false;
    }
  
    HandleOnlyXs();

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '+' || input[i] == '=')
        {
            if (input[i-1] != ' ')
            {
                input.insert(i - 1, " ");
            }
            
            if (input[i+1] != ' ')
            {
                input.insert(i + 1, " ");
            }
        }
    }
    
    RewriteX();

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ' && input[i+1] != '+' && input[i-1] != '+' && input[i+1] != '=' && input[i-1] != '=')
        {
            input.erase(i, 1);
        }
    }
}

//  Diese Funktion schreibt alle Summanden entsprechend ihrer Position zum Gleichheitszeichen in entsprechenden std::vector
void GetAddends()
{
    std::string placeholder;
    
    bool equalsign = false;
    
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '+' || input[i+1] == '+' || input[i-1] == '+')
        {
            if (input[i+1] == '+')
            {
                if (equalsign == false)
                {
                    addendsLeft.push_back(placeholder);
                }
                else if (equalsign == true)
                {
                    addendsRight.push_back(placeholder);
                }
                placeholder = "";
            }
            
            continue;
        }
        
        if (input[i]== '=' || input[i+1] == '=' || input[i-1] == '=')
        {
            if (input[i+1] == '=')
            {
                equalsign = true;
                
                addendsLeft.push_back(placeholder);
                
                placeholder = "";
            }
            
            continue;
        }
        
        placeholder += input[i];
    }
    
    addendsRight.push_back(placeholder);
}
//Diese Funktion tauscht die Vorzeichen, falls die Summanden auf der falschen Seite der Gleichung stehen
void ChangeSign()
{
    std::string text;
    
    bool thereIsX = false;
    
//  for addendsLeft:
    for (int i = 0; i < addendsLeft.size(); i++)
    {
        text = addendsLeft[i];
        
        for (int x = 0; x < text.length(); x++)
        {
            if (text[x] == 'x')
            {
                thereIsX = true;
            }
        }
        
        if (thereIsX == false)
        {
            if (text[0] == '-')
            {
                text.erase(0,1);
            }
            else if (text[0] != '-')
            {
                text.insert(0, "-");
            }
            
            addendsLeft[i] = text;

        }
        
        thereIsX = false;
    }
    
//    for addendsRight:
    for (int i = 0; i < addendsRight.size(); i++)
    {
        text = addendsRight[i];
        
        for (int x = 0; x < text.length(); x++)
        {
            if (text[x] == 'x')
            {
                thereIsX = true;
            }
        }
        
        if (thereIsX == true)
        {
            if (text[0] == '-')
            {
                text.erase(0,1);
            }
            else if (text[0] != '-')
            {
                text.insert(0, "-");
            }
            
            addendsRight[i] = text;

        }
        
        thereIsX = false;
    }
    
    for (int i = 0; i < addendsLeft.size(); i++)
    {
        allAddends.push_back(addendsLeft[i]);
    }
    
    for (int i = 0; i < addendsRight.size(); i++)
    {
        allAddends.push_back(addendsRight[i]);
    }
   

    addendsLeft.clear();
    addendsRight.clear();
}

void SortAddends()
{
    std::string text;
    std::string numberS;
    std::string address;
    std::string firstAddressPart = "x^";
    std::string secondAddressPart;
    
    float numberF;
    
    bool thereIsX = false;
    bool thereIsNoX = true;
    bool thereIsExponent = false;
    bool alreadyExists = false;
    
    for (int i = 0; i < allAddends.size(); i++)
    {
        numberS = "";
        address = "";
        secondAddressPart = "";
        numberF = 0.0;
        thereIsX = false;
        thereIsNoX = true;
        thereIsExponent = false;
        alreadyExists = false;
        
        text = allAddends[i];
        
        
        for (int x = 0; x < text.length(); x++)
        {
            if (text[x] != 'x' && thereIsX == false)
            {
                numberS += text[x];
            }
            else if (text[x] == 'x')
            {
                thereIsX = true;
                thereIsNoX = false;
            }
            else if (text[x] != 'x' && thereIsX == true)
            {
                thereIsExponent = true;
                
                if (text[x] == '^')
                {
                    continue;
                }
                
                if (text[x] != '^')
                {
                    secondAddressPart += text[x];
                }
            }
        }
        
        numberF = std::stof(numberS);
        
        address = firstAddressPart + secondAddressPart;
        
        if (thereIsNoX == true)
        {
            rightNumber += numberF;
        }
        
        if (thereIsX == true && thereIsExponent == false)
        {
            address = "x^1";
            
            for (int y = 0; y < numbersAddresses.size(); y++)
            {
                if (address == numbersAddresses[y])
                {
                    allNumbers[y] += numberF;
                    alreadyExists = true;
                    break;
                }
            }
            
            if (alreadyExists == false)
            {
                allNumbers.push_back(numberF);
                numbersAddresses.push_back(address);
            }
            alreadyExists = false;
        }
        
        if (thereIsExponent == true)
        {
            for (int y = 0; y < numbersAddresses.size(); y++)
            {
                if (address == numbersAddresses[y])
                {
                    allNumbers[y] += numberF;
                    alreadyExists = true;
                    break;
                }
            }
            
            if (alreadyExists == false)
            {
                allNumbers.push_back(numberF);
                numbersAddresses.push_back(address);
            }
            alreadyExists = false;
        }
    }

}

void Rebuilt()
{
    std::string addend;
        
    input = "";
    
    for (int i = 0; i < numbersAddresses.size(); i++)
    {
        
        addend = std::to_string(allNumbers[i]) + numbersAddresses[i];
        
        for (int x = 0; x < addend.length(); x++)
        {
            if (addend[x] == '1' && addend[x-1] == '^' && x == addend.length())
            {
                addend.erase(x - 1, 2);
            }
        }
        
        input += addend + " + ";
 
    }
    
    input.replace(input.length()-2, 1, "=");
    input += std::to_string(rightNumber);
    
}

void Simplify()
{
    GetAddends();
    
    ChangeSign();
    
    SortAddends();
    
    Rebuilt();
}

void CleanUpVectors()
{
    for (int i = 0; i < allNumbers.size(); i++)
    {
        if (allNumbers[i] == 0.000000)
        {
            allNumbers.erase(allNumbers.begin() + i);
            numbersAddresses.erase(numbersAddresses.begin() + i);
        }
    }
}

void QuadraticEquation()
{
    float a = 0.0;
    float b = 0.0;
    float c = 0.0;
    float discriminant = 0.0;
    float solution1 = 0.0;
    float solution2 = 0.0;
    
    for (int i = 0; i < numbersAddresses.size(); i++)
    {
        if (numbersAddresses[i] == "x^1")
        {
            b = allNumbers[i];
        }
        else if (numbersAddresses[i] == "x^2")
        {
            a = allNumbers[i];
        }
    }
    
    c = rightNumber * -1;
    
    discriminant = pow(b, 2) - (4 * a * c);
    
    if (discriminant < 0)
    {
        std::cout<<"\t\t Es gibt keine Loesung."<<std::endl;
    }
    else if (discriminant == 0)
    {
        solution1 = (-1 * b) / (2 * a);
        
        std::cout<<"\t\t x = "<<solution1<<std::endl;
    }
    else if (discriminant > 0)
    {
        solution1 = (-1 * b - sqrt(discriminant)) / (2 * a);
        solution2 = (-1 * b + sqrt(discriminant)) / (2 * a);

        std::cout<<"\t\t"<<variable<<"1 = "<<solution1<<std::endl<<std::endl;
        std::cout<<"\t\t"<<variable<<"2 = "<<solution2<<std::endl;
    }
}

void LinearEquation()
{
    std::string xOperator;
    std::string exponent;
    
    float number;
    float secondPowOperator;
    float solution = 0.0;
    
    bool write = false;
    
    xOperator = numbersAddresses[0];

    number = allNumbers[0];
    
    for (int i = 0; i < xOperator.length(); i++)
    {
        if (write == true)
        {
            exponent += xOperator[i];
        }
        
        if (xOperator[i] == '^')
        {
            write = true;
        }
    }
    
    secondPowOperator = 1 / std::stof(exponent);
    
    solution = rightNumber / number;
    
    solution = pow(solution, secondPowOperator);
    
    std::cout<<std::endl<<"\t\t"<<variable<<" = "<<solution<<std::endl;
}

// Diese Funktion analysiert die Eingabe und entscheidet, welches Lösungsverfahren angewendet werden muss.
void SolveEquations()
{
    bool xSquare = false;
    bool xSingle = false;
    
    std::cout << "";
    std::cout << "Tippen Sie eine Geleichung ein, die nach \"x\" aufgeloest wird:\n";
    std::cout << "Beispiel: \"ax^2 + bx + c = 0\"\n\n\t\t";

    std::getline(std::cin, input);
    
    CleanUpInput();
    Simplify();
    CleanUpVectors();
    
    for (int i = 0; i < numbersAddresses.size(); i++)
    {
        if (numbersAddresses[i] == "x^1")
        {
            xSingle = true;
        }
        else if (numbersAddresses[i] == "x^2")
        {
            xSquare = true;
        }
    }
    
    if (xSquare == true && xSingle == true)
    {
        QuadraticEquation();
    }
    
    if (numbersAddresses.size() == 1)
    {
        LinearEquation();
    }
    
}

int main()
{
    SolveEquations();
    
    //system("pause");
    
    return 0;
}



/*
    22x^2 + 23x + 24 = 0
*/

// void ChemicalEquation ();

// Erst Gleichung sotieren: x links vom '=' nicht x nach rechts
// Analysieren: ~ Wenn x^2 + x dann quadraticEquation
//              ~ Nur x oder x^2 dann linearEquation mit entsprechendem Lösungsansatz
