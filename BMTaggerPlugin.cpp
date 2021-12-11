#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BMTaggerPlugin.h"

void BMTaggerPlugin::input(std::string file) {
  inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void BMTaggerPlugin::run() {
   
}

void BMTaggerPlugin::output(std::string file) {
	//bmtagger.sh -b Mouse.bitmask -x Mouse.srprism -q1 -1 R1.fastq -2 R2.fastq -o sample.bmtagger.list
	std::string command = "bmtagger.sh -C "+std::string(PluginManager::prefix())+"/"+parameters["config"]+" -b "+std::string(PluginManager::prefix())+"/"+parameters["bitmask"]+" -x "+std::string(PluginManager::prefix())+"/"+parameters["srprism"]+" -q1 -1"+std::string(PluginManager::prefix())+"/"+parameters["forward"]+" -2 "+std::string(PluginManager::prefix())+"/"+parameters["reverse"]+" -o "+file;
        std::cout << command << std::endl;

 system(command.c_str());

}

PluginProxy<BMTaggerPlugin> BMTaggerPluginProxy = PluginProxy<BMTaggerPlugin>("BMTagger", PluginManager::getInstance());
