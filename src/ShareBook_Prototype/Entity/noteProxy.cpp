#include "noteProxy.h"

NoteProxy::NoteProxy(int id):NoteInterface{id},m_note{nullptr}
{

}

NoteProxy::NoteProxy(int id, std::unique_ptr<Note>&&note):NoteInterface{id},m_note{std::move(note)}
{

}
void NoteProxy::addMaterial(int materialId, MaterialProxy &&material)
{
    m_note->addMaterial(materialId,std::move(material));
}
