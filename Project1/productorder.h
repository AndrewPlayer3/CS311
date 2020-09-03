/* 
 * Andrew Player
 * Project 1
 * CS311
 * 08/31/2020
*/

#pragma once

#include <iostream>
#include <sstream>

class ProductOrder {

private:

    std::string _productName;
    std::size_t _itemsOrdered;

public:

    //Constructors
    ProductOrder();
    ProductOrder(const ProductOrder& Product);
    ProductOrder(const ProductOrder&& Product);
    ProductOrder(const std::string& name, const int& number);
    ~ProductOrder();

    //Members
    std::string getName() const;
    int getNumber() const;
    void setName(const std::string& name);
    void setNumber(const int& number);
    bool empty() const;
    std::string toString() const;
    
    //Overloads
    ProductOrder& operator=(const ProductOrder& Product);
    ProductOrder& operator=(const ProductOrder&& Product);
    bool operator==(const ProductOrder& Product) const;
    bool operator!=(const ProductOrder& Product) const;
    ProductOrder& operator++();
    ProductOrder operator++(int);
    ProductOrder& operator--();
    ProductOrder operator--(int);
    friend std::ostream& operator<<(std::ostringstream& output, const ProductOrder& Product);

};
