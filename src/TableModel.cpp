#include "tablemodel.hpp"

void TableModel::addObserver(Observer* observer)
{
  observers.push_back(observer);
}

void TableModel::removeObserver(Observer* observer)
{
  observers.remove(observer);
}



