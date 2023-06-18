#ifndef NEWNOTEMESSAGE_H
#define NEWNOTEMESSAGE_H
#include "Message.h"

class NewNoteMessage : public Message {
public:
    QString toString();
    NewNoteMessage(QDate date, int sender, QByteArray profile);
};

#endif
