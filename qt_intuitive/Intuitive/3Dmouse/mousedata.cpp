/*  Class:          MouseData "mousedata.cpp"
 *  Description:    Details of class implementation. See "mousedata.h"
 */

/* Includes */
#include "3Dmouse/mousedata.h"
#include <QString>
#include <String>
#include <QDebug>

/*  Function:    Constructor function
 *  Description: Creating MouseData instance and transforms raw data into its fields.
 */
MouseData::MouseData(QString rawData)
{
    convertString(rawData);
}


/*  Function:    Default Constructor function
 *  Description: Creating MouseData instance and sets all fields to zero.
 */
MouseData::MouseData()
{
    this->data_type = 0;
    for (int i=0;i<6;i++)
        this->values[i] = 0;
    this->left_button_state = 0;
    this->right_button_state = 0;
}


/*  Function:    From Raw Data Convertion
 *  Description: Unpacking raw string data into this instance fields.
 */
void MouseData::convertString(QString rawData)
{
    std::string stri(rawData.toStdString());
    std::string s_t(stri.substr(0,1));
    this->data_type = std::stoi(s_t);
    if (data_type == 1)
    {
    stri.erase(0,1);
    for (int i=0;i<6;i++)
        {
           size_t t = stri.find('&');
            std::string temp = stri.substr(0,t);
            this->values[i] = std::stoi(temp);
            stri.erase(0,t+1);
        }
    }else if (data_type == 0) {
     for (int i=0;i<6;i++)
        this->values[i]=0;
    }else if (data_type == 2){                  //L Button Pressed
        this->left_button_state = 1;
        //emit proper signal
    }else if (data_type == 3){                  //L Button Released
        this->left_button_state = 0;
        //emit proper signal
    }else if (data_type == 4){                  //R Button Pressed
        this->right_button_state = 1;
        //emit proper signal
    }else if (data_type == 5){                  //R Button Released
        this->right_button_state = 0;
        //emit proper signal
    }else{
       ; //handle_error
    }

}

void MouseData::setData(QString rawData)
{
    convertString(rawData);
}

int MouseData::getTX() const
{
    return this->values[0];
}

int MouseData::getTY() const
{
    return this->values[1];
}

int MouseData::getTZ() const
{
    return this->values[2];
}

int MouseData::getRX() const
{
    return this->values[3];
}

int MouseData::getRY() const
{
    return this->values[4];
}

int MouseData::getRZ() const
{
    return this->values[5];
}

int MouseData::getDT() const
{
    return this->data_type;
}

int MouseData::getLBS() const
{
    return this->left_button_state;
}

int MouseData::getRBS() const
{
    return this->right_button_state;
}

void MouseData::setData(int new_data[6])
{
    for (int i=0;i<6;i++)
        values[i] = new_data[i];
}
