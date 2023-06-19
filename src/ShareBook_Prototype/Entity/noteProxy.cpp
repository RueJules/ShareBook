#include "noteProxy.h"

NoteProxy::NoteProxy(int id):NoteInterface{id},m_note{nullptr}
{

}

NoteProxy::NoteProxy(int id, std::unique_ptr<Note>note):NoteInterface{id},m_note{std::move(note)}
{

}
