#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <config.hpp>


Config::Config(std::string &path):
  configFileName(path) {
      this->initialize(path);
}

Config::~Config(){
  //  delete configFile;
}


void Config::initialize(std::string path) {
    json config = json({});
    std::string username = user;
    config["user"] = username;
    configFile.open(path, std::fstream::in | std::fstream::out | std::fstream::app);
    if (configFile) {
        configFile << config;
        std::cout << "Config file present.\nNot creating a new one.\n" << std::endl;
        configFile.close();
    }
    else {
        std::cout << "No config file found.\nCreating a new one.\n" << std::endl;
        configFile.open(configFileName, std::fstream::in | std::fstream::out | std::fstream::trunc);
        configFile << config;
    }
    configFile.close();

}

FILE_OBJ *Config::construct_file_entry(std::string location) {
    FILE_OBJ *file;
    int freq = 1;

    *file = std::make_tuple(location, freq);
    return file;
}

void Config::create_entries(Sorting *sort, Directories *dir){
    std::vector<file_info> *temp = sort->create_info();
    FILE_OBJ *tmp;
    for (auto &file: *temp) {
        tmp = construct_file_entry(file.location);
        create_new_entry(file.accessed_on, *tmp);
    }

}

json Config::create_new_entry(std::string day, FILE_OBJ file) {
    json arr = json::array();
    arr.push_back(file);
    return arr;
}

/* json Config::create_new_entry(dir_entry *entry) {
  json dir;
  dir["dir"] = entry->name;
  json arr = json::array();
  for (auto i = entry->subdirs.begin(); i != entry->subdirs.end(); i++) {
    arr.push_back(*i);
  }
  //arr = json::parse(entry->subdirs.begin(), entry->subdirs.end());
  dir["subdirs"] = arr;
  return dir;
}

json Config::create_new_entry(const std::string day, std::vector<json> entry) {
  json day_entry;
  json arr = json::array();
  for (auto i = entry.begin(); i != entry.end(); i++) {
    arr.push_back(*i);
  }
  //arr = json::parse(entry);
  day_entry[day] = arr;

  return day_entry;
}
 */
