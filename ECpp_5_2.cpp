#include <iostream>
#include "LibMat.h"

using namespace std;

void print(const LibMat&);

int main()
{
//    cout << "\n" << "Creating a LibMat object to print() \n";
//    LibMat libmat;
//    print(libmat);

//    cout << "\n" << "Creating a Book object to print() \n";
//    Book b("The Castle", "Frank Kafka");
//    print(b);

    cout << "\n" << "Creating a AudioBook object to print() \n";
    AudioBook ab("Man Without Qualities","Robert Musil", "Kenneth Meyer");
    print(ab);
    return 0;
}

void print(const LibMat& mat)
{
    cout << "in global print(): about to print mat.print()\n";

    mat.print();
}
