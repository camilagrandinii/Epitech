#include <iostream>
#include <iomanip>
#include <string>

double fahrenCelsiusConvert(float temperature, std::string scaleFrom)
{
    if (scaleFrom == "Celsius"){
        return ((temperature * 9.0 ) / 5.0 ) + 32;
    } else {
        return 5.0 / 9.0 * (temperature - 32);
    }
}

void extractLineConent(std::string str, std::string *extractedContent)
{
    std::string numberString;
    std::string scale;
    u_long count = 0;

    while (count < str.size()){
        if (str.at(count) != ' ' && (isdigit(str.at(count)) || str.at(count) == '-' || str.at(count) == '.')){
            numberString+=str.at(count);
        } else if(str.at(count) != ' '){
            scale+=str.at(count);
        }
        count++;
    }
    extractedContent[0] = numberString;
    extractedContent[1] = scale;
}

int main()
{
    std::string line;
    std::string scale;
    std::string array[] = {std::string("")};
    double temperature;

    getline(std::cin, line);
    while (!line.empty()){
        extractLineConent(line, array);

        temperature = std::stod(array[0]);
        scale = array[1];
        temperature = fahrenCelsiusConvert(temperature, array[1]);

        if(scale == "Celsius"){
            std::cout << std::setw(16) << std::fixed << std::setprecision(3) << std::setw(16) << temperature << "\t" << " Fahrenheit" << std::endl;
        } else {
           std::cout << std::setw(16) << std::fixed << std::setprecision(3) << std::setw(16) << temperature << "\t" << " Celsius" << std::endl;
        }
        getline(std::cin, line);
    }

    return 0;
}