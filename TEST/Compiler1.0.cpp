#include <iostream>
#include <fstream>

std::ifstream::pos_type filesize(std::string logfile)
{
    std::ifstream in(logfile, std::ifstream::ate | std::ifstream::binary);
    return in.tellg(); 
}

int main() {
    std::ifstream in;
    std::ofstream out;
    std::ofstream in_log;
    std::ofstream out_log;

    std::string file;
    std::getline(std::cin, file);
    std::string logfile = file.substr(0, file.find_last_of('.')) + "_LOG.txt";

    out_log.open(logfile);

    in.open(file);
    if(in.fail()) out_log << "Error: " << "Could not open " << file << std::endl; exit(1);

    std::string line;



//________________________ [ END ] ________________________//
    in.close();
    out.close();
    out_log.close();

    if(filesize(file) > 0) {
        in_log.open(logfile);
        std::string log_line;
        while(in_log) {
            log_line.clear();
            std::getline(in_log, log_line);
        }
    }

    
    in_log.close();

    return 0;
}