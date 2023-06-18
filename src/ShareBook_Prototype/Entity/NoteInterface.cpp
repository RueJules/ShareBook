#include "NoteInterface.h"

NoteInterface:: NoteInterface(int id):m_id(id)
{

}

int NoteInterface::get_Id() {
    return m_id;
}
