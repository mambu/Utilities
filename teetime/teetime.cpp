#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

int main(int argc, char* argv[])
{
   bool append = true;
   std::ios_base::openmode mode = std::ios_base::out;
   if (append)
      mode |= std::ios_base::app;
   std::ofstream file("teetime.out", mode);
   std::string line;
   char buffer [80];
   while (getline(std::cin, line))
   {
      time_t now;
      struct tm * timeinfo;

      time(&now);
      timeinfo = localtime ( &now );

      strftime (buffer, 80, "[%X] ", timeinfo);
      std::cout << buffer << line << std::endl;
      file << buffer << line << std::endl;
   }
   return 0;
}

