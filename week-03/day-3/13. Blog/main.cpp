#include <iostream>
#include <vector>
#include "Blog.h"

std::vector<BlogPost> initialize () {
    std::vector<BlogPost> blogPost;

    blogPost.push_back(BlogPost("John Doe", "Title1", "This is my text1", "2000.01.01"));
    blogPost.push_back(BlogPost("Matyi", "MS Paint", "a kedvencem", "2019.04.10"));
    blogPost.push_back(BlogPost("Kari", "Hali", "Ke'rsz cukrot?", "2019.04.15"));

    return blogPost;
}

int main()
{
    Blog myBlog (initialize());

    std::cout << "Blog before adding: \n";
    myBlog.print();

    BlogPost samu("Samu", "Holnap nem leszek ", "mert beteg vagyok", "2019.04.17.");
    myBlog.add(samu);
    std::cout << "Blog after adding: \n";
    myBlog.print();

    myBlog.deletePost(0);
    std::cout << "Blog after deleting first post: \n";
    myBlog.print();

    BlogPost samu2("Samu", "Ma nem leszek ", "mert beteg vagyok", "2019.04.18.");
    myBlog.update(myBlog.getSize()-1, samu2);
    std::cout << "Blog after updateing: \n";
    myBlog.print();

    return 0;
}