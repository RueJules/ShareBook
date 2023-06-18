/*Auther:Huangyihong
Date:2023.6.17*/

#ifndef MESSAGEINTERFACE_H
#define MESSAGEINTERFACE_H

class MessageInterface {
public:
    MessageInterface(int new_id);
    int get_id();

private:
    int m_id;
};

#endif
