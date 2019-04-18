//
// Created by sando on 2019. 04. 18..
//

#ifndef INC_13__BLOG_BLOG_H
#define INC_13__BLOG_BLOG_H

#include <iostream>
#include <vector>
#include "BlogPost.h"


class Blog {
public:
    Blog (std::vector<BlogPost> blogPost);

    void add(BlogPost myPost);

    void deletePost(int index);

    void update(int index, BlogPost blogpost);

    void print();

    int getSize();

private:
    std::vector<BlogPost> _blogPost;

};


#endif //INC_13__BLOG_BLOG_H
