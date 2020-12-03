//
// Created by sorohimm on 02.12.2020.
//
//#include <header.h>
////namespace bfs = boost::filesystem;
//size_t find_art_beg(std::ifstream &wiki) {
//    std::string line;
//    size_t accum = 0;
//    getline(wiki, line);
//    while (line.find("<text") == std::string::npos) {
//        accum += line.size() + 1;
//        getline(wiki, line);
//    }
//    return accum;
//}
//
//void FormatArticle(std::string &article) {
//    // remove "'"
//    auto new_end = std::remove_if(article.begin(), article.end(),
//                                  [](const char c) { return c == '\''; });
//    article.resize(std::distance(article.begin(), new_end));
//    // remove links
//    while (article.find("[[") != std::string::npos) {
//        size_t link_beg = article.find("[[");
//        size_t link_end = link_beg + 2;
//        for (size_t brace_cnt = 2; brace_cnt > 0; ++link_end) {
//            switch (article[link_end]) {
//                case '[':
//                    ++brace_cnt;
//                    break;
//                case ']':
//                    --brace_cnt;
//                    break;
//            }
//        }
//        link_end -= 2;
//        // file links
//        if (article.substr(link_beg + 2, 4) == "File") {
//            article.erase(article.begin() + link_beg, article.begin() + link_end + 2);
//            continue;
//        }
//        // aliases
//        if (article.find('|') != std::string::npos &&
//            article.find('|') < link_end) {
//            link_end -= article.find('|') - link_beg + 1;
//            article.erase(article.begin() + link_beg,
//                          article.begin() + article.find('|') + 1);
//            article.erase(article.begin() + link_end, article.begin() + link_end + 2);
//            continue;
//        }
//        // simple
//        article.erase(article.begin() + link_beg, article.begin() + link_beg + 2);
//        article.erase(article.begin() + link_end - 2, article.begin() + link_end);
//    }
//    // remove quotes
//    while (article.find("&quot") != std::string::npos) {
//        article.erase(article.begin() + article.find("&quot;"));
//        article.erase(article.begin() + article.find("&quot;") + 6);
//    }
//    // remove headers
//    while (article.find("==") != std::string::npos) {
//        size_t hdr_lvl = article.find("==");
//        while (article[hdr_lvl] == '=') {
//            ++hdr_lvl;
//        }
//        hdr_lvl -= article.find("==") - 1;
//        article.erase(article.begin() + article.find("=="),
//                      article.begin() + article.find("==") + hdr_lvl);
//        article.erase(article.begin() + article.find("==") - 1,
//                      article.begin() + article.find("==") + hdr_lvl - 1);
//    }
//    // remove inserts
//    while (article.find("{{") != std::string::npos) {
//        article.erase(article.begin() + article.find("{{"),
//                      article.begin() + article.find("}}") + 2);
//    }
//    // remove subheaders
//    while (article.find('*') != std::string::npos) {
//        size_t hdr_lvl = article.find('*');
//        while (article[hdr_lvl] == '*') {
//            ++hdr_lvl;
//        }
//        hdr_lvl -= article.find('*');
//        size_t hdr_pos = article.find('*');
//        article.erase(article.begin() + hdr_pos,
//                      article.begin() + hdr_pos + hdr_lvl);
//        hdr_pos -= hdr_lvl;
//        if (article.find('_', hdr_pos) < article.find('\n', hdr_pos)) {
//            continue;
//        }
//        article.erase(article.begin() + article.find('_', hdr_pos) - 1,
//                      article.begin() + article.find('_', hdr_pos) + 1);
//    }
//}
//
//
//
//
//int main(int argc) {
//    if (argc < 1) {
//        return 0;
//    }
//    std::ifstream wiki("/Users/sorohimm/CLionProjects/untitled2/wiki.txt");
//    if (!wiki.is_open()) {
//        std::cerr << "Failed to open wiki" << std::endl;
//    }
//    wiki.seekg(find_art_beg(wiki
//    ), std::ios::beg);
//    std::string articles_head;
//    getline(wiki, articles_head);
//    size_t artsize_beg = articles_head.find("bytes=") + 7;
//    size_t artsize = std::stoi(
//            articles_head.substr(artsize_beg, articles_head.find('"', artsize_beg)),
//            nullptr);
//    std::string article;
//    article.reserve(artsize);
//// read
//    std::copy_n(std::istreambuf_iterator<char>(wiki), artsize,
//                std::back_inserter(article));
//    FormatArticle(article);
//    std::cout << article << std::endl;
//
//}

//#include <header.h>
//
//void FormatArticle(std::string &article) {
//    // remove
//    auto new_end = std::remove_if(article.begin(), article.end(),
//                                  [](const char c) { return c == '\''; });
//    article.resize(std::distance(article.begin(), new_end));
//    // remove
//    article.erase(std::remove_if(std::begin(article), std::end(article),
//                                 [](auto num) { return std::isdigit(num); }),
//                  article.end());
//
//    while (article.find("&quot") != std::string::npos) {
//        article.erase(article.begin() + article.find("&quot;"));
//        article.erase(article.begin() + article.find("&quot;") + 6);
//    }
//
//    while (article.find("{{") != std::string::npos) {
//        article.erase(article.begin() + article.find("{{"),
//                      article.begin() + article.find("}}") + 2);
//    }
//
//}
//int main() {
//    std::ifstream wiki("/Users/sorohimm/CLionProjects/untitled2/wiki.txt");
//    if (!wiki.is_open()) {
//        std::cout << "WIKI ERROR!!" << std::endl;
//    }
//    std::ofstream out("clearText.txt");
//    if (!out.is_open()) {
//        std::cout << "OUTPUT OPEN ERROR!!" << std::endl;
//    }
////    char dot;
//    std::string txx;
////    std::string xf;
//    while (!wiki.eof()) {
//        getline(wiki, txx);
//        FormatArticle(txx);
//        out << txx << std::endl;
//    }
//
//
//    return 0;
//}
