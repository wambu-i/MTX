#ifndef MTX_CONFIG_H
#define MTX_CONFIG_H
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <sorting.hpp>
#include <directories.hpp>
#include <globals.hpp>


using json = nlohmann::json;
class Directories;
class Sorting;

class Config : public Globals  {
    public:
        Config(std::string &path);
        ~Config();
        std::fstream configFile;

    private:
        std::string configFileName;
        struct dir_entry {
            std::string name;
            std::vector<std::string> subdirs;
            };
        void initialize(std::string);
        void update_config(std::string, std::string, std::vector<std::string>);
        /* json create_new_entry(dir_entry *);
        json create_new_entry(const std::string, std::vector<json>); */
        json create_new_entry(std::string day, FILE_OBJ file);
        FILE_OBJ *construct_file_entry(std::string);
        void create_entries(Sorting *sort, Directories *dir);


};
#endif
