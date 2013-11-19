#ifndef QTEMPLATETHREAD_H
#define QTEMPLATETHREAD_H
#include <QObject>
#include <QThread>

template <class T>
class QTemplateThread : public QThread
{
public:
    inline explicit  QTemplateThread(){this->isStart = false;}
    inline T* getPtr() {return this->ptr;}
    inline bool isReady() {return this->isStart;}

protected:
    bool isStart;
    T* ptr;
    inline void run()
    {
        this->ptr = new T;
        this->isStart = true;
        this->exec();
    }
};

#endif // QTEMPLATETHREAD_H
