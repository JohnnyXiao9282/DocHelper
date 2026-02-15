
#include <iostream>
#include <ctime>
#include "core/DocumentStore.h"
#include "cli_util.h"

using namespace docstore;

int main() {
    DocumentStore store;
    std::cout << "DocHelper CLI starting..." << std::endl;
    while (true) {
        printMenu();
        std::string choice;
        std::getline(std::cin, choice);
        if (choice == "1") {
            Document doc;
            doc.title = input("Title: ");
            doc.path = input("Path: ");
            std::string tags = input("Tags (comma separated): ");
            size_t pos = 0, prev = 0;
            while ((pos = tags.find(',', prev)) != std::string::npos) {
                doc.tags.push_back(tags.substr(prev, pos - prev));
                prev = pos + 1;
            }
            if (!tags.substr(prev).empty()) doc.tags.push_back(tags.substr(prev));
            doc.created = std::time(nullptr);
            doc.content = input("Content: ");
            int id = store.addDocument(doc);
            std::cout << "Document added with ID: " << id << "\n";
        } else if (choice == "2") {
            auto docs = store.getAllDocuments();
            std::cout << "\nAll Documents (" << docs.size() << "):\n";
            for (const auto* doc : docs) {
                std::cout << "ID: " << doc->id << ", Title: " << doc->title << ", Path: " << doc->path << "\n";
            }
        } else if (choice == "3") {
            std::string tag = input("Enter tag to search: ");
            auto docs = store.searchByTag(tag);
            std::cout << "\nDocuments with tag '" << tag << "' (" << docs.size() << "):\n";
            for (const auto* doc : docs) {
                std::cout << "ID: " << doc->id << ", Title: " << doc->title << ", Path: " << doc->path << "\n";
            }
        } else if (choice == "0") {
            std::cout << "Exiting DocHelper CLI.\n";
            break;
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
