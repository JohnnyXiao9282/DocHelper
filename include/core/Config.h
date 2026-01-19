#pragma once
#include <string>

namespace docstore {

struct Config {
    std::string dataPath = "data/documents/";
    std::string indexPath = "data/index/";
    std::string metadataPath = "data/metadata/";
    int maxDocuments = 10000;
};

} // namespace docstore
