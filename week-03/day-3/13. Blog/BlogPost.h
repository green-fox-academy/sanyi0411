//
// Created by sando on 2019. 04. 18..
//

#ifndef INC_13__BLOG_BLOGPOST_H
#define INC_13__BLOG_BLOGPOST_H

#include <iostream>

class BlogPost {
public:
    BlogPost (std::string authorName, std::string title, std::string text, std::string publicationDate);

    void setAuthorName(std::string authorName);
    void setTitle(std::string title);
    void setText(std::string text);
    void setPublicationDate(std::string publicationDate);

    std::string getAuthorName();
    std::string getTitle();
    std::string getText();
    std::string getPublicationDate();

private:
    std::string _authorName;
    std::string _title;
    std::string _text;
    std::string _publicationDate;

};


#endif //INC_13__BLOG_BLOGPOST_H
