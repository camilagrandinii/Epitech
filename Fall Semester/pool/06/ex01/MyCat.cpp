#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
    std::string fileContent;
    int count = 1;

    if (argc > 1)
    {
        while(count < argc){
        std::ifstream ifs(argv[count]);
            if (!ifs.is_open())
            {
                std::cerr << "MyCat : " << argv[1] << " : No such file or directory";
                return(84);
            }
            
            std::getline(ifs, fileContent);
            while (!ifs.eof()){
                std::cout << fileContent << std::endl;
                std::getline(ifs, fileContent);
            }
            ifs.close();
            count++;
        }
    }
    else{
        while(true){
            std::cin >> fileContent;
            std::cout << fileContent << std::endl;
        }
    }
    return 0;
}