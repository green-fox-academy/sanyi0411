//
// Created by sando on 2019. 04. 18..
//

#include "Blog.h"

Blog::Blog (std::vector<BlogPost> blogPost)
{
    _blogPost = blogPost;
}

int Blog::getSize ()
{
    return _blogPost.size();
}

void Blog::add(BlogPost myPost)
{
    _blogPost.push_back(myPost);
}

void Blog::deletePost(int index)
{
    _blogPost.erase(_blogPost.begin() + index);
}

void Blog::update(int index, BlogPost blogpost)
{
    _blogPost[index].setText(blogpost.getText());
    _blogPost[index].setAuthorName(blogpost.getAuthorName());
    _blogPost[index].setTitle(blogpost.getTitle());
    _blogPost[index].setPublicationDate(blogpost.getPublicationDate());
}

void Blog::print ()
{
    for (int i = 0; i < _blogPost.size(); i++) {
        std::cout << _blogPost[i].getAuthorName() << "\n\t" << _blogPost[i].getTitle() << "\n\t" <<
            _blogPost[i].getText() << "\n\t" << _blogPost[i].getPublicationDate() << "\n\n";
    }
}