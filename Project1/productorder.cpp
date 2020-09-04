/* 
 * Andrew Player
 * Project 1
 * CS311
 * 08/31/2020
*/

#include "productorder.h"

//Default Constructor
ProductOrder::ProductOrder() {
    _productName  = "UNSPECIFIED";
    _itemsOrdered = 0;
}

//Value Constructor
ProductOrder::ProductOrder(const std::string& name, const int& number) {
    _productName  = name;
    _itemsOrdered = number;
}

//Copy Constructor
ProductOrder::ProductOrder(const ProductOrder& Product) {
    _productName  = Product._productName;
    _itemsOrdered = Product._itemsOrdered;
}

//Move Constructor
ProductOrder::ProductOrder(ProductOrder&& Product) {
    _productName  = Product._productName; 
    _itemsOrdered = Product._itemsOrdered;
    Product._productName  = "UNSPECIFIED";
    Product._itemsOrdered = 0;
}

//Destructor
ProductOrder::~ProductOrder() {
    _productName  = "";
    _itemsOrdered = 0;
}

//Return product name
std::string ProductOrder::getName() const {
    return _productName;
}

//Return number of items in order
int ProductOrder::getNumber() const {
    return int(_itemsOrdered);
}

//Set the products name
void ProductOrder::setName(const std::string& name) {
    _productName = name;
}

//Set the number of items ordered
void ProductOrder::setNumber(const int& number) {
    _itemsOrdered = number;
}

//Check if the Product Order has items
bool ProductOrder::empty() const {
    if(_itemsOrdered == 0) return true;
    return false;
}

//Return a string containing the products name and item count
std::string ProductOrder::toString() const {
    std::ostringstream itemsOrderedString;
    itemsOrderedString << _itemsOrdered;
    return std::string(_productName + " " + "(" + itemsOrderedString.str() + ")");
}

//Copy Assignment Operator Overload
ProductOrder& ProductOrder::operator=(const ProductOrder& Product) {
    _productName  = Product._productName;
    _itemsOrdered = Product._itemsOrdered;
    return *this;
}

//Move Assignment Operator Overload
ProductOrder& ProductOrder::operator=(const ProductOrder&& Product) {
    _productName  = Product._productName;
    _itemsOrdered = Product._itemsOrdered;
    return *this;
}

//Equality Operator Overload
bool ProductOrder::operator==(const ProductOrder& Product) const {
    if(_itemsOrdered != Product._itemsOrdered
    || _productName  != Product._productName) return false;
    return true;
}

//Inequality Operator Overload
bool ProductOrder::operator!=(const ProductOrder& Product) const {
    if(_itemsOrdered != Product._itemsOrdered
    || _productName  != Product._productName) return true;
    return false;
}

//Pre-Increment Operator Overload
ProductOrder& ProductOrder::operator++() {
    ++_itemsOrdered;
    return *this;
}

//Post-Increment Operator Overload
ProductOrder ProductOrder::operator++(int) {
    ProductOrder temp = *this;
    _itemsOrdered++;
    return temp;
}

//Pre-Decrement Operator Overload
ProductOrder& ProductOrder::operator--() {
    if(_itemsOrdered > 0) --_itemsOrdered;
    return *this;
}

//Post-Decrement Operator Overload
ProductOrder ProductOrder::operator--(int) {
    if(_itemsOrdered < 1) return *this;
    ProductOrder temp = *this;
    _itemsOrdered--;
    return temp;
}

//Stream Insertion Operator Overload
std::ostream& operator<<(std::ostringstream& output, const ProductOrder& Product) {
    output << Product.toString();
    return output;
}