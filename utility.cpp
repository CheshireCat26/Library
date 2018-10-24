#include "utility.h"

QString splitStrings(std::vector<QString> strs)
{
    QString ret;
    for (int i = 0; i < static_cast<int>(strs.size()); i++)
    {
        ret += strs[static_cast<unsigned int>(i)];
        if (i < static_cast<int>(strs.size()) - 1)
            ret += ", ";
    }

    return ret;
}

std::vector<QString> devideString(QString str)
{
    std::vector<QString> ret;
    QString buff;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ',' && ' ')
            buff += str[i];
        else if (buff.size() != 0)
        {
            ret.push_back(buff);
            buff.clear();
        }
    }

    return ret;
}
