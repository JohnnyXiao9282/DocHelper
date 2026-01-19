#pragma once
#include <string>
#include <vector>
#include <ctime>

namespace docstore {

struct Document {
    int id;
    std::string title;
    std::string path;
    std::vector<std::string> tags;
    std::time_t created;
    std::string content;

    Document() = default;
    Document(int id_, const std::string& title_, const std::string& path_,
             const std::vector<std::string>& tags_, std::time_t created_, const std::string& content_)
        : id(id_), title(title_), path(path_), tags(tags_), created(created_), content(content_) {}
};

} // namespace docstore
