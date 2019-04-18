//
// Created by sando on 2019. 04. 18..
//

#include "BlogPost.h"

BlogPost::BlogPost (std::string authorName, std::string title, std::string text, std::string publicationDate)
{
_authorName = authorName;
_title = title;
_text = text;
_publicationDate = publicationDate;

}

void BlogPost::setAuthorName(std::string authorName)
{
    _authorName = authorName;
}

void BlogPost::setTitle(std::string title)
{
    _title = title;
}

void BlogPost::setText(std::string text)
{
    _text = text;
}

void BlogPost::setPublicationDate(std::string publicationDate)
{
    _publicationDate = publicationDate;
}

std::string BlogPost::getAuthorName()
{
    return _authorName;
}

std::string BlogPost::getTitle()
{
    return _title;
}

std::string BlogPost::getText()
{
    return _text;
}

std::string BlogPost::getPublicationDate()
{
    return _publicationDate;
}