#ifndef NOTEINTERFACE_H
#define NOTEINTERFACE_H
#include <QString>

class NoteInterface {

private:
   int m_id;

public:
    NoteInterface(int id);
    int get_Id();
};

#endif
