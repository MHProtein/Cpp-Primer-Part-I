#pragma once
 class GradesClassify
{
public:
    void GradesClassification();
     ~GradesClassify()
     {
         if (this != nullptr)
             delete this;
     }
};

